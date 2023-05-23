/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions_tester
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <stdio.h>

#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"
#include "my_vec.h"

void end(void)
{
    fflush(stderr);
    fflush(stdout);
}

Test(instruction_tester, add, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test1.cor", "tests/test2.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    vm.programs->data[0].program.registers[0] = 1;
    vm.programs->data[0].program.registers[1] = 2;
    exec_add(&vm, &vm.programs->data[0].program);
    cr_assert_eq(vm.programs->data[0].program.registers[2], 3);
    free_vm(&vm);
}

Test(instruction_tester, add_and_other_command_after, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test2.cor", "tests/test1.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    p->registers[0] = 1;
    p->registers[1] = 2;
    exec_add(&vm, p);
    cr_assert_eq(p->registers[2], 3);
    u_char next = get_next_instruction(&vm, p);
    cr_assert_eq(next, 4);
    op_tab[next].func(&vm, p);
    cr_assert_eq(p->registers[2], p->registers[1] - p->registers[0]);
    free_vm(&vm);
}

Test(instruction_tester, sub, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test3.cor", "tests/test2.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    p->registers[0] = 1;
    p->registers[1] = 2;
    exec_sub(&vm, &vm.programs->data[0].program);
    cr_assert_eq(p->registers[2], p->registers[1] - p->registers[0]);
    free_vm(&vm);
}

Test(instruction_tester, sub_and_other_command_after, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test3.cor", "tests/test1.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    p->registers[0] = 1;
    p->registers[1] = 2;
    exec_sub(&vm, p);
    cr_assert_eq(p->registers[2], p->registers[1] - p->registers[0]);
    u_char next = get_next_instruction(&vm, p);
    cr_assert_neq(next, INVALID_INSTRUCTION);
    op_tab[next].func(&vm, p);
    cr_assert_eq(p->registers[2], p->registers[1] + p->registers[0]);
    free_vm(&vm);
}

Test(instruction_tester, ld_direct, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test4.cor", "tests/test1.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    exec_ld(&vm, p);
    cr_assert_eq(p->registers[5], 34);
    free_vm(&vm);
}

Test(instruction_tester, ld_indirect, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test5.cor", "tests/test1.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    vm.arena[(p->pc + 34 % IDX_MOD) % MEM_SIZE] = 'a';
    exec_ld(&vm, p);
    cr_assert_eq(p->registers[5], 'a');
    free_vm(&vm);
}

Test(instruction_tester, ld_indirect_after, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test5.cor", "tests/test1.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    vm.arena[(p->pc + 34 % IDX_MOD) % MEM_SIZE] = 'a';
    exec_ld(&vm, p);
    cr_assert_eq(p->registers[5], 'a');
    p->registers[0] = 1;
    p->registers[1] = 2;
    u_char next = get_next_instruction(&vm, p);
    cr_assert_eq(next, 4);
    op_tab[next].func(&vm, p);
    cr_assert_eq(p->registers[2], p->registers[1] - p->registers[0]);
    free_vm(&vm);
}

Test(instruction_tester, ld_direct_after, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test5.cor", "tests/test1.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    vm.arena[(p->pc + 34 % IDX_MOD) % MEM_SIZE] = 'a';
    exec_ld(&vm, p);
    cr_assert_eq(p->registers[5], 'a');
    p->registers[0] = 1;
    p->registers[1] = 2;
    u_char next = get_next_instruction(&vm, p);
    cr_assert_eq(next, 4);
    op_tab[next].func(&vm, p);
    cr_assert_eq(p->registers[2], p->registers[1] - p->registers[0]);
    free_vm(&vm);
}

Test(instruction_tester, live, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test6.cor", "tests/test1.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    exec_live(&vm, p);
    cr_assert_not_null(vm.last_live);
}

Test(instruction_tester, live_after, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test6.cor", "tests/test1.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    exec_live(&vm, p);
    cr_assert_not_null(vm.last_live);
    p->registers[0] = 1;
    p->registers[1] = 2;
    u_char next = get_next_instruction(&vm, p);
    cr_assert_eq(next, 3);
    op_tab[next].func(&vm, p);
    cr_assert_eq(p->registers[2], p->registers[1] + p->registers[0]);
    free_vm(&vm);
}

Test(instruction_tester, st_reg, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test7.cor", "tests/test1.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    p->registers[5] = 78;
    exec_st(&vm, p);
    cr_assert_eq(p->registers[1], p->registers[5]);
    p->registers[0] = 1;
    u_char next = get_next_instruction(&vm, p);
    cr_assert_eq(next, 3);
    op_tab[next].func(&vm, p);
    cr_assert_eq(p->registers[2], p->registers[1] + p->registers[0]);
    free_vm(&vm);
}

Test(instruction_tester, st_ind, .fini=end)
{
    vm_t vm = init_vm();
    char *av[] = {"./corewar", "tests/test8.cor", "tests/test1.cor", NULL};
    if (!parse_argv(3, (const char *const *)av, &vm) || !start_vm(&vm))
        cr_assert_fail();
    program_t *p = &vm.programs->data[0].program;
    int address = p->pc + 10 % IDX_MOD;
    p->registers[5] = 78;
    exec_st(&vm, p);
    cr_assert_eq(vm.arena[address % MEM_SIZE], p->registers[5]);
    p->registers[0] = 1;
    p->registers[1] = 2;
    u_char next = get_next_instruction(&vm, p);
    cr_assert_eq(next, 3);
    op_tab[next].func(&vm, p);
    cr_assert_eq(p->registers[2], p->registers[1] + p->registers[0]);
    free_vm(&vm);
}
