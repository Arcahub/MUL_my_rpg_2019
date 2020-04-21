/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_pnj_from_conf.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include "my_json.h"
#include "components/get_from_config.h"

game_object_t *rpg_pnj_init_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), (sfVector2f) {0, 0}, PNJ);

    if (object == NULL)
        return (NULL);
    object->extend = (void *)
    rpg_pnj_init_extend_from_conf(object, js, game, scene);
    object->free_extend = &rpg_pnj_destroy;
    if (!get_vector2f_from_conf(js, &object->pos, "pos") || 
    object->extend == NULL) {
        destroy_game_object(scene, object);
        return (NULL);
    }
    object->update = &rpg_pnj_update;
    object->callback = &rpg_pnj_callback;
    sfSprite_setPosition(object->sprite, object->pos);
    return (object);
}