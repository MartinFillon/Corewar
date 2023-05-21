/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** prog_size
*/

#include "my_str.h"

#include "asm/asm.h"
#include "corewar/op.h"

static void find_for_params(vec_str_t *input, size_t i, int *size)
{
    for (size_t idx = 1; idx < input->size; idx++){
        if (input->data[idx]->length == 0)
            continue;
        if (input->data[idx]->data[0] == 'r'){
            *size += 1;
        }
        if (input->data[idx]->data[0] != 'r' &&
            input->data[idx]->data[0] != '%'){
            *size += 2;
        }
        if (input->data[idx]->data[0] == '%' && OP_NAME[i].size != 0){
            *size += OP_NAME[i].size;
        }
    }
}

void get_prog_size(str_t *champ, int *size)
{
    vec_str_t *input = NULL;

    input = str_split(champ, STR(", \t"));
    if (str_endswith(input->data[0], STR(":"))){
        vec_remove(input, 0);
        if (input->size == 0)
            return;
    }
    if (str_compare(input->data[0], STR("live")) != 0 &&
        str_compare(input->data[0], STR("lfork")) != 0 &&
        str_compare(input->data[0], STR("fork")) != 0 &&
        str_compare(input->data[0], STR("zjmp")) != 0){
            *size += 2;
    } else
        *size += 1;
    for (size_t i = 0; i < AFF; i++){
        if (my_strcmp(input->data[0]->data, OP_NAME[i].name) == 0){
            find_for_params(input, i, size);
        }
    }
}
