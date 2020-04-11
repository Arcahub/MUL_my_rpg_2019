/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_event
*/

#include "my_game.h"
#include "player.h"

void try_move_left(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    game_object_t *tmp = NULL;

    if (event.key.code != sfKeyLeft)
        return;
    for (tmp = scene->objects_list; tmp && tmp->type != PLAYER;
    tmp = tmp->next);
    if (!tmp)
        return;
    tmp->move = (sfVector2f) {-1, 0};
}

void try_move_right(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    game_object_t *tmp = NULL;

    if (event.key.code != sfKeyRight)
        return;
    for (tmp = scene->objects_list; tmp && tmp->type != PLAYER;
    tmp = tmp->next);
    if (!tmp)
        return;
    tmp->move = (sfVector2f) {1, 0};
}

void try_move_top(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    game_object_t *tmp = NULL;

    if (event.key.code != sfKeyUp)
        return;
    for (tmp = scene->objects_list; tmp && tmp->type != PLAYER;
    tmp = tmp->next);
    if (!tmp)
        return;
    tmp->move = (sfVector2f) {0, -1};
}

void try_move_down(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    game_object_t *tmp = NULL;

    if (event.key.code != sfKeyDown)
        return;
    for (tmp = scene->objects_list; tmp && tmp->type != PLAYER;
    tmp = tmp->next);
    if (!tmp)
        return;
    tmp->move = (sfVector2f) {0, 1};
}

void move_event(sfEvent event, game_t *game, scene_t *scene,
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
    player_s->galaxie_dest = pos;
}