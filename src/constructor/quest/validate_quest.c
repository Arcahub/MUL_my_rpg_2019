/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** validate_quest->c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/quest/quest.h"
#include <stdlib.h>
#include <stdio.h>
#include "item/inventory.h"

void validate_quest(game_t *game, scene_t *scene, quest_t *quest)
{
    game_object_t *tmp = scene->objects_list;
    game_object_t *board = scene->objects_list;
    quest_board_t *quest_board = NULL;

    for (; tmp && tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != INVENTORY)
        return;
    tmp->extend = (void *) rpg_inventory_add_item((inventory_t *)
    tmp->extend, quest->reward_item_number, quest->reward_item);
    printf("%d / %d\n", quest->reward_item_number, quest->reward_item);
    for (; board && board->type != QUEST_BOARD; board = board->next);
    if (board->type != QUEST_BOARD)
        return;
    quest_board = (quest_board_t *) board->extend;
    quest_board->draw_infos = 0;
    free(game->quest);
    game->quest = rpg_init_quest(game);
    game->quest->state = RESET;
}

void validate_step(game_t *game, scene_t *scene, quest_t *quest)
{
    step_t *tmp = NULL;
    game_object_t *board = scene->objects_list;
    quest_board_t *quest_board = NULL;

    for (tmp = quest->step; tmp && tmp->step_number != quest->actual_step; \
    tmp = tmp->next);
    if (tmp == NULL || tmp->step_number != quest->actual_step)
        return;
    tmp->validated = 1;
    quest->actual_step++;
    for (; board && board->type != QUEST_BOARD; board = board->next);
    if (board->type != QUEST_BOARD)
        return;
    quest_board = (quest_board_t *) board->extend;
    quest_board = rpg_quest_board_update_text(quest_board, scene);
    if (tmp->step_number == quest->number_of_step - 1)
        quest->state = ACHIEVED;
}