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

void rpg_galaxie_scene_event_bind(scene_t *scene)
{
    bind_event(scene, sfEvtClosed, &close_scene);
    bind_event(scene, sfEvtMouseButtonPressed, &is_click_on_object);
    bind_event(scene, sfEvtKeyPressed, &rpg_galaxie_handle_key_pressed);
}

scene_t *rpg_galaxie_create_scene(game_t *game)
{
    scene_t *scene = create_empty_scene(game->window->window);

    scene->background_color = sfBlack;
    scene->display = GALAXIE_SCENE;
    scene->update_scene = &update_scene;
    scene->objects_list = rpg_galaxie_generate_space();
    scene->z_index_deepth = MAX;
    rpg_galaxie_scene_event_bind(scene);
    return (scene);
}