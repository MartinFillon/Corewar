/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#ifndef ASM_H_
    #define ASM_H_
    #include <stdint.h>
    #include <stdio.h>
    #include "my_str.h"
    #include "corewar/op.h"
    #include "asm/body.h"
    #include "asm/labels.h"
    #include "asm/error.h"
    #define UNUSED __attribute__((unused))

    #define ERROR 84
    #define SUCCESS 0

    #define REG "01"
    #define DIRECT "10"
    #define INDIRECT "11"

typedef struct op_name_s {
    int id;
    const int params;
    const uint8_t hex;
    const char *name;
    const int *index;
    size_t size;
    int (*check_inst)(size_t, vec_str_t *);
} op_name_t;


typedef struct asm_s {
    FILE *file;
    char const *filepath;
    header_t *header;
    vec_champ_t *champ;
    vec_label_t *labels;
    str_t *buffer;
} asm_t;

enum {
    LIVE,
    LLDI,
    LFORK,
    LLD,
    LDI,
    LD,
    STI,
    ST,
    ADD,
    SUB,
    AND,
    XOR,
    OR,
    ZJMP,
    FORK,
    AFF,
};

enum {
    UNDEFINED,
    REGISTER,
    INDEX,
    REGEX,
};

static const op_name_t OP_NAME[] = {
    {
        .id = LIVE,
        .params = 1,
        .hex = 0x01,
        .name = "live",
        .index = (int[]) {UNDEFINED},
        .size = DIR_SIZE,
        .check_inst = &check_live
    },
    {
        .id = LLDI,
        .params = 3,
        .hex = 0x0e,
        .name = "lldi",
        .index = (int[]) {REGEX,  REGEX, REGISTER},
        .size = IND_SIZE,
        .check_inst = &check_load_further
    },
    {
        .id = LFORK,
        .params = 1,
        .hex = 0x0f,
        .name = "lfork",
        .index = (int[]) {INDEX},
        .size = IND_SIZE,
        .check_inst = &check_fork
    },
    {
        .id = LLD,
        .params = 2,
        .hex = 0x0d,
        .name = "lld",
        .index = (int[]) {UNDEFINED, REGISTER},
        .size = DIR_SIZE,
        .check_inst = &check_load_base
    },
    {
        .id = LDI,
        .params = 3,
        .hex = 0x0a,
        .name = "ldi",
        .index = (int[]) {REGEX,  REGEX, REGISTER},
        .size = IND_SIZE,
        .check_inst = &check_load_further
    },
    {
        .id = LD,
        .params = 2,
        .hex = 0x02,
        .name = "ld",
        .index = (int[]) {UNDEFINED, REGISTER},
        .size = DIR_SIZE,
        .check_inst = &check_load_base
    },
    {
        .id = STI,
        .params = 3,
        .hex = 0x0b,
        .name = "sti",
        .index = (int[]) {REGISTER,  REGEX, REGEX},
        .size = IND_SIZE,
        .check_inst = &check_sti
    },
    {
        .id = ST,
        .params = 2,
        .hex = 0x03,
        .name = "st",
        .index = (int[]) {REGISTER,  UNDEFINED},
        .size = 0,
        .check_inst = &check_st
    },
    {
        .id = ADD,
        .params = 3,
        .hex = 0x04,
        .name = "add",
        .index = (int[]) {REGISTER,  REGISTER, REGISTER},
        .size = 0,
        .check_inst = &check_arithm
    },
    {
        .id = SUB,
        .params = 3,
        .hex = 0x05,
        .name = "sub",
        .index = (int[]) {REGISTER,  REGISTER, REGISTER},
        .size = 0,
        .check_inst = &check_arithm
    },
    {
        .id = AND,
        .params = 3,
        .hex = 0x06,
        .name = "and",
        .index = (int[]) {UNDEFINED,  UNDEFINED, REGISTER},
        .size = DIR_SIZE,
        .check_inst = &check_bitwise
    },
    {
        .id = XOR,
        .params = 3,
        .hex = 0x08,
        .name = "xor",
        .index = (int[]) {UNDEFINED,  UNDEFINED, REGISTER},
        .size = DIR_SIZE,
        .check_inst = &check_bitwise
    },
    {
        .id = OR,
        .params = 3,
        .hex = 0x07,
        .name = "or",
        .index = (int[]) {UNDEFINED,  UNDEFINED, REGISTER},
        .size = DIR_SIZE,
        .check_inst = &check_bitwise
    },
    {
        .id = ZJMP,
        .params = 1,
        .hex = 0x09,
        .name = "zjmp",
        .index = (int[]) {INDEX},
        .size = IND_SIZE,
        .check_inst = &check_zjmp
    },
    {
        .id = FORK,
        .params = 1,
        .hex = 0x0c,
        .name = "fork",
        .index = (int[]) {INDEX},
        .size = IND_SIZE,
        .check_inst = &check_fork
    },
    {
        .id = AFF,
        .params = 1,
        .hex = 0x10,
        .name = "aff",
        .index = (int[]) {REGISTER},
        .size = 0,
        .check_inst = &check_aff
    }
};

int launch_parser(asm_t *assembler, char const *filepath);

void write_file(asm_t *assembler);

#endif /* !ASM_H_ */
