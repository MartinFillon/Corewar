/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** labels
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_stdlib.h"
#include "my_str.h"
#include "my_cstr.h"

#include "asm/asm.h"
#include "asm/body.h"

int parse_labels(str_t *label, int index, str_t **buffer, labels_t *all_labels)
{
    (void)index;
    (void)buffer;

    for (size_t i = 0; i < all_labels->vector->size; i++) {
        my_printf("---%s\n", all_labels->vector->data[i]->data);
        if (str_ncompare(
                label, all_labels->vector->data[i], label->length) == 0
            ) {
            my_printf("Label exists\n");
            return SUCCESS;
        }
    }
    return ERROR;
}
