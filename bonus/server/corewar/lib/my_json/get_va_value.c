/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** get va arg value
*/

#include <stdarg.h>

#include "my_stdlib.h"

#include "./include/json.h"

json_elem_t *get_va_value(int ac, va_list *ap, json_elem_t const *json)
{
    json_elem_t *elem = NULL;
    str_t *key = str_create("");

    while (ac--) {
        str_add(str_clear(&key), va_arg(*ap, char *));
        elem = map_get(json->value.object, key);
        if (elem == NULL || elem->type != JSON_OBJECT)
            break;
        json = elem;
    }
    free(key);
    return elem;
}
