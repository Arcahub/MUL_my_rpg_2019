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
    game_object_t * tmp = scene->objects_list;

    if (hud->button && hud->button->update)
        hud->button->update(hud->button, scene);
    for (; tmp && tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp && tmp->state == 1)
        object->state = 0;
    return (true);
}