/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** body
*/

#include <unistd.h>
#include <stdio.h>

#include "my_cstr.h"
#include "my_stdio.h"
#include "my_str.h"
#include "my_vec.h"

#include "asm/asm.h"
#include "corewar/op.h"

long my_str_find(str_t *str, str_t *find, size_t start)
{
    if (find->length > str->length)
        return -1;
    if (start >= str->length)
        return -1;
    for (size_t i = start; i < str->length - find->length; ++i) {
        if (my_strncmp(str->data + i, find->data, find->length) ==
        0 && (str->data[i + find->length] == ' ' ||
        str->data[i + find->length] == '\t'))
            return i;
        }
    return -1;
}

static int str_count(str_t *str, char c)
{
    int count = 0;
    for (size_t i = 0; i < str->length; i++) {
        if (str->data[i] == c)
            count++;
    }
    return count;
}

static int get_coding_byte(str_t *line, int i)
{
    if (str_count(line, ',') != OP_NAME[i].nb_param) {
        my_printf("error nb parameter\n");
        return ERROR;
    }
    return SUCCESS;
}

int get_instruction_name(str_t *line)
{
    for (size_t i = 0; i <= AFF; i++) {
        if (my_str_find(line, str_create(OP_NAME[i].name), 0) != -1) {
            my_printf("%s\n", OP_NAME[i].name);
            return get_coding_byte(line, i);
        }
    }
    return SUCCESS;
}

int parse_body(vec_str_t *champ)
{
    for (size_t i = 0; i < champ->size; i++) {
        if (champ->data[i]->data[0] == '#' ||
        champ->data[i]->length == 0 || champ->data[i]->data[0] == '.') {
            vec_remove(champ, i);
            i--;
        }
    }
    for (size_t i = 0; i < champ->size; i++) {
        if (get_instruction_name(champ->data[i]) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}
