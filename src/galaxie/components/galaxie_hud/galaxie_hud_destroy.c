/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_hud_destroy
*/

#include "galaxie/galaxie_hud.h"
#include <stdlib.h>

void galaxie_hud_destroy(void *pt)
{
    game_object_t *object = pt;
    galaxie_hud_t *hud = object->extend;

    destroy_game_object(hud->scene, hud->button);
    destroy_game_object(hud->scene, hud->planet_name);
    free(hud);
}