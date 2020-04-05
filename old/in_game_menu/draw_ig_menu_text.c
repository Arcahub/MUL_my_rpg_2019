/*
** EPITECH PROJECT, 2019
** test_rpg
** File description:
** draw_ig_menu_text.c
*/

#include "my_rpg.h"
#include <stdlib.h>

void rpg_in_game_menu_draw_pause_text(sfRenderWindow *window)
{
    sfText *text = init_text("GAME IN PAUSE", 450, 100, (char *) FONT_PATH);

    sfText_setCharacterSize(text, 100);
    sfRenderWindow_drawText(window, text, NULL);
}