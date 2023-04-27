/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parser
*/

#include "my_str.h"
#include "my_stdio.h"

#include "corewar/corewar.h"
#include "corewar/op.h"

static int error_from_path(int ac)
{
    if (ac != 2)
        return ERROR;
    return SUCESS;
}

static str_t *parse_header(char *champ_path)
{
    str_t *content = read_file(champ_path);
    if (content == NULL)
        return NULL;
    return content;
}

void launch_parser(int ac, char **argv)
{
    //header_t header = {0};
    str_t *champ = NULL;

    if (error_from_path(ac) == ERROR ||
    (champ = parse_header(argv[1])) == NULL)
        return;
    my_printf("%s\n", champ->data);
}
