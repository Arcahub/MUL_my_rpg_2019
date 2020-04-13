/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_hud
*/

#ifndef GALAXIE_HUD_H_
#define GALAXIE_HUD_H_

#include "my_game.h"
#include "my_json.h"

typedef struct {
    game_object_t *button;
    game_object_t *planet_name;
    char *village_conf_path;
    scene_t *scene;
} galaxie_hud_t;

game_object_t *rpg_create_animated_button_from_conf(game_object_t *, json_object_t *, game_t *, scene_t *);
game_object_t *rpg_create_text_handler_from_conf(game_object_t *last, json_object_t *js, game_t *game, scene_t *scene);
void galaxie_hud_destroy(void *pt);

#endif /* !GALAXIE_HUD_H_ */
