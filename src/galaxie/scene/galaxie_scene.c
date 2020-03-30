/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_scene
*/

#include "my_game.h"
#include "galaxie/galaxie.h"
#include "my_rpg.h"

void rpg_galaxie_draw_scene(scene_t *scene, game_t *game,
sfRenderWindow *window)
{
    display_scene(scene, window);
    sfRenderWindow_display(window);
}

void rpg_galaxie_update_scene(scene_t *scene, game_t *game)
{
    update_objects(scene, scene->objects_list, game);
}

void rpg_galaxie_scene_event_bind(scene_t *scene)
{
    bind_event(scene, sfEvtClosed, &close_scene);
}

scene_t *rpg_galaxie_create_scene(game_t *game)
{
    scene_t *scene = create_empty_scene(game->window->window);

    scene->background_color = sfBlack;
    scene->display = GALAXIE_SCENE;
    scene->update_scene = &rpg_galaxie_update_scene;
    scene->objects_list = NULL;
    scene->z_index_deepth = MAX;
    rpg_galaxie_scene_event_bind(scene);
    return (scene);
}