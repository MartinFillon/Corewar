/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_direct
*/

#include "my_stdlib.h"

#include "corewar/op.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"

arg_types_t get_dir(u_char *memory, int *pc)
{
    arg_types_t arg = {0};

    arg.dir = 0;
    if (*pc + DIR_SIZE < MEM_SIZE) {
        my_memcpy(&arg.dir, &memory[*pc % MEM_SIZE], DIR_SIZE);
    }
    arg.dir = swap_endian(arg.dir);
    inc_pc(pc, DIR_SIZE);
    return arg;
}
