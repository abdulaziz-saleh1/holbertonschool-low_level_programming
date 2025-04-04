#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *create_buffer(char *file)
{
char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
}
return (buffer);
}

void close_file(int fd)
{
int c = close(fd);
if (c == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

int main(int ac, char **av)
{
int fd_from, fd_to, r, w;
char *buffer;

if (ac != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer(av[2]);
fd_from = open(av[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
free(buffer);
exit(98);
}

fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
free(buffer);
close_file(fd_from);
exit(99);
}

while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
w = write(fd_to, buffer, r);
if (w != r)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
free(buffer);
close_file(fd_from);
close_file(fd_to);
exit(99);
}
}

if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
free(buffer);
close_file(fd_from);
close_file(fd_to);
exit(98);
}

free(buffer);
close_file(fd_from);
close_file(fd_to);
return (0);
}
