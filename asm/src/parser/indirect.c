/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** indirect
*/

#include <stdlib.h>

#include "my_stdio.h"
#include "my_stdlib.h"

#include "asm/asm.h"

static void get_indirect(size_t type, long nbr, str_t **buffer)
{
    if (type == IND_SIZE) {
        if (nbr < 0) {
            nbr = 65536 + nbr;
            str_cadd(buffer, (nbr / 256));
            str_cadd(buffer, (nbr % 256));
        } else {
            str_cadd(buffer, (nbr / 256));
            str_cadd(buffer, (nbr % 256));
        }
    }
}

void manage_indirect(str_t *param, str_t **buffer, size_t type)
{
    int value = 0;
    str_t *tmp = str_create(param->data);

    value = my_atoi(tmp->data);
    if (value == 0 && tmp->data[0] != '0'){
        my_dprintf(2, " invalid parameter (%%%s)\n", tmp->data);
        free(tmp);
        return;
    }
    get_indirect(type, value, buffer);
    free(tmp);
}
