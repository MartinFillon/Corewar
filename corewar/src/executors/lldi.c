/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** exec_lldi
*/

#include "corewar/instructions.h"

int exec_lldi(vm_t *vm, program_t *p)
{
    int arg1 = 0;
    int arg2 = 0;
    int reg = 0;
    int st = p->pc;
    u_char *arg_types = (u_char[4]){0};

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg_types(vm->arena, p->pc, arg_types);
    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&arg1, vm->arena, &p->pc, arg_types[0]);
    get_arg(&arg2, vm->arena, &p->pc, arg_types[1]);
    get_arg(&reg, vm->arena, &p->pc, arg_types[2]);
    if (reg == 0)
        return 0;
    p->registers[reg - 1] = get_direct(vm->arena, st + (arg1 + arg2));
    return 0;
}
