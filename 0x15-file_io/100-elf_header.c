#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
/**
* check_elf - Checks if file is ELF file but what does that mean
* @e_ident: A pointer to too much similarity.
* Description: not my business
*/
void check_elf(unsigned char *e_ident)
{
int index;
for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
e_ident[index] != 'E' &&
e_ident[index] != 'L' &&
e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}
/**
* print_magic - get out the way
* @e_ident: A pointer brrrrrrrrrrrrrrrrrrr
* Description: no more creativity brr.
*/
void print_magic(unsigned char *e_ident)
{
int index;
printf(" Magic: ");
for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", e_ident[index]);
if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}
/**
* print_class - brrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr.
* @e_ident: brrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
*/
void print_class(unsigned char *e_ident)
{
printf(" Class: ");
switch (e_ident[EI_CLASS])
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
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}
/**
* print_data - brrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
* @e_ident: brrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
*/
void print_data(unsigned char *e_ident)
{
printf(" Data: ");
switch (e_ident[EI_DATA])
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
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}
/**
* print_version - brrrrrrrrrrrrrrrrrrrrrrrr
* @e_ident: grrrrrrrrrrrrrrrrrrrrrrrrrr
*/
void print_version(unsigned char *e_ident)
{
printf(" Version: %d",
e_ident[EI_VERSION]);
switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}
check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);
print_class(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);
free(header);
close_elf(o);
return (0);
}
