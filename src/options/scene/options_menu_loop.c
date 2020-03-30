/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** options_menu_loop
*/

#include "my_rpg.h"
#include "options_menu/options_menu.h"

int rpg_options_menu_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = rpg_options_create_scene(game);
    int display = OPTION_SCENE;

    if (scene == NULL)
        scene->display = -1;
    while (sfRenderWindow_isOpen(window) && scene->display == OPTION_SCENE) {
        handle_scene_event(scene, game, window);
        handle_framerate(clock, scene, game);
        rpg_options_draw_scene(scene, game, window);
    }
    disappear_scene(scene, window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}