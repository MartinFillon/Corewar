/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** xor
*/

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"

int exec_xor(vm_t *vm, program_t *p)
{
    u_char *arg_types = (u_char[4]){0};
    int st = p->pc;
    arg_types_t reg = {0}, arg1 = {0}, arg2 = {0};

    get_arg_types(vm->arena, &p->pc, arg_types);
    get_arg(&arg1, vm->arena, &p->pc, arg_types[0]);
    get_arg(&arg2, vm->arena, &p->pc, arg_types[1]);
    get_arg(&reg, vm->arena, &p->pc, T_REG);

    if (arg_types[0] == 0b11)
        arg1.dir = vm->arena[(st + arg1.ind % IDX_MOD) % MEM_SIZE];
    if (arg_types[1] == 0b11)
        arg2.dir = vm->arena[(st + arg2.ind % IDX_MOD) % MEM_SIZE];

    if (arg_types[0] == T_REG) {
        if (arg1.reg > 0 && arg1.reg < REG_NUMBER)
            return 0;
        arg1.dir = p->registers[arg1.reg - 1];
    }
    if (arg_types[1] == T_REG) {
        if (arg2.reg > 0 && arg2.reg < REG_NUMBER)
            return 0;
        arg2.dir = p->registers[arg2.reg - 1];
    }

    p->registers[reg.reg - 1] = arg1.dir ^ arg2.dir;
    p->carry = (p->registers[reg.reg - 1] == 0);
    return 0;
}
