/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parser
*/

#include <stdlib.h>

#include "my_cstr.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "corewar/op.h"
#include "asm/asm.h"
#include "asm/header.h"
#include "asm/body.h"
#include "asm/labels.h"
#include "asm/error.h"

int launch_parser(asm_t *assembler, char const *filepath)
{
    vec_str_t *content = NULL;
    header_t header = {0};

    header.magic = swap_endian(COREWAR_EXEC_MAGIC);
    content = parse_header(filepath, &header);
    if (content == NULL) {
        return ERROR;
    }
    assembler->header = &header;
    write_file(assembler);
    if (parse_labels(content, assembler) == ERROR ||
        parse_body(content, assembler) == ERROR) {
        vec_free(content);
        return ERROR;
    }
    vec_free(content);
    return SUCCESS;
}
