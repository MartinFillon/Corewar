/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** parse boolean
*/

#include "my_map.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "../include/json.h"

int parse_boolean(json_state_t *st)
{
    json_elem_t *elem = malloc(sizeof(json_elem_t));
    elem->type = JSON_BOOLEAN;

    if (my_strncmp(st->data->data + st->data_idx, "true", 4) == 0) {
        elem->value.boolean = 1;
        st->data_idx += 4;
    } else if (my_strncmp(st->data->data + st->data_idx, "false", 5) == 0) {
        elem->value.boolean = 0;
        st->data_idx += 5;
    } else {
        return -1;
    }
    if (get_char(st) == -1)
        return -1;
    append_value(st, elem);
    return 0;
}
