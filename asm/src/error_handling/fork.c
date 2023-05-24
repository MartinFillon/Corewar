/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fork
*/

#include "asm/asm.h"

int check_fork(size_t instruction, vec_str_t *params)
{
    printf("%s : ", OP_NAME[instruction].name);
    for (size_t i = 0; i < params->size; i++)
        printf("[%s], ", params->data[i]->data);
    printf("\n");
    return SUCCESS;
}

/*

FORK && LFORK:
takes 1 parameter, which must be an index.

*/
