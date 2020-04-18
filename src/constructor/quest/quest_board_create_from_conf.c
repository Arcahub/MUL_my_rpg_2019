/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_board_create_from_conf.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/quest/quest.h"
#include <stdlib.h>
#include <stdio.h>
#include "const.h"
#include "components/get_from_config.h"
#include "components/quest/board.h"

void rpg_quest_board_destroy(void *pt)
{
    quest_board_t *board = (quest_board_t *) pt;

    if (board == NULL)
        return;
    if (board->title && board->actual_step) {
        sfText_destroy(board->title);
        sfText_destroy(board->actual_step);    
        sfFont_destroy((sfFont *) sfText_getFont(board->title));
        sfFont_destroy((sfFont *) sfText_getFont(board->actual_step));
    }
    for (int x = 0; x < board->number_of_step; x++)
        if (board->steps[x])
            sfText_destroy(board->steps[x]);
}

game_object_t *rpg_quest_board_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, \
    get_str_from_conf(js, "texture_path"), (sfVector2f) {0, 0}, QUEST_BOARD);

    if (object == NULL)
        return (NULL);
    object->state = 0;
    object->draw = &rpg_quest_board_draw;
    object->extend = (void *) rpg_quest_board_create_extend(last, \
    js, game, scene);
    object->free_extend = &rpg_quest_board_destroy;
    if (object->extend == NULL)
        return (NULL);
    return (object);
}