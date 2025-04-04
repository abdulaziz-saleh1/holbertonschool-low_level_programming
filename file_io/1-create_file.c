#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * create_file - Creates a file and writes text to it.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
int fd, len = 0, written;

if (filename == NULL)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content)
{
while (text_content[len])
len++;

written = write(fd, text_content, len);
if (written != len)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}
