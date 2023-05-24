/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** stores_value_st
*/

#include "my_str.h"
#include "my_vec.h"

#include "asm/asm.h"

int check_st(size_t instruction, vec_str_t *params)
{
    printf("%s : ", OP_NAME[instruction].name);
    for (size_t i = 0; i < params->size; i++)
        printf("[%s], ", params->data[i]->data);
    printf("\n");
    return SUCCESS;
}

int check_sti(size_t instruction, vec_str_t *params)
{
    printf("%s : ", OP_NAME[instruction].name);
    for (size_t i = 0; i < params->size; i++)
        printf("[%s], ", params->data[i]->data);
    printf("\n");
    return SUCCESS;
}

/* ST : takes 2 parameters.
1st == resgister, 2nd register or a number

STI : takes 3 parameters.
1st == register, 2nd & 3rd == index or register

*/
