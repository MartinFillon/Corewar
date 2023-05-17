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

typedef struct label_s {
    str_t *label;
    int location;
} label_t;

VEC_DEF(label_t, label)

typedef struct champ_s {
    str_t *instruction;
    vec_str_t *params;
    vec_int_t *types;
} champ_t;

VEC_DEF(champ_t, champ)

typedef struct asm_s asm_t;

int parse_body(vec_str_t *body, asm_t *assembler, str_t **buffer);

long find_name(str_t *str, str_t *find);

int parse_instruction_parameter(
    str_t *param, size_t index, str_t **buffer, champ_t *champ
);

int parse_labels(
    str_t *label, int index, str_t **buffer, vec_str_t *all_labels
);

void manage_direct(vec_str_t *params, str_t **buffer, size_t i);

void get_indirect(char type, long nbr, str_t **buffer);

#endif /* !BODY_H */
