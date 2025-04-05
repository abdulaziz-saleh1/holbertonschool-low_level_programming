#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void print_error(int code, const char *msg, const char *arg);
void close_fd(int fd);
void copy_file(const char *file_from, const char *file_to);
void close_files(int fd_from, int fd_to);

#endif
