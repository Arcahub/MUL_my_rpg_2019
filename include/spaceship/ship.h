/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef SHIP_H_
#define SHIP_H_

#include "item/item_id.h"

typedef struct ship {
    int hp;
    int shield;
    item_id equiped_weapon;
    int damage;
    int repair_value;
    bool skill_statue;
    bool repair_statue;
    int dodge_value;
    int member_in_ship;
} space_ship_t;

#endif /* !SHIP_H_ */
