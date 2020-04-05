/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_planet
*/

#include "my_game.h"
#include "galaxie/galaxie.h"
#include "my_rpg.h"

bool rpg_galaxie_update_planet(game_object_t *object, scene_t *scene)
{
    game_object_t *tmp = scene->objects_list;

    for (; tmp; tmp = tmp->next) {
        if (tmp->type == (int) PLAYER)
            break;
    }
    if (sfIntRect_intersects(&tmp->box, &object->box, NULL))
        scene->display = MAIN_MENU_SCENE;
    return (true);
}