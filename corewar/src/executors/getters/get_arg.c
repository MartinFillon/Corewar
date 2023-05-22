/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_arg
*/

#include "corewar/corewar.h"
#include "corewar/op.h"

int get_arg(int *arg, u_char *memory, int *pc, u_char arg_type)
{
    if (arg_type == 0b10) {
        *arg = get_direct(memory, *pc);
        *pc = (*pc + DIR_SIZE) % MEM_SIZE;
        return 1;
    }
    if (arg_type == 0b11) {
        *arg = get_indirect(memory, *pc);
        *pc = (*pc + IND_SIZE) % MEM_SIZE;
        return 1;
    }
    if (arg_type == 0b01) {
        *arg = memory[*pc] % (REG_NUMBER + 1);
        *pc = (*pc + 1) % MEM_SIZE;
        return 1;
    }
    return 0;
}
