#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * print_error_and_exit - Prints an error message 
 * and exits with a given code.
 * @exit_code: The exit code to use.
 * @message: The error message format.
 * @arg: The argument for the error message.
 */
void print_error_and_exit(int exit_code, const char *message, const char *arg)
{
dprintf(STDERR_FILENO, message, arg);
dprintf(STDERR_FILENO, "\n");
exit(exit_code);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 *
 * Return: 0 on success, exits with respective error codes on failure.
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

if (argc != 3)
print_error_and_exit(97, "Usage: cp file_from file_to", "");

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
print_error_and_exit(98, "Error: Can't read from file %s", argv[1]);

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
close(fd_from);
print_error_and_exit(99, "Error: Can't write to %s", argv[2]);
}

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written != bytes_read)
{
close(fd_from);
close(fd_to);
print_error_and_exit(99, "Error: Can't write to %s", argv[2]);
}
}

if (bytes_read == -1)
{
close(fd_from);
close(fd_to);
print_error_and_exit(98, "Error: Can't read from file %s", argv[1]);
}

if (close(fd_from) == -1)
print_error_and_exit(100, "Error: Can't close fd %d", "fd_from");

if (close(fd_to) == -1)
print_error_and_exit(100, "Error: Can't close fd %d", "fd_to");

return (0);
}
