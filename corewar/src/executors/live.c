/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** live
*/

#include <stdio.h>

#include "my_stdio.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

static program_t *find_program(vm_t *vm, arg_types_t arg)
{
    for (size_t i = 0; i < vm->programs->size; i++)
        if (vm->programs->data[i].is_running &&
            vm->programs->data[i].program.registers[0] == arg.dir)
            return &vm->programs->data[i].program;

    return NULL;
}

int exec_live(vm_t *vm, program_t *p)
{
    argument_t *arg = (argument_t[4]){0};

    my_dprintf(2, "exec live as %s\n", p->header.prog_name);

    inc_pc(&p->pc, 1);
    arg[0].arg_type = T_DIR;
    get_arg(&arg[0], vm->arena, &p->pc);

    program_t *pl = find_program(vm, arg[0].data);
    my_dprintf(2, "arg = %d\n", arg[0].data.dir);
    if (pl == NULL)
        return 0;
    my_printf("The player %d(%s)is alive.\n", arg[0].data.dir, pl->header.prog_name);
    vm->last_live = pl;
    vm->nbr_live++;
    pl->is_alive = true;
    return 0;
}
