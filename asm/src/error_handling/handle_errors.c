/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** handle_errors
*/

#include <unistd.h>

#include "my_stdio.h"

#include "asm/asm.h"

void clean_comments_lines(str_t **line)
{
    if (str_find(*line, STR("#"), 0) != -1){
        str_slice(line, 0, str_find(*line, STR("#"), 0));
        str_trim(line, ' ');
        str_trim(line, '\t');
    }
}

void clean_comments(vec_str_t **words)
{
    for (size_t i = 0; i < (*words)->size; i++){
        if ((*words)->data[i]->data[0] == COMMENT_CHAR){
            vec_remove(*words, i);
            i--;
        }
    }
}

int check_args(int argc, char **argv)
{
    if (argc != 2){
        my_dprintf(2, "Usage: ./asm file_name[.s]\n");
        return ERROR;
    }

    if (my_strendwith(argv[1], ".s") == 0){
        my_dprintf(2, "asm: File must be a .s\n");
        return ERROR;
    }
    return SUCCESS;
}
