/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "components/get_from_config.h"
#include "item/inventory.h"
#include <stdlib.h>

void rpg_inventory_destroy(void *pt)
{
    inventory_t *item = pt;
    inventory_t *tmp = NULL;

    if (item == NULL)
        return;
    for (; item; item = tmp) {
        tmp = item->next;
        free_item(item);
    }
}

void free_item(inventory_t *item)
{
    if (item == NULL)
        return;
    if (item->item_name && item->item_description) {
        free(item->item_name);
        free(item->item_description);
    }
    if (item->sprite && item->texture) {
        sfSprite_destroy(item->sprite);
        sfTexture_destroy(item->texture);
    }
    free_text(item->text[0]);
    free_text(item->text[1]);
    free_text(item->text[2]);
    free(item);
}