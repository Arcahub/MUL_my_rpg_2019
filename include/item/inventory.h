/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "my_game.h"
#include "my_json.h"
#include "item/item_id.h"

typedef enum {
    WEAPON_ITEM,
    REPAIR_ITEM,
    QUEST_ITEM
} item_type;

typedef struct inventory {
    sfText *text[3];
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
inventory_t *rpg_inventory_add_item(inventory_t *, int, item_id);
bool rpg_update_inventory(game_object_t *object, scene_t *scene);
bool rpg_inventory_get_click_on_item(game_object_t *object, void *pt);
void rpg_inventory_draw(sfRenderWindow *window, game_object_t *object);
void rpg_inventory_destroy(void *pt);
bool rpg_is_item_in_inventory(game_object_t *object, item_id id, int number);

#endif /* !INVENTORY_H_ */
