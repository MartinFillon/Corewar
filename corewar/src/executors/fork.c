/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fork
*/

#include "my_stdlib.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int exec_fork(vm_t *vm, program_t *p)
{
    int st = p->pc;
    arg_types_t arg = {0};

    inc_pc(&p->pc, 1);
    get_arg(&arg, vm->arena, &p->pc, 0b11);

    prog_t tmp = dup_program(p);
    tmp.program.pc = (st + (arg.ind % IDX_MOD)) % MEM_SIZE;
    my_memcpy(tmp.program.registers, p->registers, sizeof(p->registers));
    update_cycle_to_wait(vm, &tmp.program);
    vec_pushback(&vm->programs, &tmp);
    return 0;
}
