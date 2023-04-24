/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** parse number
*/

#include "my_cstr.h"
#include "my_map.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "../include/json.h"

int parse_number(json_state_t *st)
{
    json_elem_t *elem = malloc(sizeof(json_elem_t));
    int found_dot = 0;

    elem->value.number = my_atof(st->data->data + st->data_idx);

    if (get_char(st) == '-')
        next_char(st);
    while (my_isnum(get_char(st)) || get_char(st) == '.') {
        found_dot += (get_char(st) == '.');
        next_char(st);
    }
    if (found_dot > 1 || get_char(st) == -1)
        return -1;

    elem->type = (found_dot) ? JSON_DOUBLE : JSON_LONG;
    append_value(st, elem);
    return 0;
}
