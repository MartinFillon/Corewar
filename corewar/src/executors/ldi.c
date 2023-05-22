/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ldi
*/

#include "corewar/corewar.h"

int exec_ldi(vm_t *vm, program_t *p)
{
    u_char *arg_types = (u_char[4]){0};
    int reg = -1;
    int arg1 = 0;
    int arg2 = 0;
    int st = p->pc;
    int address = 0;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg_types(vm->arena, p->pc, arg_types);
    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&arg1, vm->arena, &p->pc, arg_types[0]);
    get_arg(&arg2, vm->arena, &p->pc, arg_types[1]);
    get_arg(&reg, vm->arena, &p->pc, arg_types[2]);
    if (reg == 0)
        return 0;
    address = ((arg1 + arg2) % IDX_MOD) % MEM_SIZE;
    p->registers[reg - 1] = get_direct(vm->arena, st + address);
    return 0;
}
