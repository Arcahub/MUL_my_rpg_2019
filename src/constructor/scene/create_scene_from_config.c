/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_scene_from_config
*/

#include "my_game.h"
#include "my_json.h"
#include "my_rpg.h"
#include "constructors/scene/scene_constructor.h"

static scene_t *create_scene_from_json_object(json_object_t *js, \
game_t *game)
{
    scene_t *scene = create_empty_scene(game->window->window);

    if (scene == NULL)
        return (NULL);
    scene->objects_list = \
    load_scene_objects_list_from_config(js, game, scene);
    scene->display = load_scene_id_from_config(js);
    scene->z_index_deepth = load_scene_z_index_deepth_from_config(js);
    load_scene_draw_from_config(js, scene);
    load_scene_update_from_config(js, scene);
    if (scene->display < 0 || scene->z_index_deepth < 0 || \
    scene->objects_list == NULL || scene->draw_scene == NULL || \
    scene->update_scene == NULL || \
    !load_scene_background_color_from_config(js, scene) || \
    !load_scene_event_from_config(js, scene)) {
        destroy_scene(scene);
        return (NULL);
    }
    return (scene);
}

scene_t *create_scene_from_file(char *path, game_t *game)
{
    json_object_t *js = json_create_from_file(path);
    scene_t *scene = NULL;

    if (js == NULL)
        return (NULL);
    scene = create_scene_from_json_object(js, game);
    json_object_destroy(js);
    return (scene);
}