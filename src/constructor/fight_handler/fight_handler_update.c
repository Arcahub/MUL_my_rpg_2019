/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/fight_handler/fight_handler.h"
#include "spaceship/ship.h"
#include <stdlib.h>

bool rpg_fight_handler_update(game_object_t *object, scene_t *scene)
{
    fight_handler_t *handler = (fight_handler_t *) object->extend;

    if (object == NULL || handler == NULL)
        return (false);
    if (handler->in_fight == 0)
        return (true);
    handler->action_number = rpg_spaceship_get_equip_size(object, scene);
    if (handler->player_turn == 1 && handler->done == handler->action_number) {
        rpg_fight_handler_make_player_actions(object, scene);
        handler->player_turn = 0;
    } else if (handler->player_turn == 0) {
        rpg_fight_handler_make_ennemy_play(object, scene);
        handler->player_turn = 1;
    }
    return (true);
}