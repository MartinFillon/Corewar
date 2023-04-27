/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parser
*/

#include "my_cstr.h"
#include "my_stdio.h"
#include "my_str.h"

#include "corewar/corewar.h"
#include "corewar/op.h"

static int error_from_path(int ac)
{
    if (ac != 2)
        return ERROR;
    return SUCESS;
}

static void fill_struct(vec_str_t *champ, header_t *header)
{
    for (size_t i = 0; i < champ->size; ++i) {
        if (str_startswith(champ->data[i], STR(".name"))) {
            my_strcpy(header->prog_name, champ->data[i]->data + 7);
        }
        if (str_startswith(champ->data[i], STR(".comment"))) {
            my_strcpy(header->comment, champ->data[i]->data + 10);
        }
    }
    for (int i = 0; header->prog_name[i] != '\0'; i++)
        if (header->prog_name[i] == '"')
            header->prog_name[i] = '\0';
    for (int i = 0; header->comment[i] != '\0'; i++)
        if (header->comment[i] == '"')
            header->comment[i] = '\0';

    my_printf("[%s]\n", header->prog_name);
    my_printf("[%s]\n", header->comment);
}

static str_t *parse_header(char *champ_path, header_t *header)
{
    str_t *content = read_file(champ_path);

    if (content == NULL)
        return NULL;
    vec_str_t *champ = str_split(content, STR("\n"));
    for (size_t i = 0; i < champ->size; i++) {
        str_ltrim(&champ->data[i], '\t');
    }
    fill_struct(champ, header);
    return content;
}

void launch_parser(int ac, char **argv)
{
    header_t header = {0};
    str_t *champ = NULL;

    if (error_from_path(ac) == ERROR ||
        (champ = parse_header(argv[1], &header)) == NULL)
        return;
}
