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
    #define ERROR 84
    #define SUCCESS 0

    typedef struct op_name_s {
        int id;
        const int nb_param;
        const uint8_t hex;
        const int *param_type;
        const char *name;
    }op_name_t;

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
        REG,
        DIRECT,
        INDIRECT,
    };

    static const op_name_t OP_NAME[] = {
        {
            .id = LIVE,
            .nb_param = 0,
            .hex = 0x01,
            .param_type =
            (int[]) {

            },
            .name = "live",
        },
        {
            .id = LD,
            .nb_param = 1,
            .hex = 0x02,
            .name = "ld",
        },
        {
            .id = ST,
            .nb_param = 1,
            .hex = 0x03,
            .name = "st",
        },
        {
            .id = ADD,
            .nb_param = 2,
            .hex = 0x04,
            .name = "add",
        },
        {
            .id = SUB,
            .nb_param = 2,
            .hex = 0x05,
            .name = "sub",
        },
        {
            .id = AND,
            .nb_param = 2,
            .hex = 0x06,
            .name = "and",
        },
        {
            .id = OR,
            .nb_param = 2,
            .hex = 0x07,
            .name = "OR",
        },
        {
            .id = XOR,
            .nb_param = 2,
            .hex = 0x08,
            .name = "xor",
        },
        {
            .id = ZJMP,
            .nb_param = 0,
            .hex = 0x09,
            .name = "zjmp",
        },
        {
            .id = LDI,
            .nb_param = 2,
            .hex = 0x0a,
            .name = "ldi",
        },
        {
            .id = STI,
            .nb_param = 2,
            .hex = 0x0b,
            .name = "sti",
        },
        {
            .id = FORK,
            .nb_param = 0,
            .hex = 0x0c,
            .name = "fork",
        },
        {
            .id = LLD,
            .nb_param = 1,
            .hex = 0x0d,
            .name = "lld",
        },
        {
            .id = LLDI,
            .nb_param = 2,
            .hex = 0x0e,
            .name = "lldi",
        },
        {
            .id = LFORK,
            .nb_param = 0,
            .hex = 0x0f,
            .name = "lfork",
        },
        {
            .id = AFF,
            .nb_param = 0,
            .hex = 0x10,
            .name = "aff"
        }
    };

/* PARSER */
int launch_parser(header_t *header, char const *filepath);
int parse_body(vec_str_t *champ);

/* ERROR HANDLING */
// BASE
int check_args(int argc);

/* CONVERSION */
void write_file(header_t *header, const char *filepath);

#endif /* !ASM_H_ */
