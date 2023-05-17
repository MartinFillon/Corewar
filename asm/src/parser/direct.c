/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** direct
*/

#include "my_str.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_cstr.h"

#include "asm/asm.h"

char DIR4 = '0';
char DIR2 = '2';

static void get_direct_index(char type, long nbr, str_t **buffer)
{
    if (type == DIR2) {
        if (nbr < 0) {
            nbr = 65536 + nbr;
            str_cadd(buffer, (nbr / (long)256));
            str_cadd(buffer, (nbr % (long)256));
        } else {
            str_cadd(buffer, (nbr / (long)256));
            str_cadd(buffer, (nbr % (long)256));
        }
    }
}

static void get_direct_int(char type, long nbr, str_t **buffer)
{
    if (type == DIR4) {
        if (nbr < 0) {
            nbr = 4294967296 + nbr;
            str_cadd(buffer, (nbr / 16777216));
            str_cadd(buffer, (nbr / 65536) % (long)256);
            str_cadd(buffer, (nbr / (long)256) % (long)256);
            str_cadd(buffer, (nbr % (long)256));
        } else {
            str_cadd(buffer, (nbr / 16777216));
            str_cadd(buffer, (nbr / 65536 % (long)256));
            str_cadd(buffer, ((nbr / (long)256) % (long)256));
            str_cadd(buffer, (nbr % (long)256));
        }
    }
    get_direct_index(type, nbr, buffer);
}

void manage_direct(str_t *param, str_t **buffer)
{
    int value = 0;
    char type = 0;
    str_t *tmp = str_create(param->data + 1);

    if (tmp->data[0] == LABEL_CHAR){
        str_cadd(buffer, 0x00);
        return;
    }
    value = my_atoi(tmp->data);
    if (value == 0 && tmp->data[0] != '0'){
        my_dprintf(2, " invalid parameter (%%%s)\n", tmp->data);
        free(tmp);
        return;
    }
    get_direct_int(type, value, buffer);
    free(tmp);
}
