/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_event
*/

#include "my_game.h"

void village_move_event(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    sfVector2f new_move = {0, 0};
    game_object_t *tmp = scene->objects_list;

    for (; tmp && tmp->type != PLAYER; tmp = tmp->next);
    if (tmp->type != PLAYER)
        return;
    if (event.key.code == sfKeyDown) {
        new_move.y = 5;
        tmp->move = new_move;
        return;
    }
    if (event.key.code == sfKeyUp) {
        new_move.y = -5;
        tmp->move = new_move;
        return;
    }
    if (event.key.code == sfKeyRight) {
        new_move.x = 5;
        tmp->move = new_move;
        return;
    }
     if (event.key.code == sfKeyLeft) {
        new_move.x = -5;
        tmp->move = new_move;
        return;
    }
}