/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** handle_errors
*/

#include <unistd.h>

#include "my_stdio.h"

#include "asm/asm.h"

int check_args(int argc)
{
    if (argc != 2){
        my_dprintf(2, "Usage: ./asm file_name[.s]\n");
        return ERROR;
    }

    return SUCCESS;
}
