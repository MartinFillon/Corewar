/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** live
*/

#include "my_stdio.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/op.h"

int exec_live(vm_t *vm, program_t *p)
{
    int arg = get_direct(vm->arena, p->pc + 1);

    my_printf("The player %d(%s) is alive.\n", arg, p->header.prog_name);
    vm->last_live = p;
    vm->nbr_live++;
    p->is_alive = true;
    p->pc = (p->pc + 2) % MEM_SIZE;
    return 0;
}
