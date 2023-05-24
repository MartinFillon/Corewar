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
#include "asm/error.h"

static bool check_for_label(str_t *line, size_t index)
{
    str_t *tmp = str_create(line->data);

    if (my_strncmp(line->data, OP_NAME[index].name,
        my_strlen(OP_NAME[index].name)) == 0
        && line->data[my_strlen(OP_NAME[index].name)] != ':' ){
            str_slice(&tmp, 0, my_strlen(OP_NAME[index].name));
            if (tmp->data[0] == ' ' || tmp->data[0] == '\t'){
                free(tmp);
                return false;
            }
    }
    free(tmp);
    return true;
}

static void exclude_instructions(
    str_t *line, asm_t *assembler, vec_str_t *lines
)
{
    vec_str_t *words = NULL;
    label_t label = {0};

    for (size_t i = 0; i < AFF; i++){
        if (check_for_label(line, i) == false){
            return;
        }
    }
    words = str_split(line, STR(" \t"));
    clean_comments(&words);
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

void get_label_value(
    str_t *label, asm_t *assembler, str_t **buffer, size_t type
)
{
    long value = 0;

    str_slice(&label, 1, label->length);
    str_cadd(&label, ':');
    for (size_t i = 0; i < assembler->labels->size; i++){
        if (str_compare(label, assembler->labels->data[i].label) == 0){
            value = assembler->labels->data[i].location -
            find_pos((*buffer)->length, assembler);
            printf("pos %ld\n", value);
            break;
        }
    }
    get_direct_int(type, value, buffer);
}
