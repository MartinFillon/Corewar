/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** create_file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "my_stdio.h"
#include "my_str.h"

#include "asm/asm.h"
#include "corewar/op.h"

str_t *convert_file(char const *filepath)
{
    str_t *new_file = str_create(filepath);

    if (str_endswith(new_file, STR(".s")) == 0) {
        my_dprintf(2, "Error: File must be a .s\n");
        return NULL;
    }

    str_replace(&new_file, STR(".s"), STR(".cor"));
    return new_file;
}

void write_file(
    asm_t *assembler, str_t **buffer
)
{
    (void)buffer;
    str_t *new_file = convert_file(assembler->filepath);
    assembler->filepath = new_file->data;

    if (new_file == NULL) {
        return;
    }

    assembler->file = fopen(assembler->filepath, "w");
    if (assembler->file == NULL){
        my_dprintf(2, "Error: Can't open file\n");
        return;
    }

    fwrite(assembler->header, sizeof(header_t), 1, assembler->file);
    free(new_file);
}
