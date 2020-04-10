/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_mini_map_draw
*/

#include "galaxie/galaxie_minimap.h"

void draw_mini_map(sfRenderWindow *window, game_object_t *object)
{
    galaxie_mini_map_t *map = object->extend;
    const sfView *tmp_view = sfView_copy(sfRenderWindow_getView(window));

    sfView_setCenter(map->view, sfView_getCenter(tmp_view));
    sfRenderWindow_setView(window, map->view);
    draw_objects(map->scene->objects_list, window,
    map->scene->z_index_deepth - 1);
    sfRenderWindow_setView(window, tmp_view);
    sfView_destroy((sfView *) tmp_view);
}