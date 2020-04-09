/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef ENNEMY_H_
#define ENNEMY_H_

#include "item/item_id.h"

typedef struct ennemy {
    char *name;
    int hp;
    int shield;
    item_id equiped_weapon;
    int damage;
} ennemy_t;

#endif /* !ENNEMY_H_ */
