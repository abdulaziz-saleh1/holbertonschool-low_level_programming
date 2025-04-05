#include "main.h"

/**
 * print_error - Print an error message and exit with code
 * @exit_code: The exit code to use
 * @format: Format of the error message
 * @arg: Argument for the format
 */
void print_error(int exit_code, const char *format, const char *arg)
{
	dprintf(STDERR_FILENO, format, arg);
	dprintf(STDERR_FILENO, "\n");
	exit(exit_code);
}

/**
 * close_fd - Close a file descriptor with error check
 * @fd: The file descriptor to close
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
 * copy_file - Copy contents from one file to another
 * @file_from: Source file
 * @file_to: Destination file
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
 * main - Entry point, check args and call copy_file
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, exits with error code otherwise
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);
	return (0);
}
