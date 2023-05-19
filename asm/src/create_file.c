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
        my_dprintf(2, "asm: File must be a .s\n");
        return NULL;
    }

    str_slice(&new_file, 0, new_file->length - 2);
    str_add(&new_file, ".cor");
    printf("%s\n", new_file->data);
    return new_file;
}

void write_file(asm_t *assembler)
{
    str_t *new_file = convert_file(assembler->filepath);
    assembler->filepath = new_file->data;

    if (new_file == NULL) {
        return;
    }
    assembler->file = fopen(assembler->filepath, "w");
    if (assembler->file == NULL){
        my_dprintf(2, "asm: Can't open file\n");
        return;
    }
    free(new_file);
}
