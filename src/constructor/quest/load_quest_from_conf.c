/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/quest/quest.h"
#include "my_rpg.h"

void create_step_from_conf(json_object_t *js, \
step_t *next, game_t *game, scene_t *scene)
{
    return;
}

step_t *rpg_quest_load_step_from_conf(json_object_t *js, game_t *game, scene_t *scene)
{
    json_value_t *value = NULL;
    json_array_t *array = NULL;
    step_t *list = NULL;
    step_t *tmp = NULL;

    value = json_get_element_by_key(js, "step_list");
    if (!value || value->value_type != ARRAY)
        return (NULL);
    array = (json_array_t *) value->value;
    for (int i = 0; array->array[i]; i++) {
        if (array->array[i]->value_type != OBJECT)
            continue;
        value = json_get_element_by_key(array->array[i]->value, "type");
        if (value && value->value_type == INT) {
            tmp = create_step_from_conf(array->array[i]->value, list, \
            game, scene);
            list = (tmp) ? tmp : list;
        }
    }
    return (list);
}