/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest->c
*/

#include "my_json.h"
#include "components/get_from_config.h"
#include "components/quest/quest.h"
#include "player.h"
#include <stdlib.h>

quest_t rpg_quest_get_from_conf(char *path, scene_t *scene)
{
    json_object_t *js = json_create_from_file((char *) path);
    player_t *player = scene->game->player;

    if (js == NULL)
        return (player->quest);
    player->quest.actual_step = 1;
    if (!get_int_from_conf(js, (int *) &player->quest.reward_item, \
    "reward_item") || !get_int_from_conf(js, \
    &player->quest.reward_money, "reward_money") || \
    !get_int_from_conf(js, (int *) &player->quest.id, "id") || \
    !get_int_from_conf(js, &player->quest.number_of_step, \
    "number_of_step") || !get_int_from_conf(js, \
    &player->quest.reward_item_number, "reward_item_number") || \
    (player->quest.name = get_str_from_conf(js, "name")) == NULL)
        return (player->quest);
    player->quest.step = rpg_quest_load_step_from_conf(js, scene->game);
    rpg_quest_board_update(scene);
    json_object_destroy(js);
    return (player->quest);
}