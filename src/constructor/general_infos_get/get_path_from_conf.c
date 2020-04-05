/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_path_from_conf
*/

#include "my_json.h"
#include <stdlib.h>

char *get_path_from_conf(json_object_t *js)
{
    json_value_t *value = json_get_element_by_key(js, "texture_path");
    char *path = NULL;

    if (value && value->value_type == STRING)
        path = value->value;
    return (path);
}