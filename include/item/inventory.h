/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "my_game.h"

typedef struct inventory {
    char **item_name;
    char **item_description;
    int *item_id;
    sfVector2f **item_pos;
    sfIntRect **item_rect;
    void (*free_inventory)(void *);
} inventory_t;

#endif /* !INVENTORY_H_ */
