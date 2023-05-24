/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** arithmetic
*/

#include "asm/asm.h"

int check_arithm(size_t instruction, vec_str_t *params)
{
    printf("%s : ", OP_NAME[instruction].name);
    for (size_t i = 0; i < params->size; i++)
        printf("[%s], ", params->data[i]->data);
    printf("\n");
    return SUCCESS;
}

int check_bitwise(size_t instruction, vec_str_t *params)
{
    printf("%s : ", OP_NAME[instruction].name);
    for (size_t i = 0; i < params->size; i++)
        printf("[%s], ", params->data[i]->data);
    printf("\n");
    return SUCCESS;
}

// takes 3 registers as parameters. (for add and sub)

// takes 3 parameters. (for and, or, xor)
// third one must be a register
