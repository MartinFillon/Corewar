/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ldi
*/

#include <sys/types.h>
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int exec_ldi(vm_t *vm, program_t *p)
{
    argument_t *args = (argument_t[4]){0};
    ind_state_t ind_state = {vm->arena, p->pc, true};
    int st = p->pc;

    get_arg_types(vm->arena, &p->pc, args);
    args[0].is_index = true;
    args[1].is_index = true;
    for (int i = 0; i < 2; ++i) {
        get_arg(&args[i], vm->arena, &p->pc);
        if (args[i].arg_type == 0 ||
            (args[i].arg_type == T_REG && (args[i].data.reg == CHAR_MAX)))
            return 0;
    }
    // debug_args(args);
    p->registers[args[1].data.reg - 1] = read_int(
        vm->arena,
        (st +
         (get_value(&args[0], p, &ind_state) +
          get_value(&args[1], p, &ind_state)) %
             IDX_MOD) %
            MEM_SIZE
    );
    return 0;
}
