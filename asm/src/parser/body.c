/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** body
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_cstr.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

#include "corewar/op.h"
#include "asm/asm.h"
#include "asm/body.h"

static int find_instruction(str_t *line, str_t const *op_name)
{
    int callback = 0;

    for (size_t i = 0; i < line->length; i++) {
        callback = str_find(line, op_name, i);
        if ((callback != -1) &&
            (line->data[callback + op_name->length] == ' ' ||
            line->data[callback + op_name->length] == '\t')){
                return callback;
            }
        if (callback != 1 &&
            line->data[callback + op_name->length] == LABEL_CHAR){
                str_slice(&line, callback + op_name->length + 2, line->length);
                return callback;
        }
    }
    return -1;
}

static int manage_instruction(
    str_t *line, size_t index, str_t **buffer, asm_t *assembler
)
{
    (void)index;
    champ_t body = {0};
    str_t *name = str_create("");
    str_t *tmp = str_create("");
    int callback = 0;

    for (size_t i = 0; i <= AFF; i++) {
        str_add(str_clear(&name), OP_NAME[i].name);
        callback = find_instruction(line, name);
        if (callback != -1) {
            body.instruction = name;
            tmp = str_create(&line->data[callback + name->length]);
            str_trim(&tmp, '\t');
            str_trim(&tmp, ' ');
            body.params = str_split(tmp, STR(SEPARATOR_CHAR));
            callback = parse_instruction_parameter(tmp, i, buffer, &body);
            vec_pushback(&assembler->champ, &body);
            my_vfree(2, tmp, name);
            return callback;
        }
    }
    free(name);
    return ERROR;
}

int parse_body(vec_str_t *body, asm_t *assembler, str_t **buffer)
{
    for (size_t i = 0; i < body->size; i++) {
        if (body->data[i]->data[0] == COMMENT_CHAR ||
            body->data[i]->length == 0 || body->data[i]->data[0] == '.') {
            free(body->data[i]);
            vec_remove(body, i);
            i--;
        }
    }
    for (size_t i = 0; i < body->size; i++) {
        if (manage_instruction(body->data[i], i, buffer, assembler) == ERROR){
            return ERROR;
        }
    }
    return SUCCESS;
}
