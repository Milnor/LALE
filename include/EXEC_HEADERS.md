# Executable Headers
* `bin_formats.h` has the magic numbers for each

## ELF
* header is 52 (32-bit) or 64 (64-bit) bytes long

## Portable Executable
* DOS MZ Header + DOS Stub `first 64 bytes`
* PE File Header `next 20 bytes`
* 84 bytes should be enough to triage the header of "any" executable

## Mach-O
* TODO: buy a Mac so I can build these
* 32 bytes (32-bit and 64-bit)

## SHE
* my own heuristic executable format that doesn't really exist yet

## References
* Palo Alto Networks, [Custom Application IDs and Signatures](https://docs.paloaltonetworks.com/pan-os/u-v/custom-app-id-and-threat-signatures/custom-application-and-threat-signatures/custom-signature-contexts/string-contexts/pe-file-header)
* Wikipedia, [Executable and Linkable Format](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format)
* Wikipedia, [Mach-O](https://en.wikipedia.org/wiki/Mach-O)
