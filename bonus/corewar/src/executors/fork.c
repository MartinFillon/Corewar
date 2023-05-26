/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fork
*/

#include "my_stdio.h"
#include "my_stdlib.h"

#include "corewar/corewar.h"
#include "corewar/instructions.h"

int exec_fork(vm_t *vm, program_t *p)
{
    argument_t *args = (argument_t[4]){0};
    int st = p->pc;

    inc_pc(&p->pc, 1);
    args[0].arg_type = T_DIR;
    args[0].is_index = true;
    for (int i = 0; i < 1; ++i) {
        get_arg(&args[i], vm->arena, &p->pc);
    }

    prog_t tmp = dup_program(p);
    my_dprintf(
        2, "{\"action\":\"fork\",\"name\":\"%s\"}\n", p->header.prog_name
    );
    tmp.program.pc = (st + (args[0].data.ind.ind % IDX_MOD)) % MEM_SIZE;
    update_cycle_to_wait(vm, &tmp.program);
    vec_pushback(&vm->programs, &tmp);
    return 0;
}
