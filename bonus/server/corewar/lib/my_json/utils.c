/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** utils
*/

#include "my_map.h"
#include "my_vec.h"

#include "./include/json.h"

int skip_whitespace(json_state_t *st)
{
    while (get_char(st) == ' ' || get_char(st) == '\t' || get_char(st) == '\n')
        next_char(st);

    return get_char(st);
}

void append_value(json_state_t *st, json_elem_t *value)
{
    if (st->self == NULL) {
        st->self = value;
        return;
    }
    switch (st->self->type) {
        case JSON_ARRAY:
            vec_pushback(&st->self->value.array, &value);
            break;
        case JSON_OBJECT:
            map_set(st->self->value.object, st->parent, value);
            break;
        default:
            break;
    }
}

int parse_key(json_state_t *st)
{
    next_char(st);
    str_clear(&st->parent);

    while (get_char(st) != '"' && get_char(st) != -1) {
        str_cadd(&st->parent, get_char(st));
        next_char(st);
    }
    next_char(st);

    return get_char(st);
}

int get_char(json_state_t *st)
{
    if (st->data_idx >= st->data->length) {
        return -1;
    }

    return st->data->data[st->data_idx];
}

int next_char(json_state_t *st)
{
    if (st->data_idx >= st->data->length) {
        return -1;
    }

    st->data_idx++;

    return st->data->data[st->data_idx];
}
