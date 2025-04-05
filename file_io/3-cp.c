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
 * open_files - Opens source and destination files.
 * @file_from: Source file path.
 * @file_to: Destination file path.
 * @fd_from: Pointer to source file descriptor.
 * @fd_to: Pointer to destination file descriptor.
 */
void open_files(const char *file_from, const char *file_to,
		 int *fd_from, int *fd_to)
{
	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
		print_error(98, "Error: Can't read from file %s", file_from);

	*fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		close_fd(*fd_from);
		print_error(99, "Error: Can't write to %s", file_to);
	}
}

/**
 * transfer_data - Reads from source and writes to destination.
 * @fd_from: Source file descriptor.
 * @fd_to: Destination file descriptor.
 * @file_from: Source file path.
 * @file_to: Destination file path.
 */
void transfer_data(int fd_from, int fd_to,
		     const char *file_from, const char *file_to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

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
}

/**
 * copy_file_content - Copies content from one file to another.
 * @file_from: Source file path.
 * @file_to: Destination file path.
 */
void copy_file_content(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;

	open_files(file_from, file_to, &fd_from, &fd_to);
	transfer_data(fd_from, fd_to, file_from, file_to);
	close_fd(fd_from);
	close_fd(fd_to);
}

/**
 * main - Entry point. Handles arguments.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, error otherwise.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to", "");

	copy_file_content(argv[1], argv[2]);
	return (0);
}
