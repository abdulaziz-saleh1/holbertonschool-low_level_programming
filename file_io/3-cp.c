#include "main.h"

/**
 * print_error - Prints error to STDERR and exits with code.
 * @code: Exit code.
 * @msg: Format string.
 * @arg: Argument.
 */
void print_error(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	dprintf(STDERR_FILENO, "\n");
	exit(code);
}

/**
 * close_fd - Closes a file descriptor with error handling.
 * @fd: File descriptor to close.
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
 * copy_file - Copies the content of one file to another.
 * @file_from: Source file name.
 * @file_to: Destination file name.
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file %s", file_from);

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		print_error(99, "Error: Can't write to %s", file_to);
	}

	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			print_error(99, "Error: Can't write to %s", file_to);
		}
	}

	if (bytes_read == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		print_error(98, "Error: Can't read from file %s", file_from);
	}

	close_fd(fd_from);
	close_fd(fd_to);
}

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Argument values.
 * Return: 0 if successful.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to", "");

	copy_file(argv[1], argv[2]);

	return (0);
}
