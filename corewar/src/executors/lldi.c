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
    arg_types_t reg = {0};
    int arg1 = 0;
    int arg2 = 0;
    int st = p->pc;

    get_arg_types(vm->arena, &p->pc, arg_types);
    arg1 = convert_index_long(arg_types[0], p, st, vm);
    arg2 = convert_index_long(arg_types[1], p, st, vm);
    get_arg(&reg, vm->arena, &p->pc, T_REG);
    if (reg.reg < 1 || reg.reg > REG_NUMBER)
        return 0;

    p->registers[reg.reg - 1] =
        vm->arena[(st + (arg1 + arg2) % IDX_MOD) % MEM_SIZE];
    p->carry = p->registers[reg.reg - 1] == 0;
    return 0;
}
