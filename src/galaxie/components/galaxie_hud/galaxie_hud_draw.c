/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_hud_draw
*/

#include "galaxie/galaxie_hud.h"

void galaxie_hud_draw(sfRenderWindow *window, game_object_t *object)
{
    galaxie_hud_t *hud = object->extend;

    if (object->state == 0) {
        draw_object(window, hud->button);
        draw_object(window, hud->planet_name);
    }
}