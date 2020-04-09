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

void rpg_fight_handler_handle_dodge(game_object_t *object, int dodge)
{
    game_object_t *tmp = NULL;
    space_ship_t *ship = NULL;

    if (dodge == 0)
        return;
    if (object == NULL)
        return;
    for (tmp = object; tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != SPACESHIP)
        return;;
    ship = (space_ship_t *) tmp->extend;
    ship->dodge_value = dodge;
}

void rpg_fight_handler_repair_spaceship(game_object_t *object)
{
    game_object_t *tmp = NULL;
    space_ship_t *ship = NULL;

    if (object == NULL)
        return;
    for (tmp = object; tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != SPACESHIP)
        return;;
    ship = (space_ship_t *) tmp->extend;
    if (ship->repair_value + ship->hp > 100)
        ship->hp = 100;
    else
        ship->hp += ship->repair_value;
    ship->repair_statue = 0;    
}

void rpg_fight_handler_remove_spaceship_life(game_object_t *object, int damage)
{
    game_object_t *tmp = NULL;
    space_ship_t *ship = NULL;
    int x = 0;

    if (object == NULL)
        return;
    for (tmp = object; tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != SPACESHIP)
        return;;
    ship = (space_ship_t *) tmp->extend;
    if (ship->shield + ship->hp <= damage)
        ship->hp = 0;
    if (ship->shield >= damage)
        ship->shield -= damage;
    x = damage - ship->shield;
    if (ship->hp > x) {
        ship->hp -= x;
        ship->shield = 0;
    }
}

void rpg_fight_handler_remove_ennemy_life(game_object_t *object)
{
    game_object_t *tmp = NULL;
    ennemy_t *ennemy = NULL;
    int x = 0;
    int damage = rpg_spaceship_get_damage(object);

    if (object == NULL)
        return;
    for (tmp = object; tmp->type != ENNEMY; tmp = tmp->next);
    if (tmp->type != ENNEMY)
        return;;
    ennemy = (ennemy_t *) tmp->extend;
    if (ennemy->shield + ennemy->hp <= damage)
        ennemy->hp = 0;
    if (ennemy->shield >= damage)
        ennemy->shield -= damage;
    x = damage - ennemy->shield;
    if (ennemy->hp > x) {
        ennemy->hp -= x;
        ennemy->shield = 0;
    }
}
void rpg_fight_handler_make_ennemy_play(game_object_t *object, scene_t *scene)
{
    return;
}