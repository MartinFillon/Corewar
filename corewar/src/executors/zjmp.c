/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** zjmp
*/

#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int exec_zjmp(vm_t *vm, program_t *p)
{
    arg_types_t arg = {0};
    int address = p->pc;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&arg, vm->arena, &p->pc, 0b11);
    if (p->carry == 1)
        p->pc = (address + (arg.ind % IDX_MOD)) % MEM_SIZE;
    return 0;
}
