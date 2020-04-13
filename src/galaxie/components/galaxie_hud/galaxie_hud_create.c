/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_hud_create
*/

#include "galaxie/galaxie_hud.h"
#include <stdlib.h>

game_object_t *galaxie_hud_create(game_object_t *last, json_object_t *js,
game_t *game, scene_t *scene)
{
    json_value_t *value = NULL;
    game_object_t *object = malloc(sizeof(game_object_t));
    galaxie_hud_t *hud = malloc(sizeof(galaxie_hud_t));

    if (object == NULL || hud == NULL)
        return (NULL);
    init_appearing_object(object);
    *hud = (galaxie_hud_t) {NULL, NULL, NULL, scene};
    value = json_get_element_by_key(js, "button");
    hud->button = (value && value->value_type == OBJECT) ?
    rpg_create_animated_button_from_conf(NULL, value->value, game, scene) : NULL;
    hud->planet_name = (value && value->value_type == OBJECT) ?
    rpg_create_text_handler_from_conf(NULL, value->value, game, scene) : NULL;
    hud->village_conf_path = NULL;
    hud->scene = scene;
    object->extend = hud;
    object->draw = &galaxie_hud_draw;
    object->free_extend = &galaxie_hud_destroy;
    return (object);
}