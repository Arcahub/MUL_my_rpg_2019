/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** scene
*/

#include "my_game.h"
#include "my_game/scene.h"
#include "my_game/framerate.h"
#include <stdlib.h>

void destroy_scene(scene_t *scene)
{
    if (scene != NULL) {
        destroy_object_list(scene);
        destroy_binds_list(scene->binds_list);
        free(scene);
    }
}

void display_scene(scene_t *scene, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, scene->background_color);
    draw_objects(scene->objects_list, window, scene->z_index_deepth);
}

void check_if_event_is_bind(sfEvent event, game_t *game, scene_t *scene, sfRenderWindow *window)
{
    for (bind_event_t *tmp = scene->binds_list; tmp; tmp = tmp->next) {
        if (tmp->id == event.type)
            tmp->bind(event, game, scene, window);
    }
}

void handle_scene_event(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_if_event_is_bind(event, game, scene, window);
    }
}

scene_t *create_empty_scene(sfRenderWindow *window)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = sfBlack;
    scene->display = 0;
    scene->scene_views = NULL;
    scene->binds_list = NULL;
    scene->joystick_coord_id = 0;
    scene->objects_list = NULL;
    scene->window = window;
    scene->z_index_deepth = 0;
    scene->update_scene = NULL;
    return (scene);
}