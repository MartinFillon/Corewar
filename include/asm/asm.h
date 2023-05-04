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

    static const op_name_t OP_NAME[] = {
        {
            .id = LIVE,
            .nb_param = 0,
            .hex = 0x01,
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
long find_name(str_t *str, str_t *find);
void parse_instruction_parameter(str_t *param, int UNUSED index);
void get_coding_byte(str_t *param_type);

/* UTILS */
int nb_char_to_skip(str_t *line, char delimiter, int start);

/* ERROR HANDLING */
// BASE
int check_args(int argc);

int convert_big_endian(int little);

/* CONVERSION */
void write_file(header_t *header, const char *filepath);

#endif /* !ASM_H_ */
