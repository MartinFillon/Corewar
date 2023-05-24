/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** live
*/

#include <stddef.h>
#include "my_stdio.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/op.h"

int exec_live(vm_t *vm, program_t *p)
{
    int arg = 0;
    prog_t *pl = NULL;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&arg, vm->arena, &p->pc, T_DIR);
    for (size_t i = 0; i < vm->programs->size; i++)
        if (vm->programs->data[i].number == arg)
            pl = &vm->programs->data[i];
    if (pl == NULL)
        return 0;
    my_printf(
        "The player %d(%s) is alive.\n", arg, pl->program.header.prog_name
    );
    vm->last_live = &pl->program;
    vm->nbr_live++;
    p->is_alive = true;
    return 0;
}
