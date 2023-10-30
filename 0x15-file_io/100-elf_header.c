/*
 * File: 100-elf_header.c
 * Auth: Brennan D Baraban
 */

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void chk_elf(unsigned char *e);
void prt_magic(unsigned char *e);
void prt_class(unsigned char *e);
void prt_data(unsigned char *e);
void prt_version(unsigned char *e);
void prt_abi(unsigned char *e);
void prt_osabi(unsigned char *e);
void prt_type(unsigned int e_type, unsigned char *e);
void prt_entry(unsigned long int e_entry, unsigned char *e);
void cl_elf(int elf);

/**
 * chk_elf - Program checks if a file is an ELF file.
 * @e: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void chk_elf(unsigned char *e)
{
	int pos;

	for (pos = 0; pos < 4; pos++)
	{
		if (e[pos] != 127 &&
		    e[pos] != 'E' &&
		    e[pos] != 'L' &&
		    e[pos] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * prt_magic - The program Prints the magic numbers of an ELF header.
 * @e: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void prt_magic(unsigned char *e)
{
	int pos;

	printf("  Magic:   ");

	for (pos = 0; pos < EI_NIDENT; pos++)
	{
		printf("%02x", e[pos]);

		if (pos == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * prt_class -  function prints the class of an ELF header.
 * @e: A pointer to an array containing the ELF class.
 */
void prt_class(unsigned char *e)
{
	printf("  Class:                             ");

	switch (e[EI_CLASS])
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
		printf("<unknown: %x>\n", e[EI_CLASS]);
	}
}

/**
 * prt_data -  function prints the data of an ELF header.
 * @e: A pointer to an array containing the ELF class.
 */
void prt_data(unsigned char *e)
{
	printf("  Data:                              ");

	switch (e[EI_DATA])
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
		printf("<unknown: %x>\n", e[EI_CLASS]);
	}
}

/**
 * prt_version - function prints the version of an ELF header.
 * @e: A pointer to an array containing the ELF version.
 */
void prt_version(unsigned char *e)
{
	printf("  Version:                           %d",
	       e[EI_VERSION]);

	switch (e[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * prt_osabi - function prints the OS/ABI of an ELF header.
 * @e: A pointer to an array containing the ELF version.
 */
void prt_osabi(unsigned char *e)
{
	printf("  OS/ABI:                            ");

	switch (e[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e[EI_OSABI]);
	}
}

/**
 * prt_abi -  function prints the ABI version of an ELF header.
 * @e: A pointer to an array containing the ELF ABI version.
 */
void prt_abi(unsigned char *e)
{
	printf("  ABI Version:                       %d\n",
	       e[EI_ABIVERSION]);
}

/**
 * prt_type - function prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e: A pointer to an array containing the ELF class.
 */
void prt_type(unsigned int e_type, unsigned char *e)
{
	if (e[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e: A pointer to an array containing the ELF class.
 */
void prt_entry(unsigned long int e_entry, unsigned char *e)
{
	printf("  Entry point address:               ");

	if (e[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * cl_elf - Function Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void cl_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - This program displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 if success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, x;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		cl_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	x = read(o, header, sizeof(Elf64_Ehdr));
	if (x == -1)
	{
		free(header);
		cl_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	chk_elf(header->e);
	printf("ELF Header:\n");
	prt_magic(header->e);
	prt_class(header->e);
	prt_data(header->e);
	prt_version(header->e);
	prt_osabi(header->e);
	prt_abi(header->e);
	prt_type(header->e_type, header->e);
	prt_entry(header->e_entry, header->e);

	free(header);
	cl_elf(o);
	return (0);
}
