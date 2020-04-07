/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** callback_button
*/

#ifndef CALLBACK_BUTTON_H_
#define CALLBACK_BUTTON_H_

#include "my_game.h"

enum {
    PLAY_BUTTON_CALLBACK,
    OPTIONS_BUTTON_CALLBACK,
    INFOS_BUTTON_CALLBACK,
    EXIT_BUTTON_CALLBACK,
    RETURN_BUTTON_CALLBACK,
    MAIN_MENU_BUTTON_CALLBACK,
    MAX_CALLBACK_ID_BUTTON
};


void play_button_function(game_object_t *, void *);
void options_button_function(game_object_t *, void *);
void exit_button_function(game_object_t *, void *);
void infos_button_function(game_object_t *, void *);
void return_button_function(game_object_t *, void *);
void infos_right_arrow_function(game_object_t *, void *);
void infos_left_arrow_function(game_object_t *, void *);
void main_menu_button_function(game_object_t *, void *);

static void (*BUTTON_CALLBACK_PT[]) (game_object_t *, void *) = {
    &play_button_function,
    &options_button_function,
    &infos_button_function,
    &exit_button_function,
    &return_button_function,
    &main_menu_button_function
};

#endif /* !CALLBACK_BUTTON_H_ */
