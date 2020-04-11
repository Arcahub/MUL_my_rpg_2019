/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#include "item/item_id.h"
#include "stdbool.h"
#include "SFML/Graphics/Text.h"

#ifndef SHIP_H_
#define SHIP_H_

typedef struct ship {
    bool in_fight;
    int hp;
    int shield;
    item_id equiped_weapon;
    int damage;
    int repair_value;
    int repair_statue;
    int dodge_value;
    int member_in_ship;
    sfText *hp_text;
    sfText *shield_text;
} space_ship_t;

#endif /* !SHIP_H_ */
