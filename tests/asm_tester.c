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
#include "asm/body.h"
#include "asm/utils.h"

Test(big_endian, util)
{
    int nbr = 0x12345678;
    swap_endian_int(nbr);
    cr_assert(0x78563412);
}

Test(count_char, util)
{
    str_t *str = str_create("thisismystring");
    str_count(str, 'i');
    cr_assert(3);
}

Test(size_prog_nocb, header)
{
    header_t header = {0};
    str_t *str = str_create("zjmp %:live");
    get_prog_size(str, &header.prog_size);
    cr_assert_eq(header.prog_size, 3);
}

Test(size_prog_lfork, header)
{
    header_t header = {0};
    str_t *str = str_create("lfork %:live");
    get_prog_size(str, &header.prog_size);
    cr_assert_eq(header.prog_size, 3);
}

Test(size_prog_fork, header)
{
    header_t header = {0};
    str_t *str = str_create("fork %:live");
    get_prog_size(str, &header.prog_size);
    cr_assert_eq(header.prog_size, 3);
}

Test(size_prog_ez, header)
{
    header_t header = {0};
    str_t *str = str_create("live %1");
    get_prog_size(str, &header.prog_size);
    cr_assert_eq(header.prog_size, 5);
}

Test(size_prog, header)
{
    header_t header = {0};
    str_t *str = str_create("ld %100, r4");
    get_prog_size(str, &header.prog_size);
    cr_assert_eq(header.prog_size, 7);
}

Test(size_prog_comment, header)
{
    header_t header = {0};
    str_t *str = str_create("ld    %100, r4 #comment");
    get_prog_size(str, &header.prog_size);
    cr_assert_eq(header.prog_size, 7);
}

Test(size_prog_label, header)
{
    header_t header = {0};
    str_t *str = str_create("ok:");
    get_prog_size(str, &header.prog_size);
    cr_assert_eq(header.prog_size, 0);
}

Test(header_wrong_file, errbase)
{
    header_t header = {0};
    parse_header("champions/abel.cor", &header);
    cr_assert(ERROR);
}

Test(wrong_file, errbase)
{
    asm_t champ;
    launch_parser(&champ, "no_file.cor");
    cr_assert(ERROR);
}

Test(direct_index, params)
{
    str_t *buffer = str_create("");
    str_t *expected = str_create("");
    get_direct_int(DIR_SIZE, 3, &buffer);
    str_cadd(&expected, 3 / (65536 * 256));
    str_cadd(&expected, (3 / 65536) % 256);
    str_cadd(&expected, (3 / 256) % 256);
    str_cadd(&expected, 3 / 256);
    cr_assert_str_eq(buffer->data, expected->data);
}

// Test(direct_neg_index, params)
// {
//     int nbr = -3;
//     str_t *buffer = str_create("");
//     str_t *expected = str_create("");
//     get_direct_int(DIR_SIZE, nbr, &buffer);
//     nbr = 4294967296 + nbr;
//     str_cadd(&expected, nbr / (65536 * 256));
//     str_cadd(&expected, (nbr / 65536) % 256);
//     str_cadd(&expected, (nbr / 256) % 256);
//     str_cadd(&expected, nbr / 256);
//     cr_assert_str_eq(buffer->data, expected->data);
// }

Test(indirect_index, params)
{
    str_t *buffer = str_create("");
    str_t *expected = str_create("");
    get_indirect(3, &buffer);
    str_cadd(&expected, (3 / 256));
    str_cadd(&expected, 3 % 256);
    cr_assert_str_eq(buffer->data, expected->data);
}
