/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu_bind_event
*/

#include "my_game.h"
#include "general_event.h"

void rpg_main_menu_bind_event(scene_t *scene)
{
    bind_event(scene, sfEvtClosed, &close_scene);
    bind_event(scene, sfEvtMouseButtonPressed, &is_click_on_object);
}