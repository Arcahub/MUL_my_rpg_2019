/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** in_game_menu_loop
*/

#include "my_rpg.h"
#include "in_game_menu/in_game_menu.h"

int rpg_in_game_menu_loop(game_t *game, sfRenderWindow *window, \
scene_t *last_scene)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = rpg_in_game_menu_create_scene(game);
    scene_index display = IN_GAME_MENU_SCENE;

    if (scene == NULL)
        scene->display = -1;
    scene->window = window;
    while (sfRenderWindow_isOpen(window) && scene->display == \
    IN_GAME_MENU_SCENE) {
        handle_scene_event(scene, game, window);
        handle_framerate(clock, scene, game);
        draw_objects(scene->objects_list, window, 0);
        draw_cursor(game->cursor, window);
        rpg_in_game_menu_draw_pause_text(window);
        sfRenderWindow_display(window);
    }
    rpg_in_game_menu_close_scene(scene, window, last_scene, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}