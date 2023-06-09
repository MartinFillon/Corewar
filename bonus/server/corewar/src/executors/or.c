/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** or
*/

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"

int exec_or(vm_t *vm, program_t *p)
{
    argument_t *args = (argument_t[4]){0};
    ind_state_t ind_state = {vm->arena, p->pc, true};

    get_arg_types(vm->arena, &p->pc, args);
    for (int i = 0; i < 3; ++i) {
        get_arg(&args[i], vm->arena, &p->pc);
        if (args[i].arg_type == 0 ||
            (args[i].arg_type == T_REG && (args[i].data.reg == CHAR_MAX)))
            return 0;
    }
    p->registers[args[2].data.reg - 1] =
        get_value(&args[0], p, &ind_state) | get_value(&args[1], p, &ind_state);
    p->carry = p->registers[args[2].data.reg - 1] == 0;
    return 0;
}
