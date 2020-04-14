/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_space_ship.c
*/

#include "my_game.h"
#include "fight_scene/ship.h"
#include "fight_scene/fight_handler.h"

int rpg_get_left_actions(scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);
    fight_handler_t *handler = rpg_fight_handler_get_extend(scene);
    
    return (ship->member_in_ship - handler->done);
}