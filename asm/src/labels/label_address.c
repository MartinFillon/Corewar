/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** label_address
*/

#include "my_str.h"

#include "asm/asm.h"

int get_label_addr(str_t *label, asm_t *assembler, vec_str_t *body)
{
    (void)assembler;
    size_t size = 0;

    for (size_t i = 0; i < body->size; i++){
        if (my_strcmp(body->data[i]->data, label->data) == 0){
            my_printf("%s\n", body->data[i]->data);
            return size;
        }
    }
    return ERROR;
}
