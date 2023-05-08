#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters it could read and print
 *         0 if the file cannot be opened or read, or if write fails
 **/

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *pt;
	ssize_t fd, w, t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	pt = malloc(sizeof(char) * letters);
	t = read(fd, pt, letters);
	w = write(STDOUT_FILENO, pt, t);

	free(pt);
	close(fd);
	return (w);

}
