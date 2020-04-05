/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_loop
*/

#include "my_game.h"
#include "galaxie/galaxie.h"
#include "my_rpg.h"

int rpg_galaxie_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = rpg_galaxie_create_scene(game);
    scene_index display = GALAXIE_SCENE;

    while (sfRenderWindow_isOpen(window) && scene->display == GALAXIE_SCENE) {
        handle_scene_event(scene, game, window);
        handle_framerate(clock, scene, game);
        rpg_galaxie_draw_scene(scene, game, window);
    }
    disappear_scene(scene, window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}