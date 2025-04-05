#include "main.h"

/**
 * print_error - Prints error to stderr and exits with given code
 * @code: Exit code
 * @msg: Error message format
 * @arg: Argument (file name)
 */
void print_error(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	dprintf(STDERR_FILENO, "\n");
	exit(code);
}

/**
 * close_fd - Closes a file descriptor
 * @fd: File descriptor to close
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
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file %s", argv[1]);

	bytes_read = read(fd_from, buffer, 1024);
	if (bytes_read == -1)
	{
		close_fd(fd_from);
		print_error(98, "Error: Can't read from file %s", argv[1]);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		print_error(99, "Error: Can't write to %s", argv[2]);
	}

	while (bytes_read > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			print_error(99, "Error: Can't write to %s", argv[2]);
		}

		bytes_read = read(fd_from, buffer, 1024);
		if (bytes_read == -1)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			print_error(98, "Error: Can't read from file %s", argv[1]);
		}
	}

	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}
