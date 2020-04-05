/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** GG_menu
*/

#include "my_rpg.h"
#include <stdlib.h>

game_object_t *rpg_end_menu_create_objects_list(void)
{
    game_object_t *object = NULL;

    return (object);
}

void rpg_end_menu_draw_scene(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    display_scene(scene, window);
    sfRenderWindow_display(window);
}

scene_t *rpg_end_menu_create_scene(game_t *game)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->objects_list = rpg_end_menu_create_objects_list();
    scene->display = MAIN_MENU_SCENE;
    return (scene);
}

int rpg_end_menu_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = rpg_end_menu_create_scene(game);
    scene_index display = END_SCENE;

    if (scene == NULL)
        scene->display = -1;
    scene->window = window;
    while (sfRenderWindow_isOpen(window) && scene->display == END_SCENE) {
        handle_scene_event(scene, game, window);
        handle_framerate(clock, scene, game);
        rpg_end_menu_draw_scene(scene, game, window);
    }
    disappear_scene(scene, window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}