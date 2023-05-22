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

int exec_st(vm_t *vm, program_t *p)
{
    u_char *arg_types = (u_char[4]){0};
    int reg = -1;
    int arg1 = 0;

    get_arg_types(vm->arena, p->pc + 1, arg_types);
    reg = vm->arena[p->pc + 2];
    if (arg_types[1] == T_IND) {
        arg1 = get_indirect(vm->arena, p->pc + 3, p->pc);
        write_int(
            vm->arena, (p->pc + arg1 % IDX_MOD) % MEM_SIZE,
            p->registers[reg - 1]
        );
    } else if (arg_types[1] == T_REG) {
        arg1 = vm->arena[p->pc + 3];
        p->registers[arg1 - 1] = p->registers[reg - 1];
    }
    p->pc = (p->pc + 4) % MEM_SIZE;
    return 0;
}
