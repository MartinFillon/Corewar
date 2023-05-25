/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** zjmp
*/

#include "my_stdio.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int exec_zjmp(vm_t *vm, program_t *p)
{
    argument_t *arg = (argument_t[4]){0};
    int address = p->pc;

    inc_pc(&p->pc, 1);
    arg[0].arg_type = T_DIR;
    arg[0].is_index = true;
    get_arg(&arg[0], vm->arena, &p->pc);
    my_dprintf(2, "ZJMP: %d\n", p->carry);
    if (p->carry == 1)
        p->pc = (address + (arg[0].data.ind.ind % IDX_MOD)) % MEM_SIZE;
    return 0;
}
