/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** village_decor_constructor
*/

#ifndef VILLAGE_DECOR_CONSTRUCTOR_H_
#define VILLAGE_DECOR_CONSTRUCTOR_H_

enum {
    SHIP,
    GRASS,
    PATH,
    TREE,
    TAVERN,
    ARMOR,
    WEAPON,
    WATER,
    PNJ1,
    PNJ2,
};

static const char *TILE_PATH[] = {
    "/assets_runner/spaceship01.png"
};

game_object_t *create_village(game_object_t *, json_object_t *,
game_t *, scene_t *);

#endif /* !VILLAGE_DECOR_CONSTRUCTOR_H_ */
