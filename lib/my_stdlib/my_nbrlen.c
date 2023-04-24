/*
** EPITECH PROJECT, 2023
** my_stdlib
** File description:
** my_nbr_len
*/

#include "my_stdlib.h"

size_t my_nbrlen(long int nb, int base)
{
    size_t nb_digit = 0;

    if (nb == 0)
        return 1;

    while (nb) {
        nb_digit++;
        nb /= base;
    }

    return nb_digit;
}
