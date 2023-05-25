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
#include "asm/labels.h"

static const long BITS_DIR_MAX = 4294967296;
static const long BITS_IND_MAX = 65536;
static const long MAX_BYTE_VAL = 256;

static void get_direct_index(size_t type, long nbr, str_t **buffer)
{
    if (type == IND_SIZE) {
        if (nbr < 0) {
            nbr = BITS_IND_MAX + nbr;
            str_cadd(buffer, (nbr / MAX_BYTE_VAL));
            str_cadd(buffer, (nbr % MAX_BYTE_VAL));
        } else {
            str_cadd(buffer, (nbr / MAX_BYTE_VAL));
            str_cadd(buffer, (nbr % MAX_BYTE_VAL));
        }
    }
}

void get_direct_int(size_t type, long nbr, str_t **buffer)
{
    if (type == DIR_SIZE) {
        if (nbr < 0) {
            nbr = BITS_DIR_MAX + nbr;
            str_cadd(buffer, (nbr / (BITS_IND_MAX * BITS_IND_MAX)));
            str_cadd(buffer, (nbr / BITS_IND_MAX) % MAX_BYTE_VAL);
            str_cadd(buffer, (nbr / MAX_BYTE_VAL) % MAX_BYTE_VAL);
            str_cadd(buffer, (nbr % MAX_BYTE_VAL));
        } else {
            str_cadd(buffer, (nbr / (BITS_IND_MAX * BITS_IND_MAX)));
            str_cadd(buffer, (nbr / BITS_IND_MAX % MAX_BYTE_VAL));
            str_cadd(buffer, ((nbr / MAX_BYTE_VAL) % MAX_BYTE_VAL));
            str_cadd(buffer, (nbr % MAX_BYTE_VAL));
        }
    }
    get_direct_index(type, nbr, buffer);
}

int manage_direct(str_t *param, str_t **buffer, size_t type, asm_t *assembler)
{
    long value = 0;
    str_t *tmp = str_create(param->data + 1);

    if (tmp->data[0] == LABEL_CHAR){
        get_label_value(tmp, assembler, buffer, type);
        free(tmp);
        return SUCCESS;
    }
    value = my_atoi(tmp->data);
    if (value == 0 && tmp->data[0] != '0'){
        my_dprintf(2, "body: Invalid parameter (%%%s)\n", tmp->data);
        free(tmp);
        return ERROR;
    }
    get_direct_int(type, value, buffer);
    free(tmp);
    return SUCCESS;
}
