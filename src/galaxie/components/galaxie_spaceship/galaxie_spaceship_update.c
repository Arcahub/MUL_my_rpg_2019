/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_spaceship_update
*/

#include "galaxie/galaxie_spaceship.h"

bool galaxie_spaceship_update(game_object_t *object, scene_t *scene)
{
    galaxie_spaceship_move(object, scene);
    return (true);
}