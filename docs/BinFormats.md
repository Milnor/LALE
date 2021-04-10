# Binary Formats

`Note: This first pass is just my notes on Xeno's slides,
not my own original work`

## Executable Formats
* PE - Portable Executable
	- Windows
	- derived from UNIX System V COFF (Common Object File Format)
* ELF - Executable and Linkable Format
	- Linux
* Mach-o - Mach Object
	- Mac OS X

## Target Binary Formats
* Executable
	- stands alone or requires external libraries
	- no suffix on Linux, `.exe` on Windows
* Shared Library
	- needs to be loaded by some other program
	- Dynamic Linked Library `.dll` on Windows
	- Shared Object `.so` on Linux
* Static Library
	- collection of object files with a header to describe them
	- `.lib` on Windows
	- `.a` on Linux

## Where are these defined?
* WINNT.h for Windows

`TODO: add Mac to previous lists`

## PE

### Common Windows Extensions
* `.exe` executable
* `.dll` dynamic link library
* `.sys`/`.drv` system file (kernel driver)
* `.ocx` ActiveX control
* `.cpl` control panel
* `.scr` screensaver
* `.lib` static library (not DOS Header, PE Header)
	- TODO: did he mean just PE and not DOS?

### MS-DOS Header (Simplified)
`typedef struct _IMAGE_DOS_HEADER {
	WORD e_magic;	// Magic Number
	...				// don't care
	LONG e_lfanew;	// address of new exe header
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;`
* **e\_magic** is ASCII 'MZ' for Mark Zbikoski
* **e\_lfanew** is file offset to PE header

### NT/PE Header
* resume notes here...


## References
* Kovah, Xeno. "Life of Binaries" https://www.opensecuritytraining.info/LifeOfBinaries.html
