/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instruction_parameter
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#include "my_cstr.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

#include "corewar/op.h"
#include "asm/asm.h"
#include "asm/body.h"
#include "asm/error.h"

int check_instructions(vec_str_t *params, size_t index, asm_t *assembler)
{
    (void)assembler;

    if ((int)params->size != OP_NAME[index].params){
        my_dprintf(2, "%s: Invalid nbr of parameters\nExpected %d, got %d\n",
        OP_NAME[index].name, OP_NAME[index].params, params->size);
        return ERROR;
    }
    return OP_NAME[index].check_inst(index, params);
}

static int get_parameters(
    vec_str_t *params, str_t **buffer, size_t index, asm_t *assembler
)
{
    int status = 0;
    size_t size = OP_NAME[index].size;

    if (check_instructions(params, index, assembler) == ERROR)
        return ERROR;
    for (size_t i = 0; i < params->size; i++) {
        str_ltrim(&params->data[i], ' ');
        str_ltrim(&params->data[i], '\t');
        if (str_startswith(params->data[i], STR(DIRECT_CHAR))) {
            status = manage_direct(params->data[i], buffer, size, assembler);
        }
        if (str_startswith(params->data[i], STR("r")))
            str_cadd(buffer, (long)my_atoi(params->data[i]->data + 1));
        if (!str_startswith(params->data[i], STR("r")) &&
            !str_startswith(params->data[i], STR(DIRECT_CHAR))) {
            status = manage_indirect(params->data[i], buffer, size, assembler);
        }
    }
    return status;
}

static void get_coding_byte(str_t *param_type, str_t **buffer, int index)
{
    unsigned char coding_byte = 0;

    if (index == LIVE || index == ZJMP || index == FORK || index == LFORK )
        return;
    for (size_t i = 0; i <= 7; i++) {
        coding_byte <<= 1;
        if (i > param_type->length)
            continue;
        if (param_type->data[i] == '1') {
            coding_byte |= 1;
        }
    }
    str_cadd(buffer, coding_byte);
}

static str_t *add_parameter(vec_str_t *params, str_t *param_type)
{
    for (size_t i = 0; i < params->size; i++) {
        str_ltrim(&params->data[i], ' ');
        str_ltrim(&params->data[i], '\t');
        if (str_startswith(params->data[i], STR(DIRECT_CHAR))){
            str_sadd(&param_type, STR(DIRECT));
        }
        if (str_startswith(params->data[i], STR("r"))){
            str_sadd(&param_type, STR(REG));
        }
        if (!str_startswith(params->data[i], STR("r")) &&
            !str_startswith(params->data[i], STR(DIRECT_CHAR))){
            str_sadd(&param_type, STR(INDIRECT));
        }
    }
    return param_type;
}

int parse_instruction_parameter(
    str_t *param, size_t index, asm_t *assembler, str_t **buffer
)
{
    champ_t champ = {0};
    str_t *param_type = str_create("");
    int status = 0;

    str_trim(&param, '\t');
    str_trim(&param, ' ');
    champ.params = str_split(param, STR(SEPARATOR_CHAR));
    param_type = add_parameter(champ.params, param_type);
    str_cadd(buffer, ((char) OP_NAME[index].hex));
    get_coding_byte(param_type, buffer, index);
    status = get_parameters(champ.params, buffer, index, assembler);
    champ.line_size = (int)(*buffer)->length;
    vec_pushback(&assembler->champ, &champ);
    free(param_type);
    return status;
}
