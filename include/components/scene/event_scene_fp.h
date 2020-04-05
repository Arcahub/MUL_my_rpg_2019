/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_scene_fp
*/

#ifndef EVENT_SCENE_FP_H_
#define EVENT_SCENE_FP_H_

#include "my_game.h"

enum {
    CLOSE_SCENE_EVENT_ID,
    CLICK_ON_EVENT_ID,
    RETURN_TO_MAIN_MENU_EVENT_ID,
    MAX_SCENE_EVENT_ID
};

void return_to_main_menu(sfEvent event, game_t *game, scene_t *scene, sfRenderWindow *window);

static void (*EVENT_SCENE_FP[]) (sfEvent, game_t *, scene_t *, sfRenderWindow *) = {
    &close_scene,
    &is_click_on_object,
    &return_to_main_menu
};

#endif /* !EVENT_SCENE_FP_H_ */
