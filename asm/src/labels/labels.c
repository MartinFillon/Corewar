/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** labels
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_stdlib.h"
#include "my_str.h"
#include "my_cstr.h"
#include "my_stdio.h"

#include "asm/asm.h"
#include "asm/body.h"

static int get_label_addr(str_t *label, asm_t *assembler, vec_str_t *body)
{
    (void)label;
    (void)assembler;
    (void)body;
    return ERROR;
}

static int exclude_instructions(str_t *lines, asm_t *assembler)
{
    vec_str_t *words = NULL;
    label_t label = {0};

    for (size_t i = 0; i < AFF; i++){
        if (my_strncmp(lines->data, OP_NAME[i].name,
            my_strlen(OP_NAME[i].name)) == 0){
            return SUCCESS;
        }
    }
    words = str_split(lines, STR(" \t"));
    if (words->data[0]->data[words->data[0]->length - 1] == LABEL_CHAR){
        label.label = words->data[0];
        label.location = get_label_addr(label.label, assembler, words);
        vec_pushback(&assembler->labels, &label);
    }
    return SUCCESS;
}

int parse_labels(vec_str_t *lines, asm_t *assembler)
{
    (void)assembler;
    for (size_t i = 0; i < lines->size; i++) {
        if (lines->data[i]->data[0] == COMMENT_CHAR ||
            lines->data[i]->length == 0 || lines->data[i]->data[0] == '.') {
            free(lines->data[i]);
            vec_remove(lines, i);
            i--;
        }
    }
    for (size_t i = 0; i < lines->size; i++){
        if (exclude_instructions(lines->data[i], assembler) == ERROR){
            return ERROR;
        }
    }
    return SUCCESS;
}
