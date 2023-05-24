/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sti
*/

#include "corewar/corewar.h"
#include "corewar/instructions.h"

int exec_sti(vm_t *vm, program_t *p)
{
    u_char *arg_types = (u_char[4]){0};
    arg_types_t reg = {0};
    arg_types_t arg1 = {0};
    arg_types_t arg2 = {0};
    int st = p->pc;
    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg_types(vm->arena, p->pc, arg_types);
    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&reg, vm->arena, &p->pc, arg_types[0]);
    arg1.dir = convert_index(arg_types[1], p, st, vm);
    arg2.dir = convert_index(arg_types[2], p, st, vm);
    write_int(
        vm->arena, (st + (arg1.dir + arg2.dir) % IDX_MOD) % MEM_SIZE,
        swap_endian(p->registers[reg.reg - 1])
    );
    return 0;
}
