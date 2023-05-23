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

static void exclude_instructions(
    str_t *line, asm_t *assembler, vec_str_t *lines
)
{
    vec_str_t *words = NULL;
    label_t label = {0};

    for (size_t i = 0; i < AFF; i++){
        if (my_strncmp(line->data, OP_NAME[i].name,
            my_strlen(OP_NAME[i].name)) == 0 &&
            line->data[my_strlen(OP_NAME[i].name)] != ':'){
            return;
        }
    }
    words = str_split(line, STR(" \t"));
    if (words->data[0]->data[words->data[0]->length - 1] == LABEL_CHAR){
        label.label = str_create(words->data[0]->data);
        get_label_addr(label.label, lines, &label);
        vec_pushback(&assembler->labels, &label);
    }
    vec_free(words);
}

int find_duplicates(vec_label_t *labels, vec_str_t *lines)
{
    size_t count = 0;

    for (size_t i = 0; i < lines->size; i++){
        for (size_t j = 0; j < labels->size; j++){
            (str_ncompare(lines->data[i], labels->data[j].label,
            labels->data[j].label->length) == 0) ? count++ : 0;
        }
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
        exclude_instructions(lines->data[i], assembler, lines);
    }
    if (find_duplicates(assembler->labels, lines) == ERROR){
        return ERROR;
    }
    return SUCCESS;
}

void get_label_value(str_t *label, asm_t *assembler, str_t **buffer)
{
    long value = 0;

    str_slice(&label, 1, label->length);
    for (size_t i = 0; i < assembler->labels->size; i++){
        if (str_ncompare(label, assembler->labels->data[i].label,
            label->length) == 0){
            value = assembler->labels->data[i].location -
            find_pos((*buffer)->length, assembler);
        }
    }
    if (value < 0) {
        value = 65536 + value;
        str_cadd(buffer, (value / 256));
        str_cadd(buffer, (value % 256));
    } else {
        str_cadd(buffer, (value / 256));
        str_cadd(buffer, (value % 256));
    }
}
