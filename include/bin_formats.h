#ifndef BIN_FORMATS_H
#define BIN_FORMATS_H

#define DOS_MAGIC           "\x4D\x5A"              // "MZ"
#define ELF_MAGIC           "\x7F\x45\x4C\x46"      // x7F + "ELF"
#define MACHO_MAGIC_BE32    "\xFE\xED\xFA\xCE"
#define MACHO_MAGIC_LE32    "\xCE\xFA\xED\xFE"
#define MACHO_MAGIC_BE64    "\xFE\xED\xFA\xCF"
#define MACHO_MAGIC_LE64    "\xCF\xFA\xED\xFE"
#define PE_MAGIC            "\x50\x45\x00\x00"      // "PE" + x0000
#define SHE_MAGIC           "\x1a\x1e\x53\x48\x45"  // x1a1e + "SHE"

#define FORMAT_TRIAGE_LEN   84  // enough bytes for any executable header

typedef enum
{
    UNKNOWN = -1,
    ELF,
    MACHO,
    PE,
    SHE
} exec_fmt_t;

typedef enum
{
    OTHER = -1,
    ARM,
    MIPS,
    PPC,
    X86
} cpu_arch_t;

/* Storing the string pointers is inefficient, but ergonomic */
typedef struct
{
    exec_fmt_t format;
    cpu_arch_t cpu;
    char arch_bits;
    char * format_str;
    char * cpu_str;
    char endian;
} obj_fmt_t;

#endif
