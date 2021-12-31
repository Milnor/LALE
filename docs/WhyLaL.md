# Notes on Levin [Chapter 1](https://web.archive.org/web/20120603100717/http://www.iecc.com/linker/linker01.html)

## What do linkers and loaders do?
* Bind more abstract names to more concrete names
    - e.g. abstract `getline` bound to concrete "location 612 bytes from beginning of executable code"

## Linking vs. loading
* Program loading (loader)
    - copy program from disk to RAM
* Relocation (either linker or loader)
    - load object code at non-overlapping addresses
* Symbol resolution (linker)
    - patch caller's object code to refer to location
        * e.g. make `call sqrt` in main refer to location in library

Note: Linkers and loaders are nearly unique in that they patch object code; debuggers do to, but that is a rare feature.
