/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** scene_loop
*/

#include "my_game.h"

game_object_t *rpg_inventory_create(game_object_t *last, char *path);

int scene_loop(game_t *game, const char *conf_path)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = create_scene_from_file(conf_path, game);
    int display = 0;

    if (scene == NULL)
        return (-1);
    display = scene->display;
    scene->objects_list = rpg_inventory_create(scene->objects_list, "templates/inv.png");
    while (sfRenderWindow_isOpen(scene->window) && scene->display == display) {
        handle_scene_event(scene, game, scene->window);
        handle_framerate(clock, scene, game);
        scene->draw_scene(scene, game, scene->window);
    }
    disappear_scene(scene, scene->window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}