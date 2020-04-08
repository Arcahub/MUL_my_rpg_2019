/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "my_game.h"
#include "item_id.h"

typedef enum {
    WEAPON,
    REPAIR,
    QUEST
} item_type;

typedef struct inventory {
    char *item_name;
    char *item_description;
    item_id id;
    item_type type;
    int item_number;
    bool selected;
    sfIntRect box;
    sfSprite *sprite;
    sfTexture *texture;
    int price;
    int damage;
    int repair_value;
    struct inventory *next;
} inventory_t;

void free_item(inventory_t *item);
void rpg_inventory_remove_item(inventory_t *item, item_id id, int number);
inventory_t *rpg_inventory_add_item(inventory_t *last, char *path, int number, \
item_id id);
#endif /* !INVENTORY_H_ */
