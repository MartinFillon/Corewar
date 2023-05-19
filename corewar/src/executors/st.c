/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** st
*/

#include <sys/types.h>

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/op.h"

int exec_st(program_t *p, char *memory, int *pc)
{
    u_char *arg_types = (u_char[4]){0};
    int reg = -1;
    int arg1 = 0;

    get_arg_types(memory, *pc + 1, arg_types);
    reg = memory[*pc + 2];
    if (arg_types[1] == T_IND) {
        arg1 = get_indirect(memory, *pc + 3, *pc);
        write_int(
            memory, (*pc + arg1 % IDX_MOD) % MEM_SIZE, p->registers[reg - 1]
        );
    } else if (arg_types[1] == T_REG) {
        arg1 = memory[*pc + 3];
        p->registers[arg1 - 1] = p->registers[reg - 1];
    }
    *pc += 4;
    return 0;
}
