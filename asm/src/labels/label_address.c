/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** label_address
*/

#include <stdbool.h>

#include "my_str.h"
#include "my_stdio.h"

#include "asm/asm.h"
#include "asm/header.h"

static int find_pos(size_t length, asm_t *assembler)
{
    int len = 0;

    for (size_t i = 0; i < assembler->champ->size; i++){
        if ((int)length > assembler->champ->data[i].line_size){
            len = assembler->champ->data[i].line_size;
        }
    }
    return len;
}

int get_label_addr(str_t *label, vec_str_t *body, label_t *stock)
{
    int size = 0;
    bool exists = false;

    for (size_t i = 0; i < body->size; i++){
        if (my_strncmp(body->data[i]->data, label->data, label->length) == 0){
            exists = true;
            break;
        }
        get_prog_size(body->data[i], &size);
    }
    if (exists != false){
        stock->location = size;
        return SUCCESS;
    }
    my_dprintf(2, "body: Label %s doesn't exist\n", label->data);
    return ERROR;
}

void get_label_value(
    str_t *label, asm_t *assembler, str_t **buffer, size_t type
)
{
    long value = 0;

    if (type == 0)
        type = 2;
    str_slice(&label, 1, label->length);
    str_cadd(&label, ':');
    for (size_t i = 0; i < assembler->labels->size; i++){
        if (str_compare(label, assembler->labels->data[i].label) == 0){
            value = assembler->labels->data[i].location -
            find_pos((*buffer)->length, assembler);
            break;
        }
    }
    get_direct_int(type, value, buffer);
}
