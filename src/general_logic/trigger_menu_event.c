/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** trigger_menu_event
*/

#include "my_game.h"

void trigger_in_game_menu(sfEvent event, game_t *game,
scene_t *scene, sfRenderWindow *window)
{
    sfKeyCode key = event.key.code;

    if (key == sfKeyEscape)
        scene->display = scene_loop(game, (const char *)
        "./config/in_game_menu.json");
}