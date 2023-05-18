/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** program
*/

#include "corewar/corewar.h"

prog_t init_prog(void)
{
    prog_t prog = {
        .program =
            {
                .body = NULL,
                .carry = false,
                .header = {0},
                .registers = {0},
                .pc = 0,
            },
        .address = -1,
        .number = -1,
    };

    return prog;
}
