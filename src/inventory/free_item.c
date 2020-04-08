/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "my_json.h"
#include "components/get_from_config.h"
#include "my_game.h"
#include "item/inventory.h"

void free_item(inventory_t *item)
{
    if (item == NULL)
        return;
    if (!item->item_name && !item->item_description) {
        free(item->item_name);
        free(item->item_description);
    }
    if (!item->sprite && !item->texture) {
        sfSprite_destroy(item->sprite);
        sfTexture_destroy(item->texture);
    }
    if (!item)
        free(item);
}