/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** utils
*/

#include <limits.h>
#include <stdio.h>

#include "corewar/corewar.h"
#include "corewar/instructions.h"

#include "my_stdio.h"

void inc_pc(int *pc, int inc)
{
    *pc = (*pc + inc) % MEM_SIZE;
}

// void debug_args(argument_t *args)
// {
//     for (int i = 0; i < 4; ++i) {
//         if (args[i].arg_type == 0)
//             break;
//         dprintf(2, "arg[%d] type[%d]: ", i, args[i].arg_type);
//         if (args[i].arg_type == T_REG)
//             dprintf(2, "r%d", args[i].data.reg);
//         else if (args[i].arg_type == 0b11 || (args[i].arg_type == T_DIR &&
//         args[i].is_index)) {
//             dprintf(2, "%hd", args[i].data.ind.ind);
//         }
//         else if (args[i].arg_type == T_DIR) {
//             dprintf(2, "%d", args[i].data.dir);
//         }
//         dprintf(2, "\n");
//     }
// }
