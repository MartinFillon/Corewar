/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** run single cycle
*/

#include <stdio.h>
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

static void update_cycle_to_wait(vm_t *vm, program_t *program)
{
    u_char instruction_idx = get_instruction(vm, program);

    if (instruction_idx != INVALID_INSTRUCTION) {
        program->cycle_to_wait = op_tab[instruction_idx].nbr_cycles;
    }
}

void run_cycle(vm_t *vm)
{
    static bool first_call = true;

    for (size_t i = 0; i < vm->programs->size; ++i) {
        program_t *program = &vm->programs->data[i].program;

        if (program->cycle_to_wait > 0) {
            program->cycle_to_wait--;
            continue;
        }

        u_char instruction_idx = get_instruction(vm, program);
        if (first_call) {
            update_cycle_to_wait(vm, program);
            program->cycle_to_wait--;
            continue;
        }
        if (instruction_idx != INVALID_INSTRUCTION) {
            my_dprintf(2,
                "executing: %d, %s, prog_id: %d\n", instruction_idx + 1,
                op_tab[instruction_idx].mnemonique, i
            );
            my_dprintf(2,"old pc: %d\n", program->pc);

            op_tab[instruction_idx].func(vm, program);

            my_dprintf(2,
                "new pc: %d, %d\n\n\n", program->pc, vm->arena[program->pc]
            );

            update_cycle_to_wait(vm, program);

            my_dprintf(2,"cycle_to_wait: %d\n", program->cycle_to_wait);
        }
    }
    first_call = false;
}
