/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** validate_quest.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/quest/quest.h"
#include <stdlib.h>
#include "item/inventory.h"

void validate_quest(game_t *game, scene_t *scene, quest_t *quest)
{
    game_object_t *tmp = scene->objects_list;

    quest->state = ACHIEVED;
    for (; tmp && tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != INVENTORY)
        return;
    tmp->extend = (void *) rpg_inventory_add_item((inventory_t *)
    tmp->extend, quest->reward_item_number, quest->reward_item);
}

void validate_step(game_t *game, scene_t *scene, quest_t *quest)
{
    step_t *tmp = NULL;

    if (quest->actual_step == quest->number_of_step) {
        validate_quest(game, scene, quest);
        return;
    }
    for (tmp = quest->step; tmp && tmp->step_number != quest->actual_step; \
    tmp = tmp->next);
    if (tmp->step_number != quest->actual_step)
        return;
    quest->actual_step++;
    tmp->validated = 1;
}