/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_event
*/

#include "my_game.h"
#include "player.h"
#include "galaxie/galaxie_hud.h"
#include "my_rpg.h"

static void galaxie_button_callback(scene_t *scene, sfRenderWindow *window)
{
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window,
    sfMouse_getPositionRenderWindow(window), sfRenderWindow_getView(window));
    game_object_t *tmp = NULL;
    galaxie_hud_t *hud = NULL;

    for (tmp = scene->objects_list; tmp && tmp->type != GALAXIE_HUD;
    tmp = tmp->next);
    if (!tmp)
        return;
    hud = tmp->extend;
    if (sfIntRect_contains(&hud->button->box, pos.x, pos.y))
        scene->display = VILLAGE_SCENE;
}

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
    galaxie_button_callback(scene, window);
}