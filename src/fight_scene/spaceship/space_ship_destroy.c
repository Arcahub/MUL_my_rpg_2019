/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_space_ship.c
*/

#include "fight_scene/ship.h"
#include <stdlib.h>

void rpg_space_ship_destroy(void *ptr)
{
    space_ship_t *space_ship = ptr;

    if (!space_ship->hp_text)
        sfText_destroy(space_ship->hp_text);
    if (!space_ship->shield_text)
        sfText_destroy(space_ship->shield_text);
    if (!space_ship->repair_turn_left)
        sfText_destroy(space_ship->repair_turn_left);
    if (!space_ship->action_left)
        sfText_destroy(space_ship->action_left);
    if (!space_ship)
        free(space_ship);
}