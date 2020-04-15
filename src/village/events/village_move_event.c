/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_event
*/

#include "my_game.h"
#include "player.h"

void village_move_event(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    if (event.key.code == sfKeyLeft)
        printf("Salut\n");
}