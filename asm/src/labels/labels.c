/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** labels
*/

#include <stdlib.h>

#include "my_stdlib.h"
#include "my_str.h"
#include "my_cstr.h"
#include "my_stdio.h"

#include "asm/asm.h"
#include "asm/body.h"
#include "asm/labels.h"

static int exclude_instructions(str_t *line, asm_t *assembler, vec_str_t *lines)
{
    (void)assembler;
    vec_str_t *words = NULL;
    label_t label = {0};

    for (size_t i = 0; i < AFF; i++){
        if (my_strncmp(line->data, OP_NAME[i].name,
            my_strlen(OP_NAME[i].name)) == 0 &&
            line->data[my_strlen(OP_NAME[i].name)] != ':'){
            return SUCCESS;
        }
    }
    words = str_split(line, STR(" \t"));
    if (words->data[0]->data[words->data[0]->length - 1] == LABEL_CHAR){
        label.label = words->data[0];
        label.location = get_label_addr(label.label, lines);
        vec_pushback(&assembler->labels, &label);
    }
    return SUCCESS;
}

int parse_labels(vec_str_t *lines, asm_t *assembler)
{
    for (size_t i = 0; i < lines->size; i++) {
        if (lines->data[i]->data[0] == COMMENT_CHAR ||
            lines->data[i]->length == 0 || lines->data[i]->data[0] == '.') {
            free(lines->data[i]);
            vec_remove(lines, i);
            i--;
        }
    }
    for (size_t i = 0; i < lines->size; i++){
        if (exclude_instructions(lines->data[i], assembler, lines) == ERROR)
            return ERROR;
    }
    my_printf("%s = %d\n", assembler->labels[0].data->label->data,
    assembler->labels[0].data->location);
    my_printf("%s = %d\n", assembler->labels[1].data->label->data,
    assembler->labels[1].data->location);
    return SUCCESS;
}

void get_label_value(str_t *label, asm_t *assembler, str_t **buffer)
{
    (void)buffer;
    (void)label;
    for (size_t i = 0; i < assembler->labels->size; i++){
        my_printf("%s\n", assembler->labels[i].data->label->data);
        my_printf("%d\n", assembler->labels[i].data->location);
    }
}
