/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef SHIP_H_
#define SHIP_H_

#include "item_id.h"

typedef struct ship {
    int hp;
    int shield;
    item_id equiped_weapon;
    int weapon_level;
    int weapon_damage;
    bool skill_statue;
    bool repair_statue;
} ship_t;

#endif /* !SHIP_H_ */
