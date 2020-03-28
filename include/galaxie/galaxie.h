/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie
*/

#ifndef GALAXIE_H_
#define GALAXIE_H_

#include "my_game.h"

scene_t *rpg_galaxie_create_scene(game_t *game);
void rpg_galaxie_handle_event(scene_t *scene, game_t *game, sfRenderWindow *window);

#endif /* !GALAXIE_H_ */
