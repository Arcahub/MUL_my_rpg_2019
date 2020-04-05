/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_flat_object_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "constructors/get_from_config.h"

game_object_t *create_game_object_from_conf(game_object_t *last, json_object_t *js, game_t *game, scene_t *scene)
{
    char *path = get_path_from_conf(js);
    sfVector2f pos = {0, 0};
    game_object_t *object = NULL;

    if (path == NULL || !get_pos_from_conf(js, &pos))
        return (NULL);
    object = create_game_object(last, path, pos, DECOR);
    return (object);
}