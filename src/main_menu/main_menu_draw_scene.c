/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu_draw_scene
*/

#include "my_game.h"
#include "my_rpg.h"

void rpg_main_menu_draw_scene(scene_t *scene, game_t *game,
sfRenderWindow *window)
{
    sfText *text = init_text("Space My RPG !", 400, 100, (char *) FONT_PATH);

    sfText_setCharacterSize(text, 100);
    display_scene(scene, window);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    sfFont_destroy((sfFont *) sfText_getFont(text));
    sfText_destroy(text);
}