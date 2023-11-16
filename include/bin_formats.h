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

#define PE_OFFSET           64  // end DOS Stub, begin PE header

#define DEFAULT_MAGIC_LEN   4
#define SHE_MAGIC_LEN       5
#define DOS_MAGIC_LEN       2

/* See https://code.google.com/archive/p/corkami/wikis/PE.wiki */
#define PE_X86_MACHINE      "\x4C\x01"  // both adjusted for LE
#define PE_X64_MACHINE      "\x64\x86"
#define PE_MACHINE_LEN      2

#define FORMAT_TRIAGE_LEN   84  // enough bytes for any executable header

static const char * exec_name[] = { "unknown", "DOS", "ELF", "MAC", "PE", "SHE" };

typedef enum
{
    UNKNOWN = 0,
    DOS,
    ELF,
    MACHO,
    PE,
    SHE
} exec_fmt_t;

static const char * cpu_name[] = { "unknown", "ARM", "MIPS", "PPC", "x86"};

typedef enum
{
    OTHER = 0,
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
