/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_planet
*/

#include "galaxie/galaxie.h"
#include "galaxie/planet.h"
#include "my_game.h"
#include "my_rpg.h"

game_object_t *rpg_galaxie_create_planet(game_object_t *last, char *path,
sfVector2f pos)
{
    game_object_t *object = create_game_object(last, path, pos, PLANET);

    object->update = &rpg_galaxie_update_planet;
    object->box = (sfIntRect) {pos.x, pos.y, PLANET_WIDTH, PLANET_HEIGHT};
    return (object);
}