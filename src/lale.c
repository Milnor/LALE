#include "../include/bin_formats.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#elif defined __unix__
#define TODO	"Linux stuff"
#elif defined __APPLE__
#define TODO	"Mac stuff"
#endif

// move these to header
int detect_format(uint8_t * magic, size_t len);

int detect_format(uint8_t * magic, size_t len)
{
    // TODO: implement me
    return ELF;
}

int main(int argc, char ** argv)
{
	FILE * target;
	
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

    uint32_t magic = 0;
    if (sizeof(uint32_t) != fread(&magic, sizeof(uint8_t), sizeof(uint32_t), target))
    {
       perror("fread");
    }
    else
    {
        printf("[!] File format = %d\n", detect_format((uint8_t *)&magic, sizeof(uint32_t)));
    }

	fclose(target);

	return EXIT_SUCCESS;
}
