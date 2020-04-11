/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/fight_handler/fight_handler.h"
#include "spaceship/ship.h"
#include "components/fight_handler/ennemy.h"

ennemy_t *rpg_ennemy_get_extend(scene_t *scene)
{
    game_object_t *tmp = NULL;
    ennemy_t *ennemy = NULL;

    if (scene->objects_list == NULL)
        return (NULL);
    for (tmp = scene->objects_list; tmp && tmp->type != ENNEMY; \
    tmp = tmp->next);
    if (tmp->type != ENNEMY)
        return (NULL);
    ennemy = (ennemy_t *) tmp->extend;
    if (ennemy == NULL)
        return (NULL);
    return (ennemy);
}

space_ship_t *rpg_spaceship_get_extend(scene_t *scene)
{
    game_object_t *tmp = NULL;
    space_ship_t *ship = NULL;

    if (scene->objects_list == NULL)
        return (NULL);
    for (tmp = scene->objects_list; tmp && tmp->type != SPACESHIP; \
    tmp = tmp->next);
    if (tmp->type != SPACESHIP)
        return (NULL);
    ship = (space_ship_t *) tmp->extend;
    if (ship == NULL)
        return (NULL);
    return (ship);
}