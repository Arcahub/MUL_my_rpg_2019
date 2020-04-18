/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_board_create_from_conf.c
*/

#include "my_json.h"
#include "my_game.h"
#include "components/quest/quest.h"
#include <stdlib.h>
#include "components/quest/board.h"

static const char *FONT_PATH = "templates/font/space.ttf";

quest_board_t *rpg_quest_board_create_extend(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    quest_board_t *board = malloc(sizeof(quest_board_t));
    step_t *tmp = game->quest->step;

    if (board == NULL || tmp == NULL)
        return (NULL);
    board->step_to_draw = 0;
    board->actual_step = NULL;
    board->number_of_step = game->quest->number_of_step;
    board->steps = malloc(sizeof(sfText *) * board->number_of_step);
    if (board->steps == NULL)
        return (NULL);
    for (int x = 0; x < board->number_of_step; x++)
        board->steps[x] = NULL;
    board->title = init_text("Quest board", 500, 50, (char *) FONT_PATH);
    sfText_setCharacterSize(board->title, 100);
    board->name = init_text(game->quest->name, 400, 250, (char *) FONT_PATH);
    sfText_setCharacterSize(board->name, 70);
    board = rpg_quest_board_init_text_step(tmp, board);
    board = rpg_quest_board_init_text(game, tmp, board);
    return (board);
}