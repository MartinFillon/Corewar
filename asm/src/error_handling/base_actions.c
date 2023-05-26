/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction_handling
*/

#include "my_stdio.h"

#include "asm/asm.h"

int check_live(size_t instruction, vec_str_t *params)
{
    if (params->data[0]->data[0] != '%'){
        my_dprintf(2, "%s: takes a direct as parameter\n",
        OP_NAME[instruction].name);
        return ERROR;
    }
    return SUCCESS;
}

int check_zjmp(size_t instruction, vec_str_t *params)
{
    if (params->data[0]->data[0] != '%')
        my_dprintf(2, "%s: takes an index as parameter\n",
        OP_NAME[instruction].name);
    return SUCCESS;
}

int check_aff(size_t instruction, vec_str_t *params)
{
    if (params->data[0]->data[0] != 'r'){
        my_dprintf(2, "%s: takes a register as parameter\n",
        OP_NAME[instruction].name);
        return ERROR;
    }
    return SUCCESS;
}
