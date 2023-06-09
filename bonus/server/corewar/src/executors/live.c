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

static prog_t *find_program(vm_t *vm, arg_types_t arg)
{
    for (size_t i = 0; i < vm->programs->size; i++)
        if (vm->programs->data[i].address != -1 &&
            vm->programs->data[i].number == arg.dir)
            return &vm->programs->data[i];

    return NULL;
}

int exec_live(vm_t *vm, program_t *p)
{
    argument_t *arg = (argument_t[4]){0};

    inc_pc(&p->pc, 1);
    arg[0].arg_type = T_DIR;
    get_arg(&arg[0], vm->arena, &p->pc);

    prog_t *pl = find_program(vm, arg[0].data);
    if (pl == NULL) {
        return 0;
    }
    my_printf(
        "The player %d(%s)is alive.\n", pl->number, pl->program.header.prog_name
    );
    my_dprintf(2, "{\"action\":\"live\",\"pid\":%d}\n", pl->program.pid);
    vm->last_live = pl;
    vm->nbr_live++;
    pl->program.is_alive = true;
    return 0;
}
