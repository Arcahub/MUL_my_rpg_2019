/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main_menu_button_fonctions
*/

#include "my_rpg.h"

bool play_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = GALAXIE_SCENE;
    return (true);
}

bool options_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = OPTION_SCENE;
    return (true);
}

bool infos_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = INFOS_SCENE;
    return (true);
}

bool exit_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = -1;
    return (true);
    sfRenderWindow_close(scene->window);
}

bool return_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = MAIN_MENU_SCENE;
    return (true);
}