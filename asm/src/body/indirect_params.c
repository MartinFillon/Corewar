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

static const int BITS_IND_MAX = 65536;
static const int MAX_BYTE_VAL = 256;

static void get_indirect(long nbr, str_t **buffer)
{
    if (nbr < 0) {
        nbr = BITS_IND_MAX + nbr;
        str_cadd(buffer, (nbr / MAX_BYTE_VAL));
        str_cadd(buffer, (nbr % MAX_BYTE_VAL));
    } else {
        str_cadd(buffer, (nbr / MAX_BYTE_VAL));
        str_cadd(buffer, (nbr % MAX_BYTE_VAL));
    }
}

int manage_indirect(str_t *param, str_t **buffer, size_t type, asm_t *assembler)
{
    int value = 0;
    str_t *tmp = str_create(param->data);

    if (tmp->data[0] == LABEL_CHAR){
        get_label_value(tmp, assembler, buffer, type);
        free(tmp);
        return SUCCESS;
    }
    value = my_atoi(tmp->data);
    if (value == 0 && tmp->data[0] != '0'){
        my_dprintf(2, "body: Invalid parameter (%s)\n", tmp->data);
        free(tmp);
        return ERROR;
    }
    get_indirect(value, buffer);
    free(tmp);
    return SUCCESS;
}
