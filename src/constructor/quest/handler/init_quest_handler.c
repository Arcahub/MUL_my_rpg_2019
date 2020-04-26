/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest_handler.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/quest/quest.h"
#include "components/quest/board.h"
#include "player.h"
#include <stdlib.h>

bool rpg_quest_handler_update(game_object_t *object, scene_t *scene)
{
    step_t *tmp = NULL;
    game_object_t *tmp2 = scene->objects_list;
    player_t *player = scene->game->player;

    if (player->quest.step == NULL || \
    player->quest.state == UNTAKEN)
        return (true);
    tmp = player->quest.step;
    for (; tmp && tmp->step_number != player->quest.actual_step; \
    tmp = tmp->next);
    if (tmp == NULL || tmp->step_number != player->quest.actual_step || \
    tmp->step_type != REACH)
        return (true);
    for (; tmp2 && tmp2->type != PLAYER; tmp2 = tmp2->next);
    if (tmp2 == NULL || tmp2->type != PLAYER)
        return (true);
    if (scene->display == (int) tmp->scene && sfIntRect_contains(&tmp2->box,
    tmp->pos.x, tmp->pos.y))
        validate_step(scene->game, scene, &player->quest);
    return (true);
} // NORM

game_object_t *rpg_quest_handler_init_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    if (object == NULL)
        return (NULL);
    init_game_object(object);
    object->draw = NULL;
    object->update = &rpg_quest_handler_update;
    return (object);
}