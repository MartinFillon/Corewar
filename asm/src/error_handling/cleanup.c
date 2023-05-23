/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** cleanup
*/

#include "corewar/op.h"
#include "asm/asm.h"

void clean_comments(vec_str_t **words)
{
    for (size_t i = 0; i < (*words)->size; i++){
        if ((*words)->data[i]->data[0] == COMMENT_CHAR){
            vec_remove(*words, i);
            i--;
        }
    }
}
