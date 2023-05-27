/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** parse value dispatcher
*/

#include "my_map.h"
#include "my_str.h"

#include "./include/json.h"

int parse_value(json_state_t *st)
{
    if (get_char(st) == ':')
        next_char(st);
    if (skip_whitespace(st) == -1)
        return -1;

    int chr = get_char(st);
    if (chr == '"')
        return parse_string(st);
    if (chr == '{')
        return parse_object(st);
    if (chr == '[')
        return parse_array(st);
    if (chr == 't' || chr == 'f')
        return parse_boolean(st);
    if (chr == '-' || my_isnum(chr))
        return parse_number(st);
    return -1;
}
