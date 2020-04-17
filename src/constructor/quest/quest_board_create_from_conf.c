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
#include "const.h"
#include "components/get_from_config.h"
#include "components/quest/board.h"

static quest_board_t *rpg_quest_board_create_extend(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    quest_board_t *board = malloc(sizeof(quest_board_t));

    if (board == NULL)
        return (NULL);
    board->title = init_text("Quest board !", 500, 100, (char *) FONT_PATH);
    return (board);
}

game_object_t *rpg_quest_board_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, \
    get_str_from_conf(js, "texture_path"), (sfVector2f) {0, 0}, QUEST_BOARD);

    if (object == NULL)
        return (NULL);
    object->extend = (void *) rpg_quest_board_create_extend(last, js, game, scene);
    if (object->extend == NULL)
        return (NULL);
    return (object);
}