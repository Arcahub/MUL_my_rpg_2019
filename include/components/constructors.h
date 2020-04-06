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
    DECOR_CONSTRUCTOR,
    BUTTON_CONSTRUCTOR,
    ANIMATED_BUTTON_CONSTRUCTOR,
    PARALLAX_CONSTRUCTOR,
    SOUND_INDICATOR_CONSTRUCTOR,
    SOUND_BAR_CONSTRUCTOR,
    TEXT_CONSTRUCTOR,
    CONSTRUCTORS_MAX_ID
};

game_object_t *rpg_create_decor_from_conf(game_object_t *, json_object_t *, game_t *, scene_t *);
game_object_t *rpg_create_button_from_conf(game_object_t *, json_object_t *, game_t *, scene_t *);
game_object_t *rpg_create_animated_button_from_conf(game_object_t *, json_object_t *, game_t *, scene_t *);
game_object_t *rpg_create_parallax_from_conf(game_object_t *, json_object_t *, game_t *, scene_t *);
game_object_t *rpg_options_create_sound_indicator_from_conf(game_object_t *, json_object_t *, game_t *, scene_t *);
game_object_t *rpg_options_create_sound_bar_from_conf(game_object_t *, json_object_t *, game_t *, scene_t *);

static game_object_t *(*CONSTRUCTORS[])(game_object_t *, json_object_t *, game_t *, scene_t *) = {
    &rpg_create_decor_from_conf,
    &rpg_create_button_from_conf,
    &rpg_create_animated_button_from_conf,
    &rpg_create_parallax_from_conf,
    &rpg_options_create_sound_indicator_from_conf,
    &rpg_options_create_sound_bar_from_conf
};

#endif /* !CONSTRUCTORS_H_ */
