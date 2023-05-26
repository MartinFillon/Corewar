/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** stores_value_st
*/

#include "my_stdio.h"
#include "my_stdlib.h"

#include "asm/asm.h"

int check_st(size_t instruction, vec_str_t *params)
{
    if (params->data[0]->data[0] != 'r'){
        my_dprintf(2, "%s: takes a register as 1st parameter\n",
        OP_NAME[instruction].name);
        return ERROR;
    }
    if (params->data[1]->data[0] != 'r' && my_atoi(params->data[1]->data) == 0
        && params->data[1]->data[0] != '0' &&
        params->data[1]->data[0] != LABEL_CHAR &&
        OP_NAME[instruction].size != 2){
        my_dprintf(2, "%s: takes a register or a number as 2nd parameter\n",
        OP_NAME[instruction].name);
        return ERROR;
    }
    return SUCCESS;
}

int check_sti(size_t instruction, vec_str_t *params)
{
    if (params->data[0]->data[0] != 'r'){
        my_dprintf(2, "%s: takes a register as 1st parameter\n",
        OP_NAME[instruction].name);
        return ERROR;
    }
    return SUCCESS;
}
