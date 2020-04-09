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

void rpg_fight_handler_update(game_object_t *object, scene_t *scene)
{
    fight_handler_t *handler = (fight_handler_t *) object->extend;

    if (handler->in_fight == 0)
        return;
    if (handler->player_turn == 1) {
        rpg_fight_handler_get_player_action(object, scene);
        rpg_fight_handler_make_player_actions(object, scene);
    } else {
        rpg_fight_handler_make_ennemy_play(object, scene);
    }
}

fight_handler_t *rpg_init_fight_handler_extend(game_object_t *object)
{
    fight_handler_t *handler = malloc(sizeof(fight_handler_t));

    if (handler == NULL)
        return (NULL);
    handler->in_fight = 0;
    handler->player_turn = 1;
    handler->action_number = rpg_spaceship_get_equiped_weapon(object);
    handler->id = malloc(sizeof(action_id) * handler->action_number);
    if (handler->id == NULL)
        return (NULL);
    return (handler);
}

game_object_t *rpg_fight_handler_create(game_object_t *last)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    if (object == NULL)
        return (NULL);
    init_game_object(object);
    object->extend = (void *) rpg_init_fight_handler_extend(object);
    object->update = &rpg_fight_handler_update;
    object->next = last;
    return (object);
}