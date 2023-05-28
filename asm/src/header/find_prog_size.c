/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** prog_size
*/

#include <stdlib.h>

#include "my_str.h"

#include "corewar/op.h"
#include "asm/asm.h"
#include "asm/error.h"

static void find_for_params(vec_str_t *input, size_t i, int *size)
{
    for (size_t idx = 1; idx < input->size; idx++){
        if (str_startswith(input->data[idx], STR("#")))
            break;
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

static void further_in_parameters(vec_str_t *input, int *size)
{
    if (str_compare(input->data[0], STR("live")) != 0 &&
        str_compare(input->data[0], STR("lfork")) != 0 &&
        str_compare(input->data[0], STR("fork")) != 0 &&
        str_compare(input->data[0], STR("zjmp")) != 0){
            *size += 2;
    } else {
        *size += 1;
    }
    for (size_t i = 0; i <= AFF; i++){
        if (my_strcmp(input->data[0]->data, OP_NAME[i].name) == 0){
            find_for_params(input, i, size);
        }
    }
}

void get_prog_size(str_t *champ, int *size)
{
    vec_str_t *input = str_split(champ, STR(", \t"));

    for (size_t i = 0; i < input->size; i++) {
        if (input->data[i]->length == 0) {
            free(input->data[i]);
            vec_remove(input, i);
            i -= 1;
            continue;
        }
    }
    if (str_endswith(input->data[0], STR(":"))){
        free(input->data[0]);
        vec_remove(input, 0);
        if (input->size == 0){
            vec_free(input);
            return;
        }
    }
    further_in_parameters(input, size);
    vec_free(input);
}
