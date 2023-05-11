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

#include "asm/header.h"
#include "asm/asm.h"
#include "corewar/op.h"

int launch_parser(header_t *header, char const *filepath)
{
    vec_str_t *champ = NULL;

    champ = parse_header(filepath, header);

    if (champ == NULL) {
        vec_free(champ);
        return ERROR;
    }
    if (parse_body(champ, filepath, header) == ERROR) {
        vec_free(champ);
        return ERROR;
    }
    vec_free(champ);
    return SUCCESS;
}
