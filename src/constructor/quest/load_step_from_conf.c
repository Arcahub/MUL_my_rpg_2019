/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_quest_from_conf.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/quest/quest.h"
#include <stdio.h>
#include <stdlib.h>
#include "components/get_from_config.h"

static step_t *create_step_from_conf(json_object_t *js, step_t *next, game_t *game)
{
    step_t *step = malloc(sizeof(step_t));

    if (step == NULL)
        return (NULL);
    if (!get_int_from_conf(js, (int *) &step->step_type, "type") || \
    !get_int_from_conf(js, &step->step_number, "step_number") ||
    (step->description = get_str_from_conf(js, "description")) == NULL || \
    !get_vector2f_from_conf(js, &step->pos, "pos"))
        return (NULL);
    if (step->step_type == FIGHT && (step->fight_scene = \
    get_str_from_conf(js, "fight_scene")) == NULL)
        return (NULL);
    step->validated = 0;
    step->next = next;
    return (step);
}

step_t *rpg_quest_load_step_from_conf(json_object_t *js, game_t *game)
{
    json_value_t *value = NULL;
    json_array_t *array = NULL;
    step_t *list = NULL;
    step_t *tmp = NULL;

    value = json_get_element_by_key(js, "step_list");
    if (!value || value->value_type != ARRAY)
        return (NULL);
    array = value->value;
    for (int i = 0; array->array[i]; i++) {
        if (array->array[i]->value_type != OBJECT)
            continue;
        value = json_get_element_by_key(array->array[i]->value, "type");
        if (value && value->value_type == INT) {
            tmp = create_step_from_conf(array->array[i]->value, list, game);
            list = (tmp) ? tmp : list;
        }
    }
    return (list);
}