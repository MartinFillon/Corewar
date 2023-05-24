/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lld
*/

#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int exec_lld(vm_t *vm, program_t *p)
{
    arg_types_t arg = {0};
    arg_types_t reg = {0};
    u_char *arg_types = (u_char[4]){0};
    int st = p->pc;

    get_arg_types(vm->arena, &p->pc, arg_types);
    get_arg(&arg, vm->arena, &p->pc, arg_types[0]);
    get_arg(&reg, vm->arena, &p->pc, T_REG);
    if (reg.reg < 1 || reg.reg > REG_NUMBER)
        return 0;
    p->registers[reg.reg - 1] = (arg_types[0] == T_DIR)
        ? arg.dir
        : vm->arena[(st + arg.ind) % MEM_SIZE];
    p->carry = p->registers[reg.reg - 1] == 0;
    return 0;
}
