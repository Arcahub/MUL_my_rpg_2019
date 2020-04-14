/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include "my_rpg.h"
#include "fight_scene/fight_handler.h"
#include "fight_scene/ennemy.h"
#include "fight_scene/ship.h"
#include <stdlib.h>


static void rpg_fight_handler_player_lose(game_object_t *object, \
scene_t *scene)
{
    scene->display = GALAXIE_SCENE;
}

static void rpg_fight_handler_player_win(game_object_t *object, \
scene_t *scene)
{
    scene->display = GALAXIE_SCENE;
}

bool rpg_fight_handler_update(game_object_t *object, scene_t *scene)
{
    fight_handler_t *handler = (fight_handler_t *) object->extend;
    ennemy_t *ennemy = rpg_ennemy_get_extend(scene);
    space_ship_t *ship = rpg_spaceship_get_extend(scene);

    if (ennemy->hp == 0)
        rpg_fight_handler_player_win(object, scene);
    if (ship->hp == 0)
        rpg_fight_handler_player_lose(object, scene);
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