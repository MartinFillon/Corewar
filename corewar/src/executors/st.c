/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** st
*/

#include <stdio.h>
#include "my_stdio.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int exec_st(vm_t *vm, program_t *p)
{
    argument_t *args = (argument_t[4]){0};
    ind_state_t ind_state = {vm->arena, p->pc, true};
    int st = p->pc;

    get_arg_types(vm->arena, &p->pc, args);
    for (int i = 0; i < 2; ++i) {
        // dprintf(2, "arg_type: %d\n", args[i].arg_type);
    }
    for (int i = 0; i < 2; ++i) {
        get_arg(&args[i], vm->arena, &p->pc);
        // if (args[i].arg_type == T_REG)
        // dprintf(2, "reg: %d\n", args[i].data.reg);
        if (args[i].arg_type == 0 ||
            (args[i].arg_type == T_REG && (args[i].data.reg == CHAR_MAX)))
            return 0;
    }
    // debug_args(args);
    if (args[1].arg_type == T_REG) {
        p->registers[args[1].data.reg - 1] = get_value(&args[0], p, &ind_state);
    } else {
        write_int(
            vm->arena, (st + get_value(&args[1], p, &ind_state)) % MEM_SIZE,
            get_value(&args[0], p, &ind_state)
        );
    }
    p->carry = get_value(&args[0], p, &ind_state) == 0;
    return 0;
}
