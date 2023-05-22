/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** label_address
*/

#include "my_str.h"
#include "my_stdio.h"

#include "asm/asm.h"
#include "asm/header.h"

int find_pos(size_t length, asm_t *assembler)
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

    for (size_t i = 0; i < body->size; i++){
        if (my_strncmp(body->data[i]->data, label->data, label->length) == 0){
            break;
        }
        get_prog_size(body->data[i], &size);
    }
    stock->location = size;
    return SUCCESS;
}
