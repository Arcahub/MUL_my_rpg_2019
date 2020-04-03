/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_parse_get_simple_value
*/

#include "my_json.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

static json_value_t json_parse_get_bool_value(char **buff)
{
    json_value_t value = {NONE, NULL};
    bool *val = NULL;

    value.value = malloc(sizeof(bool));
    if (!value.value)
        return (value);
    value.value_type = BOOLEAN;
    val = value.value;
    if (strncmp(*buff, "true", 4) == 0) {
        *val = true;
        *buff += 4;
    }
    if (strncmp(*buff, "false", 5) == 0) {
        *val = false;
        *buff += 5;
    }
    return (value);
}

json_value_t json_parse_get_int_value(char **buff)
{
    int *val = NULL;
    char *str_nbr = NULL;
    json_value_t value = {INT, NULL};
    int i = 0;

    if (strncmp(*buff, "true", 4) == 0 || strncmp(*buff, "false", 5) == 0)
        return (json_parse_get_bool_value(buff));
    for (; *(*buff + i) <= '9' && *(*buff +i) >= '0'; i++);
    val = malloc(sizeof(int));
    if (val == NULL)
        return (value);
    *val = my_getnbr(*buff);
    *buff += i;
    value.value = val;
    return (value);
}