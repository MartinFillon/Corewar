/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** run cycles
*/

#include "corewar/arguments.h"
#include "corewar/corewar.h"

void run_cycle(vm_t *vm)
{
    program_t *program = NULL;

    for (size_t i = 0; i < vm->programs->size; ++i) {

        program = &vm->programs->data[i].program;

        // vm->arena[program->pc] -> get instruction
        // execute instruction

        (void)program;
    }
}
