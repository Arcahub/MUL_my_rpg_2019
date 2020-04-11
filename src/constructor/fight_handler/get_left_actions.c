/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_space_ship.c
*/

#include "my_game.h"
#include "my_json.h"
#include "my.h"
#include "const.h"
#include "components/get_from_config.h"
#include "spaceship/ship.h"
#include "components/fight_handler/fight_handler.h"
#include <stdlib.h>

int rpg_get_left_actions(scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);
    fight_handler_t *handler = rpg_fight_handler_get_extend(scene);
    
    return (ship->member_in_ship - handler->done);
}