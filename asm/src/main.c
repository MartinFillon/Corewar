/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <unistd.h>

#include "corewar/corewar.h"

int main(int argc, char **argv)
{
    header_t header;

    if (argc != 2){
        write(2, "Usage: ./asm file_name[.s]\n", 28);
        return ERROR;
    }
    if (launch_parser(&header, argv[1]) == ERROR){
        return ERROR;
    }
    if (write_file(&header, argv[1]) == ERROR){
        return ERROR;
    }
    return SUCCESS;
}
