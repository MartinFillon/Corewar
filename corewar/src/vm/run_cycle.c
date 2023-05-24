/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** run single cycle
*/

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "corewar/corewar.h"
#include "corewar/op.h"

u_char get_next_instruction(vm_t *vm, program_t *program)
{
    u_char next_instruction_idx = vm->arena[program->pc];

    if (next_instruction_idx < 1 || next_instruction_idx > 16)
        next_instruction_idx = INVALID_INSTRUCTION;

    return next_instruction_idx - 1;
}

void run_cycle(vm_t *vm)
{
    program_t *program = NULL;
    u_char instruction_idx = INVALID_INSTRUCTION;

    for (size_t i = 0; i < vm->programs->size; ++i) {
        program = &vm->programs->data[i].program;

        if (program->cycle_to_wait > 0) {
            program->cycle_to_wait--;
            continue;
        }

        if (instruction_idx != INVALID_INSTRUCTION) {
            op_tab[instruction_idx].func(vm, program);
        }

        instruction_idx = get_next_instruction(vm, program);

        program->cycle_to_wait = op_tab[instruction_idx].nbr_cycles;
    }
}
