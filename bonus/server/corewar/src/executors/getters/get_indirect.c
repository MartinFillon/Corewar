/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_indirect
*/

#include "my_stdlib.h"

#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

arg_types_t get_ind(u_char *memory, int *pc)
{
    arg_types_t arg = {0};

    arg.ind.ind = 0;
    if (*pc + IND_SIZE < MEM_SIZE) {
        my_memcpy(&arg.ind.ind, &memory[*pc % MEM_SIZE], IND_SIZE);
    }
    inc_pc(pc, IND_SIZE);
    arg.ind.ind = swap_endian_short(arg.ind.ind);
    return arg;
}
