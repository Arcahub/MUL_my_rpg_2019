/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_background_generate_col
*/

#include "galaxie/galaxie_background.h"

game_object_t *galaxie_background_generate_line(game_object_t *last,
galaxie_mini_map_t *map, sfVector2f pos, int n)
{
    game_t *game = map->scene->game;
    game_object_t *tmp = NULL;

    pos.x -= game->window->width * 0.5 * n;
    for (int i = 0; i < n; i++) {
        tmp = create_galaxie_background(last, map, pos);
        last = (tmp) ? tmp : last;
        pos.x += 1920;
    }
    return (last);
}