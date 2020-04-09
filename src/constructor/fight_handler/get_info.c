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
#include "spaceship/ship.h"

item_id rpg_spaceship_get_equiped_weapon(game_object_t *object)
{
    game_object_t *tmp = NULL;
    space_ship_t *ship = NULL;
    item_id weapon = 0;

    if (object == NULL)
        return (weapon);
    for (tmp = object; tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != SPACESHIP)
        return (weapon);
    ship = (space_ship_t *) tmp->extend;
    weapon = ship->equiped_weapon;
    return (weapon);
}

int rpg_spaceship_get_equip_size(game_object_t *object)
{
    game_object_t *tmp = NULL;
    space_ship_t *ship = NULL;
    int member_in_ship = 0;

    if (object == NULL)
        return (member_in_ship);
    for (tmp = object; tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != SPACESHIP)
        return (member_in_ship);
    ship = (space_ship_t *) tmp->extend;
    member_in_ship = ship->member_in_ship;
    return (member_in_ship);
}

int rpg_spaceship_get_damage(game_object_t *object)
{
    game_object_t *tmp = NULL;
    space_ship_t *ship = NULL;
    int damage = 0;

    if (object == NULL)
        return (damage);
    for (tmp = object; tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != SPACESHIP)
        return (damage);
    ship = (space_ship_t *) tmp->extend;
    damage = ship->damage;
    return (damage);
}

int rpg_spaceship_get_repair_value(game_object_t *object)
{
    game_object_t *tmp = NULL;
    space_ship_t *ship = NULL;
    int repair_value = 0;

    if (object == NULL)
        return (repair_value);
    for (tmp = object; tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != SPACESHIP)
        return (repair_value);
    ship = (space_ship_t *) tmp->extend;
    repair_value = ship->repair_value;
    return (repair_value);
}

int rpg_spaceship_get_dodge_value(game_object_t *object)
{
    game_object_t *tmp = NULL;
    space_ship_t *ship = NULL;
    int dodge_value = 0;

    if (object == NULL)
        return (dodge_value);
    for (tmp = object; tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != SPACESHIP)
        return (dodge_value);
    ship = (space_ship_t *) tmp->extend;
    dodge_value = ship->dodge_value;
    return (dodge_value);
}