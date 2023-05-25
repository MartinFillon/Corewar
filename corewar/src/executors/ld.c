/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ld
*/

#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

#include "my_stdio.h"
#include "my_stdlib.h"

int exec_ld(vm_t *vm, program_t *p)
{
    argument_t *args = (argument_t[4]){0};
    ind_state_t ind_state = {vm->arena, p->pc, true};
    int st = p->pc;

    get_arg_types(vm->arena, &p->pc, args);
    for (int i = 0; i < 2; ++i) {
        get_arg(&args[i], vm->arena, &p->pc);
        if (args[i].arg_type == T_REG && (args[i].data.reg == -1))
            return 0;
    }
    if (args[0].arg_type == T_REG || args[0].arg_type == T_DIR)
        p->registers[args[1].data.reg - 1] = get_value(&args[0], p, &ind_state);
    if (args[0].arg_type == T_IND)
        p->registers[args[1].data.reg - 1] = read_int(
            vm->arena, (st + get_value(&args[0], p, &ind_state)) % MEM_SIZE
        );
    my_dprintf(2, "LD: %d\n", p->registers[args[1].data.reg - 1]);
    p->carry = p->registers[args[1].data.reg - 1] == 0;
    return 0;
}
