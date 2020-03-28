/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_scene
*/

#include "my_game.h"
#include "rpg.h"

scene_t *rpg_galaxie_create_scene(game_t *game)
{
    scene_t *scene = malloc(sizeof(scene_t));

    scene->background_color = sfBlack;
    scene->display = GALAXIE_SCENE;
    scene->handle_event = &rpg_galaxie_handle_event;
    scene->objects_list = NULL;
    scene->window = game->window->window;
    scene->z_index_deepth = 0;
}