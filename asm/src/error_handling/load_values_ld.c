/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** load_values_ld
*/

#include "my_stdio.h"

#include "asm/asm.h"

int check_load_base(size_t instruction, vec_str_t *params)
{
    if (params->data[1]->data[0] != 'r'){
        my_dprintf(2, "%s: takes a register as parameter\n",
        OP_NAME[instruction].name);
        return ERROR;
    }
    return SUCCESS;
}

int check_load_further(size_t instruction, vec_str_t *params)
{
    if (params->data[2]->data[0] != 'r'){
        my_dprintf(2, "%s: takes a register as 3rd parameter\n",
        OP_NAME[instruction].name);
        return ERROR;
    }
    return SUCCESS;
}
