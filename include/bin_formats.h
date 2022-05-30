#ifndef BIN_FORMATS_H
#define BIN_FORMATS_H

#define DOS_MAGIC       "\x4D\x5A"          // "MZ"
#define ELF_MAGIC       "\x7F\x45\x4C\x46"  // x7F ELF
#define MACHO_MAGIC     "\xFE\xED\xFA\xCE"
#define PE_MAGIC        "\x50\x45\x00\x00"  // "PE\0\0"

typedef enum
{
    UNKNOWN = -1,
    ELF,
    MACHO,
    PE
} exec_fmt_t;

typedef enum
{
    OTHER = -1,
    ARM,
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
