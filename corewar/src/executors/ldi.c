/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ldi
*/

#include "corewar/corewar.h"
#include "corewar/op.h"

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
    get_arg(&arg1, vm->arena, &p->pc, (arg_types[1] == T_REG) ? T_REG : T_IND);
    get_arg(&arg2, vm->arena, &p->pc, (arg_types[1] == T_REG) ? T_REG : T_IND);
    get_arg(&reg, vm->arena, &p->pc, arg_types[2]);
    if (reg == 0)
        return 0;
    address = (arg1 + arg2 % IDX_MOD);
    p->registers[reg - 1] = vm->arena[(st + address) % MEM_SIZE];
    p->carry = p->registers[reg - 1] == 0;
    return 0;
}
