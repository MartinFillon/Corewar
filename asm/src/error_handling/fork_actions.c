/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fork
*/

#include "my_stdio.h"

#include "asm/asm.h"

int check_fork(size_t instruction, vec_str_t *params)
{
    if (params->data[0]->data[0] != '%'){
        my_dprintf(2, "%s: takes an index as parameter\n",
        OP_NAME[instruction].name);
        return ERROR;
    }
    return SUCCESS;
}
