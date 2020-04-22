/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest->c
*/

#include "my_json.h"
#include <stdlib.h>
#include "components/get_from_config.h"
#include "components/quest/quest.h"

quest_t *rpg_quest_get_from_conf(char *path, scene_t *scene)
{
    json_object_t *js = json_create_from_file((char *) path);

    if (js == NULL || scene->game->quest == NULL)
        return (scene->game->quest);
    scene->game->quest->actual_step = 1;
    if (!get_int_from_conf(js, (int *) &scene->game->quest->reward_item, \
    "reward_item") || !get_int_from_conf(js, \
    &scene->game->quest->reward_money, "reward_money") || \
    !get_int_from_conf(js, (int *) &scene->game->quest->id, "id") || \
    !get_int_from_conf(js, &scene->game->quest->number_of_step, \
    "number_of_step") || !get_int_from_conf(js, \
    &scene->game->quest->reward_item_number, "reward_item_number") || \
    (scene->game->quest->name = get_str_from_conf(js, "name")) == NULL) {
        rpg_destroy_quest(scene->game->quest);
        return (scene->game->quest);
    }   
    scene->game->quest->step = rpg_quest_load_step_from_conf(js, scene->game);
    rpg_quest_board_update(scene);
    return (scene->game->quest);
}