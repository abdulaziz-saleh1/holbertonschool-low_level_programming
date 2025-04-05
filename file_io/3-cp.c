#include "main.h"

/**
 * print_error - Prints formatted error and exits.
 * @code: Exit code.
 * @msg: Format string.
 * @arg: File name or argument.
 */
void print_error(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	dprintf(STDERR_FILENO, "\n");
	exit(code);
}

/**
 * close_fd - Closes a file descriptor and checks for errors.
 * @fd: File descriptor.
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
 * main - Copies content from one file to another.
 * @argc: Number of arguments.
 * @argv: Arguments.
 * Return: 0 if successful, exits with error codes otherwise.
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

	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
		if (fd_to == -1)
		{
			close_fd(fd_from);
			print_error(99, "Error: Can't write to %s", argv[2]);
		}

		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			print_error(99, "Error: Can't write to %s", argv[2]);
		}

		close_fd(fd_to); 
	}

	if (bytes_read == -1)
	{
		close_fd(fd_from);
		print_error(98, "Error: Can't read from file %s", argv[1]);
	}

	close_fd(fd_from);
	return (0);
}
