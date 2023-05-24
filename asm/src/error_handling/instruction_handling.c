/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction_handling
*/

#include "asm/asm.h"

int check_live(size_t instruction, vec_str_t *params)
{
    printf("%s : ", OP_NAME[instruction].name);
    for (size_t i = 0; i < params->size; i++)
        printf("[%s], ", params->data[i]->data);
    printf("\n");
    return SUCCESS;
}

int check_zjmp(size_t instruction, vec_str_t *params)
{
    printf("%s : ", OP_NAME[instruction].name);
    for (size_t i = 0; i < params->size; i++)
        printf("[%s], ", params->data[i]->data);
    printf("\n");
    return SUCCESS;
}

int check_aff(size_t instruction, vec_str_t *params)
{
    printf("%s : ", OP_NAME[instruction].name);
    for (size_t i = 0; i < params->size; i++)
        printf("[%s], ", params->data[i]->data);
    printf("\n");
    return SUCCESS;
}

/* LIVE : 1 parameter

ZJMP : 1 parameter
must be an index.
Otherwise, it does nothing but consumes the same time.

AFF : takes 1 parameter
must be a register.

*/
