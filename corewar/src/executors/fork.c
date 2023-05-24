/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fork
*/

#include "my_stdlib.h"

#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int exec_fork(vm_t *vm, program_t *p)
{
    int st = p->pc;
    arg_types_t arg = {0};
    program_t tmp;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&arg, vm->arena, &p->pc, 0b11);
    tmp = (program_t){
        .body = NULL,
        .carry = p->carry,
        .cycle_to_wait = p->cycle_to_wait,
        .is_alive = p->is_alive,
        .pc = ((st + (arg.ind % IDX_MOD)) % MEM_SIZE),
        .header = p->header,
    };
    my_memcpy(tmp.registers, p->registers, sizeof(p->registers));
    vec_pushback(&vm->programs, &tmp);
    return 0;
}
