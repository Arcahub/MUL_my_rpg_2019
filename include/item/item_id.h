/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef ITEM_ID_H
#define ITEM_ID_H

static const char *ITEM_NAME[] = {
    "Basic Canoon",
    "Laser Canoon",
    "Plasma Canoon",
    "Basic Rocket",
    "Plasma Rocket"
};

typedef enum {
    BASIC_CANON,
    LASER_CANON,
    PLASMA_CANON,
    BASIC_ROCKET,
    PLASMA_ROCKET,
    REPAIRING_ITEM,
} item_id;

#endif /* !ITEM_ID_H */
