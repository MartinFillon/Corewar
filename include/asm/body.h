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

typedef struct labels_s {
    vec_str_t *vector;
} labels_t;

int parse_body(vec_str_t *champ, char const *filepath, header_t *header);

long find_name(str_t *str, str_t *find);

int parse_instruction_parameter(
    str_t *param, int index, str_t **buffer, labels_t *labels
);

int parse_labels(str_t *label, int index, str_t **buffer, labels_t *all_labels);

void manage_direct(vec_str_t *params, str_t **buffer, size_t i);

#endif /* !BODY_H */
