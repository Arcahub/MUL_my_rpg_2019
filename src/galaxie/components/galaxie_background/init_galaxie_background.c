/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_galaxie_background
*/

#include "galaxie/galaxie_minimap.h"

game_object_t *init_galaxie_background(game_object_t *object)
{
    galaxie_mini_map_t *map = object->extend;
    game_t *game = map->scene->game;
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(
    map->scene->window));
    game_object_t *tmp = NULL;

    pos.y -= game->window->height * 2.5;
    for (int i = 0; i < 5; i++) {
        tmp = galaxie_background_generate_line(object, map, pos, 3);
        object = (tmp) ? tmp : object;
        pos.y += game->window->height;
    }
    return (object);
}