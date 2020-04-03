/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_parse_object
*/

#include "my_json.h"
#include <stdlib.h>

json_object_t *json_parse_object(char **buff)
{
    json_object_t *object = NULL;
    json_object_t *list = NULL;

    (*buff)++;
    while (**buff != '}' && **buff != '\0') {
        object = json_object_create();
        if (object == NULL) {
            json_object_destroy(list);
            return (NULL);
        }
        json_parse_value_object(buff, object);
        if (object->value.value == NULL && object->value.value_type == NONE) {
            json_object_destroy(list);
            return (NULL);
        }
        object->next = list;
        list = object;
    }
    if (**buff == '\0')
        return (NULL);
    (*buff)++;
    return (list);
}