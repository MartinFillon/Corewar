/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#ifndef ASM_H_
    #define ASM_H_
    #include <stdint.h>
    #include "my_str.h"
    #include "corewar/op.h"
    #define UNUSED __attribute__((unused))

    #define ERROR 84
    #define SUCCESS 0

    #define REG "01"
    #define DIRECT "10"
    #define INDIRECT "11"

typedef struct op_name_s {
    int id;
    const int nb_param;
    const uint8_t hex;
    const char *name;
    const int *index;
} op_name_t;

enum {
    LIVE,
    LD,
    ST,
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    ZJMP,
    LDI,
    STI,
    FORK,
    LLD,
    LLDI,
    LFORK,
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
        .nb_param = 0,
        .hex = 0x01,
        .name = "live",
        .index = (int[]) {UNDEFINED},
    },
    {
        .id = LD,
        .nb_param = 1,
        .hex = 0x02,
        .name = "ld",
        .index = (int[]) {UNDEFINED, REGISTER},
    },
    {
        .id = ST,
        .nb_param = 1,
        .hex = 0x03,
        .name = "st",
        .index = (int[]) {REGISTER,  UNDEFINED},
    },
    {
        .id = ADD,
        .nb_param = 2,
        .hex = 0x04,
        .name = "add",
        .index = (int[]) {REGISTER,  REGISTER, REGISTER},
    },
    {
        .id = SUB,
        .nb_param = 2,
        .hex = 0x05,
        .name = "sub",
        .index = (int[]) {REGISTER,  REGISTER, REGISTER},
    },
    {
        .id = AND,
        .nb_param = 2,
        .hex = 0x06,
        .name = "and",
        .index = (int[]) {UNDEFINED,  UNDEFINED, REGISTER},
    },
    {
        .id = OR,
        .nb_param = 2,
        .hex = 0x07,
        .name = "or",
        .index = (int[]) {UNDEFINED,  UNDEFINED, REGISTER},
    },
    {
        .id = XOR,
        .nb_param = 2,
        .hex = 0x08,
        .name = "xor",
        .index = (int[]) {UNDEFINED,  UNDEFINED, REGISTER},
    },
    {
        .id = ZJMP,
        .nb_param = 0,
        .hex = 0x09,
        .name = "zjmp",
        .index = (int[]) {INDEX},
    },
    {
        .id = LDI,
        .nb_param = 2,
        .hex = 0x0a,
        .name = "ldi",
        .index = (int[]) {REGEX,  REGEX, REGISTER},
    },
    {
        .id = STI,
        .nb_param = 2,
        .hex = 0x0b,
        .name = "sti",
        .index = (int[]) {REGISTER,  REGEX, REGEX},
    },
    {
        .id = FORK,
        .nb_param = 0,
        .hex = 0x0c,
        .name = "fork",
        .index = (int[]) {INDEX},
    },
    {
        .id = LLD,
        .nb_param = 1,
        .hex = 0x0d,
        .name = "lld",
        .index = (int[]) {UNDEFINED, REGISTER},
    },
    {
        .id = LLDI,
        .nb_param = 2,
        .hex = 0x0e,
        .name = "lldi",
        .index = (int[]) {REGEX,  REGEX, REGISTER},
    },
    {
        .id = LFORK,
        .nb_param = 0,
        .hex = 0x0f,
        .name = "lfork",
        .index = (int[]) {INDEX},
    },
    {
        .id = AFF,
        .nb_param = 0,
        .hex = 0x10,
        .name = "aff",
        .index = (int[]) {REGISTER},
    }
};

/* PARSER */
int launch_parser(header_t *header, char const *filepath);
int parse_body(vec_str_t *champ, char const *filepath, header_t *header);
long find_name(str_t *str, str_t *find);
int parse_instruction_parameter(str_t *param, int index, str_t **buffer);

/* UTILS */
int nb_char_to_skip(str_t *line, char delimiter, int start);

/* ERROR HANDLING */
// BASE
int check_args(int argc);

int convert_big_endian(int little);

/* CONVERSION */
void write_file(
    header_t const *header,const char *filepath, str_t const *buffer
);

#endif /* !ASM_H_ */
