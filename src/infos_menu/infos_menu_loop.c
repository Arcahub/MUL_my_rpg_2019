/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** infos_menu_loop
*/

#include "my_rpg.h"
#include "infos_menu/infos_menu.h"

int rpg_infos_menu_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = rpg_infos_create_scene(game);
    scene_index display = INFOS_SCENE;

    if (scene == NULL)
        scene->display = -1;
    else
        scene->display = INFOS_SCENE;
    scene->window = window;
    while (sfRenderWindow_isOpen(window) && scene->display == INFOS_SCENE) {
        handle_scene_event(scene, game, window);
        handle_framerate(clock, scene, game);
        rpg_infos_draw_scene(scene, game, window);
    }
    disappear_scene(scene, window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}