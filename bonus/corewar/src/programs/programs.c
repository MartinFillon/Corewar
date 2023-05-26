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
                .is_alive = false,
                .cycle_to_wait = 0,
            },
        .path = NULL,
        .is_running = true,
        .address = -1,
        .number = -1,
    };

    return prog;
}
