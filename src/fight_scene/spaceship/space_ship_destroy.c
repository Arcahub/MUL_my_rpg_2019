/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_space_ship.c
*/

#include "fight_scene/ship.h"
#include <stdlib.h>

void rpg_space_ship_destroy(space_ship_t *ship)
{
    if (ship != NULL)
        free(ship);
}