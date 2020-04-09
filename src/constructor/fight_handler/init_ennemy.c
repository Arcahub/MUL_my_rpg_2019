/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_ennemy.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/fight_handler/ennemy.h"
#include "components/fight_handler/fight_handler.h"

ennemy_t *rpg_ennemy_extend_create_from_conf(game_object_t *object, \
json_object_t *js)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    if (ennemy == NULL)
        return (NULL);
    if (!get_int_from_conf(js, &ennemy->equiped_weapon, "weapon_id") ||
    !get_int_from_conf(js, &ennemy->damage, "damage") || 
    !get_int_from_conf(js, &ennemy->hp, "hp") || 
    !get_int_from_conf(js, &ennemy->shield, "shield") ||
    !get_str_from_conf(js, &ennemy->name, "name"))
        return (NULL);
    return (ennemy);
}

game_object_t *rpg_ennemy_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    sfVector2f pos = {0, 0};
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), pos, ENNEMY);

    if (object == NULL)
        return (NULL);
    if (!get_vector2f_from_conf(js, &pos, "pos"))
        return (NULL);
    object->pos = pos;
    object->extend = (void *) rpg_ennemy_extend_create_from_conf(object, js);
    if (object == NULL || object->extend == NULL) {
        rpg_ennemy_destroy((ennemy_t *) object->extend);
        destroy_game_object(scene, object);
        return (NULL);
    }
    return (object);
}