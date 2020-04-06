/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** constructors
*/

#ifndef TEXT_HANDLER_H_H
#define TEXT_HANDLER_H_H

#include "my_game.h"
#include "my_json.h"

typedef struct text_handler {
    sfText *text;
    int character_size;
    sfColor color;
    sfTextStyle style;
} text_handler_t;

void draw_text(sfRenderWindow *window, game_object_t *object);

#endif /* !TEXT_HANDLER_H_H */
