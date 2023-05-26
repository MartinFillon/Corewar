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

u_char get_instruction(vm_t *vm, program_t *program)
{
    u_char next_instruction_idx = vm->arena[program->pc % MEM_SIZE];

    if (next_instruction_idx < 1 || next_instruction_idx > 16)
        return INVALID_INSTRUCTION;

    return next_instruction_idx - 1;
}

void update_cycle_to_wait(vm_t *vm, program_t *program)
{
    u_char instruction_idx = get_instruction(vm, program);

    if (instruction_idx != INVALID_INSTRUCTION) {
        program->cycle_to_wait = op_tab[instruction_idx].nbr_cycles;
    }
}

void run_cycle(vm_t *vm)
{
    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (vm->programs->data[i].is_running == false)
            continue;

        program_t *program = &vm->programs->data[i].program;

        if (program->cycle_to_wait > 1) {
            program->cycle_to_wait--;
            continue;
        }

        u_char instruction_idx = get_instruction(vm, program);

        if (instruction_idx != INVALID_INSTRUCTION) {
            op_tab[instruction_idx].func(vm, program);
            update_cycle_to_wait(vm, program);
        } else {
            inc_pc(&program->pc, 1);
        }
    }
}
