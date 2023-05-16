/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <unistd.h>

#include "asm/asm.h"
#include "asm/error.h"

int main(int argc, char **argv)
{
    header_t header = {0};

    if (check_args(argc) == ERROR)
        return ERROR;
    if (launch_parser(&header, argv[1]) == ERROR)
        return ERROR;

    return SUCCESS;
}
