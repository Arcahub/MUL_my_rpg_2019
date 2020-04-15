/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_player_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "components/get_from_config.h"

game_object_t *rpg_create_player_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    char *path = get_str_from_conf(js, "texture_path");
    game_object_t *object = NULL;
    sfVector2f pos = {0, 0};

    if (path == NULL || !get_vector2f_from_conf(js, &pos, "pos"))
        return (NULL);
    object = create_game_object(last, path, pos, PLAYER);
    if (object == NULL)
        return (NULL);
    return (object);
}