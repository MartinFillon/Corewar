/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** exec_lldi
*/

#include "corewar/corewar.h"
#include "corewar/instructions.h"

int exec_lldi(vm_t *vm, program_t *p)
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
    arg1 = convert_index_long(arg_types[0], p, st, vm);
    arg2 = convert_index_long(arg_types[1], p, st, vm);
    get_arg(&reg, vm->arena, &p->pc, arg_types[2]);
    address = (arg1 + arg2);
    p->registers[reg - 1] = vm->arena[(st + address) % MEM_SIZE];
    p->carry = p->registers[reg - 1] == 0;
    return 0;
}
