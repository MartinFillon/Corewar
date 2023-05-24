/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sub
*/

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"

int exec_sub(vm_t *vm, program_t *p)
{
    arg_types_t reg1 = {0};
    arg_types_t reg2 = {0};
    arg_types_t reg3 = {0};

    p->pc = (p->pc + 2) % MEM_SIZE;
    get_arg(&reg1, vm->arena, &p->pc, T_REG);
    get_arg(&reg2, vm->arena, &p->pc, T_REG);
    get_arg(&reg3, vm->arena, &p->pc, T_REG);

    p->registers[reg3.reg - 1] =
        p->registers[reg1.reg - 1] - p->registers[reg2.reg - 1];
    p->carry = p->registers[reg3.reg - 1] == 0;
    return 0;
}
