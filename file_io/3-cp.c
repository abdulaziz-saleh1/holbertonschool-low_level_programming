#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_error - Prints error message to STDERR and exits.
 * @exit_code: Code to exit with.
 * @format: Error message format.
 * @arg: Argument for format.
 */
void print_error(int exit_code, const char *format, const char *arg)
{
	dprintf(STDERR_FILENO, format, arg);
	dprintf(STDERR_FILENO, "\n");
	exit(exit_code);
}

/**
 * close_fd - Closes a file descriptor and exits if it fails.
 * @fd: The file descriptor to close.
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copy the content of one file to another.
 * @argc: Argument count.
 * @argv: Argument values.
 * Return: 0 on success, exits with code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file %s", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		print_error(99, "Error: Can't write to %s", argv[2]);
	}

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			print_error(99, "Error: Can't write to %s", argv[2]);
		}
	}
	if (r == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		print_error(98, "Error: Can't read from file %s", argv[1]);
	}

	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}
