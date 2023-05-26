/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** aff
*/

#include "my_stdio.h"

#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int exec_aff(vm_t *vm, program_t *p)
{
    argument_t *args = (argument_t[4]){0};

    get_arg_types(vm->arena, &p->pc, args);
    for (int i = 0; i < 1; ++i) {
        get_arg(&args[i], vm->arena, &p->pc);
        if (args[i].arg_type == T_REG && (args[i].data.reg == CHAR_MAX))
            return 0;
    }
    my_printf(
        "%c", (char){p->registers[(args[0].data.reg - 1) % REG_NUMBER] % 256}
    );
    return 0;
}
