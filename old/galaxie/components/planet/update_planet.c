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
<<<<<<< HEAD:src/galaxie/components/planet/create_planet.c
}

game_object_t *rpg_galaxie_create_planet(game_object_t *last, \
char *path, sfVector2f pos)
{
    game_object_t *object = create_game_object(last, path, pos, PLANET);

    object->update = &rpg_galaxie_update_planet;
    object->box = (sfIntRect) {pos.x, pos.y, PLANET_WIDTH, PLANET_HEIGHT};
    return (object);
=======
>>>>>>> 87bea8a9ce4bdbc33bc985023a2723c9f23381a0:old/galaxie/components/planet/update_planet.c
}