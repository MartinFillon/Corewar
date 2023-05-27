/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** json setters
*/

#include <stdarg.h>

#include "./include/json.h"

json_elem_t *json_get(json_elem_t const *json, int ac, ...)
{
    va_list ap;

    va_start(ap, ac);
    json_elem_t *elem = get_va_value(ac, &ap, json);
    va_end(ap);

    return elem;
}
