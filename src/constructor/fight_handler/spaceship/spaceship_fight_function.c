/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include "components/fight_handler/fight_handler.h"
#include "spaceship/ship.h"

void rpg_fight_handler_handle_dodge_spaceship(game_object_t *object, int dodge, \
scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);

    if (ship == NULL)
        return;
    ship->repair_statue++;
    ship->dodge_value = dodge;
}

void rpg_fight_handler_repair_spaceship(game_object_t *object, scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);

    if (ship == NULL)
        return;
    sfText_setString(ship->repair_turn_left, "Repair statue; Unable");
    if (ship->repair_value + ship->hp > ship->max_hp)
        ship->hp = ship->max_hp;
    else
        ship->hp += ship->repair_value;
    ship->repair_statue = 0;    
}

int rpg_fight_handler_spaceship_get_repair_statue(scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);

    if (ship == NULL)
        return (0);
    return (ship->repair_statue);
}

void rpg_fight_handler_remove_spaceship_life(game_object_t *object, \
scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);
    int damage = rpg_ennemy_get_damage(object, scene);

    if (ship == NULL)
        return;
    if (rpg_fight_handler_dodge_handle(ship->dodge_value) == 1)
        return;
    if (ship->shield + ship->hp <= damage) {
        ship->hp = 0;
        return;
    } else if (ship->shield >= damage) {
        ship->shield -= damage;
        return;
    }
    if (ship->hp > damage - ship->shield) {
        ship->hp -= damage - ship->shield;
        ship->shield = 0;
    }
}