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
    arg_types_t reg = {0};
    arg_types_t arg1 = {0};
    arg_types_t arg2 = {0};
    int st = p->pc;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg_types(vm->arena, p->pc, arg_types);
    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&arg1, vm->arena, &p->pc, arg_types[0]);
    get_arg(&arg2, vm->arena, &p->pc, arg_types[1]);
    get_arg(&reg, vm->arena, &p->pc, arg_types[2]);
    interpret_binary(&arg1, arg_types[0], vm, st);
    interpret_binary(&arg2, arg_types[1], vm, st);
    if (arg_types[0] == T_REG)
        arg1.dir = p->registers[arg1.reg - 1];
    if (arg_types[1] == T_REG)
        arg2.dir = p->registers[arg2.reg - 1];
    p->carry = (p->registers[reg.reg - 1] = arg1.dir ^ arg2.dir) == 0;
    return 0;
}
