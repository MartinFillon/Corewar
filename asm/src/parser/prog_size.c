/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** prog_size
*/

#include "corewar/op.h"
#include "my_str.h"


void get_size(champ_t *champ, header_t *header, size_t i)
{
    size_t x = 0;

    for (x = 0; my_strcmp(DIR_TAB[x].name, champ[i].cmd[0]) != 0; ++x);
    if (my_strcmp(op_tab[x].mnemonique, "live") != 0 &&
    my_strcmp(op_tab[x].mnemonique, "lfork") != 0 &&
    my_strcmp(op_tab[x].mnemonique, "zjmp") != 0){
        header->prog_size += 2;
    } else {
        header->prog_size += 1;
    }
    for (int j = 1; champ[i].cmd[j]; j++){
        if (champ[i].type[j - 1] == T_REG)
            header->prog_size += 1;
        if (champ[i].type[j - 1] == T_IND)
            header->prog_size += 2;
        if (champ[i].type[j - 1] == T_DIR)
            header->prog_size += DIR_TAB[x].size;
    }
}
