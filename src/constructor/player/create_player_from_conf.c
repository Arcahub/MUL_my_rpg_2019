/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_button_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "components/button/callback_button.h"
#include "components/get_from_config.h"

game_object_t *rpg_create_player_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    sfVector2f pos = {0, 0};
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), pos, PLAYER);

    if (object == NULL)
        return (NULL);
    if (!get_vector2f_from_conf(js, &pos, "pos"))
        return (NULL);
    object->pos = pos;
    sfSprite_setPosition(object->sprite, object->pos);
    sfSprite_setRotation(object->sprite, 270);
    object->draw = &rpg_player_draw;
    object->update = &rpg_player_update;
    object->free_extend = &rpg_player_destroy;
    if (object == NULL || object->extend == NULL) {
        rpg_ennemy_destroy(object->extend);
        destroy_game_object(scene, object);
        return (NULL);
    }
    return (object);
}