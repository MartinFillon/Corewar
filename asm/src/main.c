/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <unistd.h>

#include "asm/asm.h"
#include "asm/error.h"

int main(int argc, char **argv)
{
    asm_t assembler = {
        .champ = vec_create(100, sizeof(champ_t)),
        .labels = vec_create(100, sizeof(label_t)),
    };

    if (check_args(argc) == ERROR)
        return ERROR;
    if (launch_parser(&assembler, argv[1]) == ERROR)
        return ERROR;

    return SUCCESS;
}
