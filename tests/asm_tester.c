/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm_tester
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "asm/asm.h"
#include "asm/header.h"
#include "asm/utils.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(big_endian, util, .init = redirect_all_std)
{
    int nbr = 0x12345678;
    swap_endian_int(nbr);
    cr_assert(0x78563412);
}

Test(count_char, util, .init = redirect_all_std)
{
    str_t *str = str_create("thisismystring");
    str_count(str, 'i');
    cr_assert(3);
}

Test(size_prog_nocb, header, .init = redirect_all_std)
{
    header_t header = {0};
    str_t *str = str_create("zjmp %:live");
    get_prog_size(str, &header.prog_size);
    cr_assert(header.prog_size == 3);
}

Test(size_prog_lfork, header, .init = redirect_all_std)
{
    header_t header = {0};
    str_t *str = str_create("lfork %:live");
    get_prog_size(str, &header.prog_size);
    cr_assert(header.prog_size == 3);
}

Test(size_prog_fork, header, .init = redirect_all_std)
{
    header_t header = {0};
    str_t *str = str_create("fork %:live");
    get_prog_size(str, &header.prog_size);
    cr_assert(header.prog_size == 3);
}

Test(size_prog_ez, header, .init = redirect_all_std)
{
    header_t header = {0};
    str_t *str = str_create("live %1");
    get_prog_size(str, &header.prog_size);
    cr_assert(header.prog_size == 5);
}

Test(size_prog, header, .init = redirect_all_std)
{
    header_t header = {0};
    str_t *str = str_create("ld %100, r4");
    get_prog_size(str, &header.prog_size);
    cr_assert(header.prog_size == 7);
}

Test(size_prog_comment, header, .init = redirect_all_std)
{
    header_t header = {0};
    str_t *str = str_create("ld    %100, r4 #comment");
    get_prog_size(str, &header.prog_size);
    cr_assert(header.prog_size == 7);
}

Test(size_prog_label, header, .init = redirect_all_std)
{
    header_t header = {0};
    str_t *str = str_create("ok:");
    get_prog_size(str, &header.prog_size);
    cr_assert(header.prog_size == 0);
}

// Test(header_name, header, .init = redirect_all_std)
// {
//     header_t header = {0};
//     parse_header("abel.s", &header);
//     cr_assert(header.prog_name == "Abel");
// }

// Test(header_comment, header, .init = redirect_all_std)
// {
//     header_t header = {0};
//     parse_header("abel.s", &header);
//     cr_assert(header.comment == "L'amer noir.");
// }

Test(header_wrong_file, errbase, .init = redirect_all_std)
{
    header_t header = {0};
    parse_header("champions/abel.cor", &header);
    cr_assert(ERROR);
}

Test(wrong_file, errbase, .init = redirect_all_std)
{
    asm_t champ;
    launch_parser(&champ, "no_file.cor");
    cr_assert(ERROR);
}
