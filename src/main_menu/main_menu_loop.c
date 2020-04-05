/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu_loop
*/

#include "my_rpg.h"
#include "my_game.h"
#include "main_menu/main_menu.h"

int rpg_main_menu_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = create_scene_from_file("./config/main_menu.json", game);
    scene_index display = MAIN_MENU_SCENE;

    if (scene == NULL)
        return (-1);
    scene->window = window;
    while (sfRenderWindow_isOpen(window) && scene->display == MAIN_MENU_SCENE) {
        handle_scene_event(scene, game, window);
        handle_framerate(clock, scene, game);
        rpg_main_menu_draw_scene(scene, game, window);
    }
    disappear_scene(scene, window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}