/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** village_tile_constructors
*/

#ifndef VILLAGE_TILE_CONSTRUCTORS_H_
#define VILLAGE_TILE_CONSTRUCTORS_H_

#include "my_game.h"

game_object_t *generate_tile(game_object_t *last, sfVector2f pos, int id,
int z_index);
game_object_t *generate_forest(game_object_t *last, sfVector2f pos, int id,
int z_index);
game_object_t *generate_grass(game_object_t *last, sfVector2f pos, int id,
int z_index);
game_object_t *generate_path(game_object_t *last, sfVector2f pos, int id,
int z_index);
game_object_t *generate_house(game_object_t *last, sfVector2f pos, int id,
int z_index);
game_object_t *generate_waterfall(game_object_t *last, sfVector2f pos, int id,
int z_index);

static game_object_t *(*TILE_GENERATORS[])(game_object_t *, sfVector2f, int,
int) = {
    &generate_grass,
    &generate_path,
    &generate_house,
    &generate_house,
    &generate_forest,
    &generate_forest,
    &generate_forest,
    &generate_tile,
    &generate_forest,
    &generate_house,
    &generate_house,
    &generate_waterfall,
    &generate_tile,
    &generate_tile,
    &generate_tile
};

#endif /* !VILLAGE_TILE_CONSTRUCTORS_H_ */
