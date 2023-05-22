/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sti
*/

#include "corewar/corewar.h"

int exec_sti(vm_t *vm, program_t *p)
{
    u_char *arg_types = (u_char[4]){0};
    int reg = -1;
    int arg1 = 0;
    int arg2 = 0;
    int st = p->pc;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg_types(vm->arena, p->pc, arg_types);
    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&reg, vm->arena, &p->pc, arg_types[0]);
    if (reg == 0)
        return 0;
    get_arg(&arg1, vm->arena, &p->pc, (arg_types[1] == T_REG) ? T_REG : T_IND);
    get_arg(&arg2, vm->arena, &p->pc, (arg_types[2] == T_REG) ? T_REG : T_IND);
    if (arg_types[1] == T_REG)
        arg1 = p->registers[arg1 - 1];
    if (arg_types[2] == T_REG)
        arg2 = p->registers[arg2 - 1];
    vm->arena[(st + (arg1 + arg2) % IDX_MOD) % MEM_SIZE] =
        p->registers[reg - 1];
    return 0;
}
