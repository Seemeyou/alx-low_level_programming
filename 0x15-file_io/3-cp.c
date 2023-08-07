#include "main.h"

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, or an error code on failure.
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

/**
 * copy_file - Copies the content of a file to another file.
 * @file_from: Source file.
 * @file_to: Destination file.
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_read(file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_write(file_to);
	}

	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read || bytes_written == -1)
		{
			close(fd_from);
			close(fd_to);
			error_write(file_to);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		error_read(file_from);
	}

	close_files(fd_from, fd_to);
}

/**
 * error_read - Handles read error.
 * @file: File name.
 */
void error_read(const char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * error_write - Handles write error.
 * @file: File name.
 */
void error_write(const char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * close_files - Closes file descriptors.
 * @fd_from: Source file descriptor.
 * @fd_to: Destination file descriptor.
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}
