/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction_parameter
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "my_cstr.h"
#include "my_stdio.h"
#include "my_str.h"
#include "my_vec.h"

#include "asm/asm.h"
#include "corewar/op.h"

static int str_count(str_t *str, char c)
{
    int count = 0;
    for (size_t i = 0; i < str->length; i++) {
        if (str->data[i] == c)
            count++;
    }
    return count;
}

static void get_coding_byte(str_t *param_type, str_t **buffer, int index)
{
    unsigned char coding_byte = 0;

    if (index == LIVE || index == ZJMP || index == FORK || index == LFORK )
        return;
    for (size_t i = 0; i <= 7; i++) {
        coding_byte <<= 1;
        if (i > param_type->length)
            continue;
        if (param_type->data[i] == '1') {
            coding_byte |= 1;
        }
    }
    str_cadd(buffer, coding_byte);
}

int parse_instruction_parameter(str_t *param, int index, str_t **buffer)
{
    vec_str_t *params = str_split(param, STR(SEPARATOR_CHAR));
    str_t *param_type = str_create("");
    if (str_count(param, ',') != OP_NAME[index].nb_param)
        return ERROR;
    str_cadd(buffer, ((char) OP_NAME[index].hex));
    for (size_t i = 0; i < params->size; i++) {
        str_ltrim(&params->data[i], ' ');
        str_ltrim(&params->data[i], '\t');
        if (str_startswith(params->data[i], STR(DIRECT_CHAR)))
            str_sadd(&param_type, STR(DIRECT));
        if (str_startswith(params->data[i], STR("r")))
            str_sadd(&param_type, STR(REG));
        if (!str_startswith(params->data[i], STR("r")) &&
            !str_startswith(params->data[i], STR(DIRECT_CHAR)))
            str_sadd(&param_type, STR(INDIRECT));
    }
    get_coding_byte(param_type, buffer, index);
    vec_free(params);
    free(param_type);
    return SUCCESS;
}
