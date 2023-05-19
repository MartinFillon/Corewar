/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** handle_errors
*/

#include <unistd.h>

#include "my_stdio.h"

#include "asm/asm.h"

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
