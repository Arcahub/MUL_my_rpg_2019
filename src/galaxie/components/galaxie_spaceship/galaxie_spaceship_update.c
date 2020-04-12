/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_spaceship_update
*/

#include "galaxie/galaxie_spaceship.h"
#include <math.h>

bool galaxie_spaceship_update(game_object_t *object, scene_t *scene)
{
    float angle = 0;

    galaxie_spaceship_move(object, scene);
    if (object->move.x == 0 && object->move.y == 0)
        return (true);
    angle = atan2(object->move.y, object->move.x) * (180.0 / M_PI) + 90;
    sfSprite_setRotation(object->sprite, angle);
    return (true);
}