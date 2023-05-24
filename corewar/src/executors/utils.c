/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** utils
*/

#include "corewar/corewar.h"

void inc_pc(int *pc, int inc)
{
    *pc = (*pc + inc) % MEM_SIZE;
}
