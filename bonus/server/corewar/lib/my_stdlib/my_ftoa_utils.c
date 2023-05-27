/*
** EPITECH PROJECT, 2023
** my_stdlib
** File description:
** my_ftoa utils
*/

#include "my_stdlib.h"
#include "./include/my_ftoa.h"

void my_ftoa_init_buffers(char *res, char *power)
{
    my_memset(res, '0', RES_SIZE);
    my_memset(power, '0', FLOAT_PART);

    res[RES_SIZE] = '\0';
    power[FLOAT_PART] = '\0';
    res[INT_PART] = '1';
    res[INT_PART + 1] = '.';
    power[0] = '.';
    power[1] = '5';
}
