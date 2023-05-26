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
