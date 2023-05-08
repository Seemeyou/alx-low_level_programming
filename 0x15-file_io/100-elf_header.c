#include "main.h"

/**
 * read_elf_header - reads the ELF header of a file
 * @file: file descriptor of the file to read
 * @header: pointer to where the ELF header should be stored
 *
 * Return: 0 on success, 1 on failure
 */
int read_elf_header(int file, Elf64_Ehdr *header)
{
	ssize_t num_read;

	if (lseek(file, (off_t)0, SEEK_SET) == (off_t)-1)
		return (1);

	num_read = read(file, header, sizeof(*header));
	if (num_read == (ssize_t)-1 || num_read != sizeof(*header) ||
	    header->e_ident[EI_MAG0] != ELFMAG0 ||
	    header->e_ident[EI_MAG1] != ELFMAG1 ||
	    header->e_ident[EI_MAG2] != ELFMAG2 ||
	    header->e_ident[EI_MAG3] != ELFMAG3)
		return (1);

	return (0);
}

/**
 * print_magic - prints the magic field of an ELF header
 * @header: the ELF header to print
 */
void print_magic(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header->e_ident[i],
		       i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * print_class - prints the class field of an ELF header
 * @header: the ELF header to print
 */
void print_class(Elf64_Ehdr *header)
{
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
		break;
	}
}

/**
 * print_data - prints the data field of an ELF header
 * @header: the ELF header to print
 */
void print_data(Elf64_Ehdr *header)
{
	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
		break;
	}
}

/**
 * print_version - prints the version field of an ELF header
 * @header: the ELF header to print
 */
void print_version(Elf64_Ehdr *header)
{
	printf("  Version:                           %d",
	       header->e_ident[EI_VERSION] == EV_NONE ? 0 :
	       header->e_ident[EI_VERSION] == EV_CURRENT ? 1 : 2);
	printf(header->e_ident[EI_VERSION] == EV_NONE ? " (invalid)\n" :
	       header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)\n" :
	       " (unknown)\n");
}
