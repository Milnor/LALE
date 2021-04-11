#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#elif defined __unix__
#define TODO	"Linux stuff"
#elif defined __APPLE__
#define TODO	"Mac stuff"
#endif

int main(int argc, char ** argv)
{
	FILE * target;
	
	if (argc < 2)
	{
		printf("Usage: %s <executable>\n", argv[0]);
		return -1;
	}

	target = fopen(argv[1], "r");

	if (NULL != target)
	{
		printf("[+] Opened %s.\n", argv[1]);
	}
	else
	{
		printf("[-] Failed to open %s.\n", argv[1]);
		return -1;
	}
	
	fclose(target);

	return 0;
}