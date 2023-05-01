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
        //if (i + 1 == str->length || i - find->length <= 0)
            //continue;
        //my_printf("avant = %c et apres = %c\n", str->data[i - 1], str->data[i + find->length]);
        if (my_strncmp(str->data + i, find->data, find->length) == 0 && (str->data[i + find->length] == ' ' || str->data[i + find->length] == '\t'))
            return i;
        }
    return -1;
}

static int nb_occurrence(str_t *str, char c)
{
    int count = 0;
    for (size_t i = 0; i < str->length; i++) {
        if (str->data[i] == c)
            count++;
    }
    return count;
}

void get_instruction_name(str_t *line)
{
    for (size_t i = 0; i <= AFF; i++) {
        if (my_str_find(line, str_create(OP_NAME[i].name), 0) != -1) {
            my_printf("%s\n", OP_NAME[i].name);
            if (nb_occurrence(line, ',') != OP_NAME[i].nb_param)
                my_printf("erreur zebi\n");
        }
    }
}

str_t *parse_body(vec_str_t *champ)
{
    for (size_t i = 0; i < champ->size; i++) {
        if (champ->data[i]->data[0] == '#' || champ->data[i]->length == 0 || champ->data[i]->data[0] == '.') {
            vec_remove(champ, i);
            i--;
        }
    }
    for (size_t i = 0; i < champ->size; i++) {
        get_instruction_name(champ->data[i]);
    }                                 
    return NULL;
}
