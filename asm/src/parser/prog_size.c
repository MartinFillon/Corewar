/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** prog_size
*/

#include "asm/asm.h"
#include "corewar/op.h"
#include "my_str.h"

void get_prog_size(str_t *champ, header_t *header)
{
    vec_str_t *input = NULL;

    input = str_split(champ, STR(" \t"));
    if (str_compare(input->data[0], STR("live")) != 0 &&
        str_compare(input->data[0], STR("lfork")) != 0 &&
        str_compare(input->data[0], STR("fork")) != 0 &&
        str_compare(input->data[0], STR("zjmp")) != 0){
            header->prog_size += 2;
    } else {
        header->prog_size += 1;
    }
    // for (size_t i = 1; i < input->size; i++){
    //     if (&input->data[i][0] == 'r')
    //         header->prog_size += 1;
    //     if (&input->data[i][0] == T_IND)
    //         header->prog_size += 2;
    //     if (&input->data[i][0] == DIRECT_CHAR)
    //         header->prog_size += OP_NAME[i].size;
    // }
}
