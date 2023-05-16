/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** direct
*/

#include "my_str.h"
#include "my_stdlib.h"

void manage_direct(vec_str_t *params, str_t **buffer, size_t i)
{
    str_t *tmp = str_create(params->data[i]->data + 1);
    int value = 0;

    if (value != 0 || tmp->data[i] == '0'){
        value = my_atoi(params->data[i]->data + 1);
    }
    str_cadd(buffer, 0x00);
    str_cadd(buffer, 0x00);
    str_cadd(buffer, (value >> 8) & 0xFF);
    str_cadd(buffer, value & 0xFF);
}
