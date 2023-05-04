/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** body
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

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

int to_define(str_t *line, size_t i)
{
    size_t to_skip = 0;

    if ((to_skip = find_name(line, str_create(OP_NAME[i].name))) != 84) {
        if (str_count(line, ',') != OP_NAME[i].nb_param)
            return ERROR;
        parse_instruction_parameter(str_create(&line->data[to_skip]), i);
    }
    return SUCCESS;
}

int get_instruction_data(str_t *line)
{
    for (size_t i = 0; i <= AFF; i++) {
        if (to_define(line, i) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

int parse_body(vec_str_t *champ)
{
    for (size_t i = 0; i < champ->size; i++) {
        if (champ->data[i]->data[0] == COMMENT_CHAR ||
            champ->data[i]->length == 0 || champ->data[i]->data[0] == '.') {
            vec_remove(champ, i);
            i--;
        }
    }
    for (size_t i = 0; i < champ->size; i++) {
        if (get_instruction_data(champ->data[i]) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}
