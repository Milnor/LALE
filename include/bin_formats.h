#ifndef BIN_FORMATS_H
#define BIN_FORMATS_H

#define DOS_MAGIC       0x4D5A      // "MZ"
#define ELF_MAGIC       0x7F454C46  // x7F ELF
#define MACHO_MAGIC     0xFEEDFACE
#define PE_MAGIC        0x50450000  // "PE\0\0"

typedef enum
{
    ELF,
    MACHO,
    PE
} exec_fmt_t;

#endif
