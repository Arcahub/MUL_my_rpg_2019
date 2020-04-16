/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** general_event
*/

#include "my_rpg.h"

void return_to_main_menu(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    if (event.key.code != sfKeyEscape)
        return;
    if (scene->display == IN_GAME_MENU_SCENE)
        scene->display = GALAXIE_SCENE;
    else
        scene->display = MAIN_MENU_SCENE;
}