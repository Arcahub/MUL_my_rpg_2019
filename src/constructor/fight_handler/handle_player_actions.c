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
#include "components/fight_handler/ennemy.h"

void rpg_fight_handler_get_player_action(game_object_t *object, scene_t *scene)
{
    fight_handler_t *handler = (fight_handler_t *) object->extend;
}

void rpg_fight_handler_make_player_actions(game_object_t *object, scene_t *scene)
{
    fight_handler_t *handler = (fight_handler_t *) object->extend;
    int dodge = 0;

    for (int x = 0; x != handler->action_number - 1; x++) {
        if (handler->id[x] == ATTACK)
            rpg_fight_handler_remove_ennemy_life(object);
        if (handler->id[x] == REPAIR)
            rpg_fight_handler_repair_spaceship(object);
        if (handler->id[x] == DODGE)
            dodge++;
    }
    rpg_fight_handler_handle_dodge(object, dodge);
}