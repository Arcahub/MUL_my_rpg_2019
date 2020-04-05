/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** constructors
*/

#ifndef CONSTRUCTORS_H_
#define CONSTRUCTORS_H_

#include "my_game.h"
#include "my_json.h"

enum {
    FLAT_OBJECT_CONSTRUCTOR,
    BUTTON_CONSTRUCTOR,
    CONSTRUCTORS_MAX_ID
};

game_object_t *create_game_object_from_conf(game_object_t *, json_object_t *, game_t *, scene_t *);
game_object_t *create_button_from_conf(game_object_t *, json_object_t *, game_t *, scene_t *);

static game_object_t *(*CONSTRUCTORS[])(game_object_t *, json_object_t *, game_t *, scene_t *) = {
    &create_game_object_from_conf,
    &create_button_from_conf,
};

#endif /* !CONSTRUCTORS_H_ */
