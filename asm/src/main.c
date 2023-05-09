/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <unistd.h>

#include "asm/asm.h"

int main(int argc, char **argv)
{
    header_t header;

    if (check_args(argc) == ERROR)
        return ERROR;
    if (launch_parser(&header, argv[1]) == ERROR)
        return ERROR;

    return SUCCESS;
}
