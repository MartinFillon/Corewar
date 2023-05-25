/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** impossible_labels
*/

#include <stdlib.h>

#include "my_stdio.h"

#include "asm/asm.h"

static int compare_labels(vec_label_t *labels, size_t j, str_t *orig)
{
    str_t *tmp = NULL;

    for (size_t i = j + 1; i < labels->size; i++){
        tmp = str_create(labels->data[i].label->data);
        if (str_compare(tmp, orig) == 0){
            my_dprintf(2, "body: Multiple definition of label\n");
            free(tmp);
            return ERROR;
        }
        free(tmp);
    }
    return SUCCESS;
}

int find_duplicates(vec_label_t *labels)
{
    str_t *tmp = NULL;

    for (size_t j = 0; j < labels->size; j++){
        tmp = str_create(labels->data[j].label->data);
        if (compare_labels(labels, j, tmp) == ERROR){
            free(tmp);
            return ERROR;
        }
        free(tmp);
    }
    return SUCCESS;
}
