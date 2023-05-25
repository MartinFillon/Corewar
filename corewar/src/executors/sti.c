/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sti
*/

#include <stdbool.h>
#include <stdio.h>
#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

#include "my_stdio.h"
#include "my_stdlib.h"

int exec_sti(vm_t *vm, program_t *p)
{
    argument_t *args = (argument_t[4]){0};
    ind_state_t ind_state = {vm->arena, p->pc, true};
    int st = p->pc;

    get_arg_types(vm->arena, &p->pc, args);
    args[1].is_index = true;
    args[2].is_index = true;
    for (int i = 0; i < 3; ++i) {
        my_dprintf(2, "type[%d] = %d\n", i, args[i].arg_type);
        get_arg(&args[i], vm->arena, &p->pc);
        if (args[i].arg_type == T_REG && (args[i].data.reg == -1))
            return 0;
    }
    write_int(
        vm->arena,
        (st + (get_value(&args[1], p, &ind_state) + get_value(&args[2], p, &ind_state) % IDX_MOD)) %
            MEM_SIZE,
        swap_endian(get_value(&args[0], p, &ind_state))
    );
    return 0;
}
