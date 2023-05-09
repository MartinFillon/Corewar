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

static int find_instruction(str_t *line, size_t index)
{
    int callback = 0;

    for (size_t i = 0; i < line->length; i++) {
        if ((callback = str_find(line, str_create(OP_NAME[index].name), i)) !=
                -1 &&
            (line->data[callback + my_strlen(OP_NAME[index].name)] == ' ' ||
            line->data[callback + my_strlen(OP_NAME[index].name)] == '\t'))
            return callback;
    }
    return -1;
}

static int manage_instruction(str_t *line)
{
    int callback = 0;

    for (size_t i = 0; i <= AFF; i++) {
        if ((callback = find_instruction(line, i)) != -1) {
            return parse_instruction_parameter(
                str_create(&line->data[callback + my_strlen(OP_NAME[i].name)]),
                i
            );
        }
    }
    return ERROR;
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
        if (manage_instruction(champ->data[i]) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}
