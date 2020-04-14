/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_hud_update
*/

#include "galaxie/galaxie_hud.h"

bool galaxie_hud_update(game_object_t *object, scene_t *scene)
{
    galaxie_hud_t *hud = object->extend;

    if (hud->button && hud->button->update)
        hud->button->update(hud->button, scene);
    return (true);
}