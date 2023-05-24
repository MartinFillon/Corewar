/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** live
*/

#include "my_stdio.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int exec_live(vm_t *vm, program_t *p)
{
    arg_types_t arg = {0};
    program_t *pl = NULL;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&arg, vm->arena, &p->pc, T_DIR);
    for (size_t i = 0; i < vm->programs->size; i++)
        if (vm->programs->data[i].is_running && vm->programs->data[i].program.registers[0] == arg.dir)
            pl = &vm->programs->data[i].program;
    if (pl == NULL) {
        my_dprintf(1, "player not found, arg: %d\n", arg);
        return 0;
    }
    my_printf("The player %d(%s)is alive.\n", arg, pl->header.prog_name);
    vm->last_live = pl;
    vm->nbr_live++;
    pl->is_alive = true;
    return 0;
}
