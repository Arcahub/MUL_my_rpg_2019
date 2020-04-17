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

void validate_quest(game_t *game, scene_t *scene, quest_t *quest)
{
    quest->state = ACHIEVED;
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