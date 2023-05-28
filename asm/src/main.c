/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>

#include "asm/asm.h"
#include "asm/error.h"

static void free_champ(asm_t *champ)
{
    for (size_t i = 0; i < champ->labels->size; i++){
        free(champ->labels->data[i].label);
    }
    free(champ->labels);
    for (size_t i = 0; i < champ->champ->size; i++){
        vec_free(champ->champ->data[i].params);
    }
    free(champ->champ);
}

int main(int argc, char **argv)
{
    asm_t assembler = {
        .champ = vec_create(100, sizeof(champ_t)),
        .labels = vec_create(100, sizeof(label_t)),
    };

    if (check_args(argc, argv) == ERROR){
        free_champ(&assembler);
        return ERROR;
    }
    assembler.filepath = argv[1];
    if (launch_parser(&assembler, argv[1]) == ERROR){
        free_champ(&assembler);
        return ERROR;
    }
    fclose(assembler.file);
    free_champ(&assembler);
    return SUCCESS;
}
