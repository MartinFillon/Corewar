/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** arithmetic
*/

#include "my_stdio.h"

#include "asm/asm.h"

int check_arithm(size_t instruction, vec_str_t *params)
{
    for (size_t i = 0; i < params->size; i++){
        if (params->data[i]->data[0] != 'r'){
            my_dprintf(2, "%s: takes 3 registers as parameter\n",
            OP_NAME[instruction].name);
            return ERROR;
        }
    }
    return SUCCESS;
}

int check_bitwise(size_t instruction, vec_str_t *params)
{
    if (params->data[2]->data[0] != 'r'){
        my_dprintf(2, "%s: takes a register as 3rd parameter\n",
        OP_NAME[instruction].name);
        return ERROR;
    }
    return SUCCESS;
}
