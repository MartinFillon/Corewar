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

int parse_labels(vec_str_t *lines, asm_t *assembler);

int get_label_addr(str_t *label, vec_str_t *body);

void get_label_value(str_t *label, asm_t *assembler, str_t **buffer);

#endif /* !LABELS_H_ */
