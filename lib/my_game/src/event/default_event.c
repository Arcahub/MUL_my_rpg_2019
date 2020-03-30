/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** default_event
*/

#include "my_game/event.h"

void close_scene(sfEvent event, game_t *game, scene_t *scene, sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}