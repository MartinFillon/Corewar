/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** zjmp
*/

#include "corewar/corewar.h"
#include "corewar/op.h"

int exec_zjmp(vm_t *vm, program_t *p)
{
    int arg = 0;
    int address = p->pc;

    get_arg(&arg, vm->arena, &p->pc, T_DIR);
    if (p->carry == 1)
        p->pc = (address + (arg % IDX_MOD)) % MEM_SIZE;
    return 0;
}
