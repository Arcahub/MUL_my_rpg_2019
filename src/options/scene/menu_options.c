/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_options
*/

#include "my_rpg.h"
#include "options_menu/options_menu.h"
#include "general_event.h"
#include <stdlib.h>

void rpg_options_draw_scene(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfText *text = init_text((char *)GLOBAL_VOLUME_TEXT, VOLUME_BAR_X - 700, \
    VOLUME_BAR_Y - 30, (char *) FONT_PATH);
    sfText *options = init_text("Options", 600, 100, (char *) FONT_PATH);

    sfText_setCharacterSize(text, 50);
    sfText_setCharacterSize(options, 100);
    sfText_setColor(text, sfWhite);
    display_scene(scene, window);
    sfRenderWindow_drawText(window, options, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    draw_cursor(game->cursor, scene->window);
    sfRenderWindow_display(window);
    sfFont_destroy((sfFont *) sfText_getFont(text));
    sfText_destroy(text);
}

void rpg_options_bind_event(scene_t *scene)
{
    bind_event(scene, sfEvtClosed, &close_scene);
    bind_event(scene, sfEvtMouseButtonPressed, &is_click_on_object);
    bind_event(scene, sfEvtKeyPressed, &return_to_main_menu);
}

scene_t *rpg_options_create_scene(game_t *game)
{
    scene_t *scene = create_empty_scene(game->window->window);

    if (scene == NULL)
        return (NULL);
    scene->objects_list = rpg_options_create_object_list();
    scene->update_scene = &update_scene;
    rpg_options_bind_event(scene);
    return (scene);
}