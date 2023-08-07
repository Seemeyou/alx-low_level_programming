#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void copy_file(const char *file_from, const char *file_to);
void error_read(const char *file);
void error_write(const char *file);
void close_files(int fd_from, int fd_to);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);

#endif
