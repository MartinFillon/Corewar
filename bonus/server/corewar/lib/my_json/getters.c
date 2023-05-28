/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** json getters
*/

#include "my_map.h"
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

#include "./include/json.h"

double json_get_number(json_elem_t const *json, int ac, ...)
{
    va_list ap;

    if (json->type != JSON_OBJECT)
        return 0.0;
    va_start(ap, ac);
    json_elem_t *elem = get_va_value(ac, &ap, json);
    va_end(ap);

    if (elem == NULL || (elem->type != JSON_LONG && elem->type != JSON_DOUBLE))
        return 0.0;
    return elem->value.number;
}

str_t *json_get_string(json_elem_t const *json, int ac, ...)
{
    va_list ap;

    if (json->type != JSON_OBJECT)
        return NULL;
    va_start(ap, ac);
    json_elem_t *elem = get_va_value(ac, &ap, json);
    va_end(ap);

    if (elem == NULL || elem->type != JSON_STRING)
        return NULL;
    return elem->value.string;
}

vec_json_t *json_get_array(json_elem_t const *json, int ac, ...)
{
    va_list ap;

    if (json->type != JSON_OBJECT)
        return NULL;
    va_start(ap, ac);
    json_elem_t *elem = get_va_value(ac, &ap, json);
    va_end(ap);

    if (elem == NULL || elem->type != JSON_ARRAY)
        return NULL;
    return elem->value.array;
}

map_t *json_get_object(json_elem_t const *json, int ac, ...)
{
    va_list ap;

    if (json->type != JSON_OBJECT)
        return NULL;
    va_start(ap, ac);
    json_elem_t *elem = get_va_value(ac, &ap, json);
    va_end(ap);

    if (elem == NULL || elem->type != JSON_OBJECT)
        return NULL;
    return elem->value.object;
}

int json_get_bool(json_elem_t const *json, int ac, ...)
{
    va_list ap;

    if (json->type != JSON_OBJECT)
        return -1;
    va_start(ap, ac);
    json_elem_t *elem = get_va_value(ac, &ap, json);
    va_end(ap);

    if (elem == NULL || elem->type != JSON_BOOLEAN)
        return -1;
    return elem->value.boolean;
}
