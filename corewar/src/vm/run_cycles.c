/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** run cycles
*/

#include <stdio.h>
#include "corewar/arguments.h"
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
        if (instruction_idx != INVALID_INSTRUCTION)
            program->cycle_to_wait = op_tab[instruction_idx].nbr_cycles;
    }
}

void check_alive(vm_t *vm)
{
    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (vm->programs->data[i].program.is_alive == false) {
            vec_remove(vm->programs, i);
            i--;
        }

        vm->programs->data[i].program.is_alive = false;
    }

    if (vm->nbr_live >= NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->nbr_live = 0;
    }
}

void run_vm(vm_t *vm)
{
    int nb_cycle = 0;

    while (vm->programs->size > 0) {
        if (nb_cycle == vm->nbr_cycles_to_dump) {
            dump_memory(vm);
            return;
        }

        run_cycle(vm);

        if (nb_cycle > 0 && nb_cycle % CYCLE_TO_DIE == 0)
            check_alive(vm);

        nb_cycle++;
    }
}
