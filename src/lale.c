#include "../include/bin_formats.h"

#include <elf.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#elif defined __unix__
#define TODO	"Linux stuff"
#elif defined __APPLE__
#define TODO	"Mac stuff"
#endif

// move these to header
exec_fmt_t detect_format(uint8_t * magic, size_t len);
void parse_elf_ident(obj_fmt_t * object, FILE * target);

void parse_elf_ident(obj_fmt_t * object, FILE * target)
{
    object->format = ELF;
    object->format_str = "ELF";

    // cf. man 5 elf
    unsigned char ident[EI_NIDENT] = { 0 };
    rewind(target);
    if (EI_NIDENT != fread(ident, sizeof(char), EI_NIDENT, target))
    {
        perror("fread");
        return;
    } 

    switch (ident[EI_CLASS])
    {
        case ELFCLASS32:
            object->arch_bits = 32;
            break;
        case ELFCLASS64:
            object->arch_bits = 64;
            break;
        default:
            // something is wrong
            object->arch_bits = -1;
    }

    switch(ident[EI_DATA])
    {
        case ELFDATA2LSB:
            object->endian = 'L';
            break;
        case ELFDATA2MSB:
            object->endian = 'B';
            break;
        default:
            // something is wrong
            object->endian = '?';
    }
}

exec_fmt_t detect_format(uint8_t * magic, size_t len)
{
    // TODO: add add'l formats
    obj_fmt_t object =
    {
        .format = UNKNOWN,
        .cpu = OTHER,
        .arch_bits = 0,
        .format_str = "UNKNOWN",
        .cpu_str = "OTHER"
    };

    if (0 == strncmp(magic, ELF_MAGIC, sizeof(uint32_t)))
    {
        return ELF;
    }

    return UNKNOWN;
}

int main(int argc, char ** argv)
{
	FILE * target = NULL;
	uint8_t * header = NULL;

	if (argc < 2)
	{
		printf("Usage: %s <executable>\n", argv[0]);
		return EXIT_FAILURE;
	}

	target = fopen(argv[1], "r");

	if (NULL != target)
	{
		printf("[+] Opened %s.\n", argv[1]);
	}
	else
	{
		printf("[-] Failed to open %s.\n", argv[1]);
		return EXIT_FAILURE;
	}

    header = calloc(FORMAT_TRIAGE_LEN, sizeof(uint8_t);
    // check for error

    if (FORMAT_TRIAGE_LEN != fread(header, sizeof(uint8_t), FORMAT_TRIAGE_LEN, target)
    {
        perror("fread");
        goto cleanup;
    }
    

    /*
    uint32_t magic = 0;
    if (sizeof(uint32_t) != fread(&magic, sizeof(uint8_t), sizeof(uint32_t), target))
    {
       perror("fread");
       return EXIT_FAILURE;
    }

    exec_fmt_t format = detect_format((uint8_t *)&magic, sizeof(uint32_t));
    obj_fmt_t object = { 0 };
    switch (format)
    {
        case ELF:
            parse_elf_ident(&object, target);
            break;
        case UNKNOWN:
        case MACHO:
        case PE:
        default:
            printf("[!] Haven't implemented support for non-ELFs\n");
            break;
    }

    printf("[!] %s is a %c.Endian %u-bit %s (%d) object for %s (%d)\n",
         argv[1], 
         object.endian,
         object.arch_bits, 
         object.format_str,
         object.format,
         object.cpu_str,
         object.cpu);
    */

cleanup:
	fclose(target);

    free(header);

	return EXIT_SUCCESS;
}
