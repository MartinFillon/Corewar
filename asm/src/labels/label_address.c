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
