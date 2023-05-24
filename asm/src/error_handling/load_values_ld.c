/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** load_values_ld
*/

#include "asm/asm.h"

int check_load_base(size_t instruction, vec_str_t *params)
{
    printf("%s : ", OP_NAME[instruction].name);
    for (size_t i = 0; i < params->size; i++)
        printf("[%s], ", params->data[i]->data);
    printf("\n");
    return SUCCESS;
}

int check_load_further(size_t instruction, vec_str_t *params)
{
    printf("%s : ", OP_NAME[instruction].name);
    for (size_t i = 0; i < params->size; i++)
        printf("[%s], ", params->data[i]->data);
    printf("\n");
    return SUCCESS;
}

/*

LD && LLD : 2 parameters
first parameter into the second parameter,
second == register.

*/

/*

LDI && LLDI : 3 parameters
1st && 2nd == index or register
3rd == register

*/
