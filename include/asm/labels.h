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

int get_label_addr(str_t *label, asm_t *assembler, vec_str_t *body);

#endif /* !LABELS_H_ */
