/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** program
*/

#include "my_stdlib.h"

#include "corewar/corewar.h"
#include "corewar/op.h"

prog_t init_prog(void)
{
    prog_t prog = {
        .address = -1,
        .number = -1,
        .path = NULL,
        .is_running = true,
        .program =
            {
                .header = {0},
                .body = NULL,
                .registers = {0},
                .pc = 0,
                .carry = false,
                .is_alive = false,
                .cycle_to_wait = 0,
                .pid = -1,
            },
    };

    return prog;
}

prog_t dup_program(program_t *p)
{
    prog_t tmp = {
        .address = -1,
        .number = -1,
        .path = NULL,
        .is_running = true,
        .program =
            {
                .header = p->header,
                .body = NULL,
                .registers = {0},
                .pc = -1,
                .carry = p->carry,
                .is_alive = p->is_alive,
                .cycle_to_wait = p->cycle_to_wait,
                .pid = p->pid,
            },
    };
    my_memcpy(&tmp.program.registers, &p->registers, sizeof(p->registers));

    return tmp;
}
