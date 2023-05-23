/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** labels
*/

#ifndef LABELS_H_
    #define LABELS_H_
    #include "my_str.h"
    #include "asm/asm.h"

typedef struct label_s {
    str_t *label;
    int location;
} label_t;

VEC_DEF(label_t, label)

int parse_labels(vec_str_t *lines, asm_t *assembler);

int get_label_addr(str_t *label, vec_str_t *body, label_t *stock);

void get_label_value(
    str_t *label, asm_t *assembler, str_t **buffer, size_t type
);

int find_pos(size_t length, asm_t *assembler);

#endif /* !LABELS_H_ */
