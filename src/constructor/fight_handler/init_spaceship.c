/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_space_ship.c
*/

#include "my_game.h"
#include "my_json.h"
#include "spaceship/ship.h"
#include "components/fight_handler/fight_handler.h"

void rpg_space_ship_destroy(space_ship_t *ship)
{
    if (ship != NULL)
        free(ship);
}

space_ship_t *rpg_space_ship_extend_create_from_conf(game_object_t *object, \
json_object_t *js)
{
    space_ship_t *space_ship = malloc(sizeof(space_ship_t));

    if (space_ship == NULL)
        return (NULL);
    space_ship->repair_statue = 0;
    space_ship->skill_statue = 0;
    space_ship->repair_value = 0;
    space_ship->member_in_ship = 1;
    if (!get_int_from_conf(js, &space_ship->equiped_weapon, "weapon_id") ||
    !get_int_from_conf(js, &space_ship->damage, "damage") || 
    !get_int_from_conf(js, &space_ship->hp, "hp") || 
    !get_int_from_conf(js, &space_ship->shield, "shield"))
        return (NULL);
    return (space_ship);
}

game_object_t *rpg_space_ship_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    sfVector2f pos = {0, 0};
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), pos, SPACESHIP);

    if (object == NULL)
        return (NULL);
    if (!get_vector2f_from_conf(js, &pos, "pos"))
        return (NULL);
    object->pos = pos;
    object->extend = (void *) rpg_space_ship_extend_create_from_conf(object, js);
    if (object == NULL || object->extend == NULL) {
        rpg_space_ship_destroy((space_ship_t *) object->extend);
        destroy_game_object(scene, object);
        return (NULL);
    }
    return (object);
}