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

void rpg_fight_handler_draw(sfRenderWindow *window, game_object_t *object)
{
    fight_handler_t *handler = (fight_handler_t *) object->extend;
    game_object_t *tmp = handler->button;

    for (; tmp; tmp = tmp->next)
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
}