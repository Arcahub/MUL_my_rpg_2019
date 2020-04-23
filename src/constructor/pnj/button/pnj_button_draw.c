/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_button_draw.c
*/

#include "my_game.h"

void rpg_pnj_button_draw(sfRenderWindow *window, game_object_t *object)
{
    game_object_t *background = (game_object_t *) object->extend;

    if (background != NULL)
        sfRenderWindow_drawSprite(window, background->sprite, NULL);
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
}