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
    int label = 1;

    for (size_t i = 0; i < line->length; i++) {
        callback = str_find(line, op_name, i);
        if (callback != -1 &&
            line->data[callback + op_name->length] == ' ' ||
            line->data[callback + op_name->length] == '\t'){
                return callback;
            }
        if (callback != 1 &&
            line->data[callback + op_name->length] == LABEL_CHAR){
                return label;
        }
    }
    return -1;
}

static int manage_instruction(str_t *line, str_t **buffer, labels_t *labels)
{
    str_t *name = str_create("");
    str_t *temp = NULL;
    int callback = 0;

    for (size_t i = 0; i <= AFF; i++) {
        str_add(str_clear(&name), OP_NAME[i].name);
        callback = find_instruction(line, name);
        if (callback != -1) {
            temp = str_create(&line->data[callback + name->length]);
            str_ltrim(&temp, ' ');
            str_ltrim(&temp, '\t');
        }
        if (callback == 0){
            callback = parse_instruction_parameter(temp, i, buffer, labels);
            my_vfree(2, temp, name);
            return callback;
        }
        if (callback == 1){
            str_slice(&line, 0, str_find(line, STR(":"), 0));
            callback = parse_labels(line, i, buffer, labels);
            return callback;
        }
    }
    free(name);
    return ERROR;
}

int parse_body(vec_str_t *champ, char const *filepath, header_t *header)
{
    str_t *buffer = str_create("");
    labels_t labels = {.vector = vec_create(100, sizeof(str_t *))};

    for (size_t i = 0; i < champ->size; i++) {
        if (champ->data[i]->data[0] == COMMENT_CHAR ||
            champ->data[i]->length == 0 || champ->data[i]->data[0] == '.') {
            free(champ->data[i]);
            vec_remove(champ, i);
            i--;
        }
    }
    for (size_t i = 0; i < champ->size; i++) {
        if (manage_instruction(champ->data[i], &buffer, &labels) == ERROR){
            return ERROR;
        }
    }
    header->prog_size = buffer->length;
    write_file(header, filepath, buffer);
    free(buffer);
    return SUCCESS;
}
