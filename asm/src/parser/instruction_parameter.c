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
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

#include "corewar/op.h"
#include "asm/asm.h"
#include "asm/body.h"

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

void get_parameters(vec_str_t *params, str_t **buffer)
{
    int value = 0;

    for (size_t i = 0; i < params->size; i++) {
        if (str_startswith(params->data[i], STR(DIRECT_CHAR))) {
            manage_direct(params, buffer, i);
        }
        if (str_startswith(params->data[i], STR("r"))) {
            value = my_atoi(params->data[i]->data + 1);
            str_cadd(buffer, value);
        }
        if (!str_startswith(params->data[i], STR("r")) &&
            !str_startswith(params->data[i], STR(DIRECT_CHAR))) {
            value = my_atoi(params->data[i]->data);
            str_cadd(buffer, (value >> 8) & 0xFF);
            str_cadd(buffer, value & 0xFF);
        }
    }
}

static str_t *add_parameter(
    vec_str_t *params, str_t *param_type, champ_t *champ
)
{
    (void)champ;
    for (size_t i = 0; i < params->size; i++) {
        str_ltrim(&params->data[i], ' ');
        str_ltrim(&params->data[i], '\t');
        if (str_startswith(params->data[i], STR(DIRECT_CHAR))){
            if (params->data[i]->data[1] == LABEL_CHAR){
                my_printf("label\n");
                continue;
                // str_slice(&params->data[i], 2, params->data[i]->length);
                // vec_pushback(&champ->label, &params->data[i]);
            }
            str_sadd(&param_type, STR(DIRECT));
            // vec_pushback(&champ->types, dir);
        }
        if (str_startswith(params->data[i], STR("r"))){
            str_sadd(&param_type, STR(REG));
            // vec_pushback(&champ->types, reg);
        }
        if (!str_startswith(params->data[i], STR("r")) &&
            !str_startswith(params->data[i], STR(DIRECT_CHAR))){
            str_sadd(&param_type, STR(INDIRECT));
            // vec_pushback(&champ->types, ind);
        }
    }
    return param_type;
}

int parse_instruction_parameter(
    str_t *param, size_t index, str_t **buffer, champ_t *champ
)
{
    str_t *param_type = str_create("");

    if (str_count(param, ',') != OP_NAME[index].nb_param){
        return ERROR;
    }
    param_type = add_parameter(champ->params, param_type, champ);
    str_cadd(buffer, ((char) OP_NAME[index].hex));
    get_coding_byte(param_type, buffer, index);
    get_parameters(champ->params, buffer);
    vec_free(champ->params);
    free(param_type);
    return SUCCESS;
}
