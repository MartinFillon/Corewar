/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** utils
*/

#include "my_str.h"

int str_count(str_t *str, char c)
{
    int count = 0;

    for (size_t i = 0; i < str->length; i++) {
        if (str->data[i] == c)
            count++;
    }
    return count;
}
