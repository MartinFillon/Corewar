/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parser
*/

#ifndef BODY_H
    #define BODY_H
    #include "my_str.h"
    #include "corewar/op.h"

typedef struct champ_s {
    vec_str_t *params;
    int line_size;
} champ_t;

VEC_DEF(champ_t, champ)

typedef struct asm_s asm_t;

int parse_body(vec_str_t *body, asm_t *assembler, str_t **buffer);

long find_name(str_t *str, str_t *find);

int parse_instruction_parameter(
    str_t *param, size_t index, asm_t *assembler, str_t **buffer
);

int manage_direct(str_t *param, str_t **buffer, size_t type, asm_t *assembler);

int manage_indirect(str_t *param, str_t **buffer, size_t type);

void get_direct_int(size_t type, long nbr, str_t **buffer);

#endif /* !BODY_H */
