/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_event
*/

#include "my_game.h"
#include "player.h"

void galaxie_move_event(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    game_object_t *tmp = NULL;
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window,
    sfMouse_getPositionRenderWindow(window), sfRenderWindow_getView(window));
    player_t *player_s = NULL;

    for (tmp = scene->objects_list; tmp && tmp->type != PLAYER;
    tmp = tmp->next);
    if (!tmp)
        return;
    player_s = tmp->extend;
    if (player_s != NULL)
        player_s->galaxie_dest = pos;
}