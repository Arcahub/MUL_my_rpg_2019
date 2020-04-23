/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "components/get_from_config.h"
#include "item/inventory.h"
#include "item/item_path.h"
#include "my.h"
#include "tmp_font.h"
#include <stdlib.h>

static inventory_t *rpg_inventory_init_item(inventory_t *item, \
json_object_t *js, int number)
{
    item->item_name = my_strdup(get_str_from_conf(js, "name"));
    item->item_description = my_strdup(get_str_from_conf(js, "description"));
    item->item_number = number;
    item->selected = 0;
    if (!get_int_from_conf(js, (int *) &item->id, "item_id")) {
        free(item);
        return (NULL);
    }
    return (item);
}

static inventory_t *rpg_inventory_add_new_item_from_conf(inventory_t *last, \
char *path, int number)
{
    json_object_t *js = json_create_from_file(path);
    inventory_t *item = malloc(sizeof(inventory_t));

    if (js == NULL || item == NULL)
        return (NULL);
    item->next = last;
    if (!rpg_inventory_init_item(item, js, number))
        return (NULL);
    item->sprite = sfSprite_create();
    item->texture = sfTexture_createFromFile(get_str_from_conf(js, \
    "path"), NULL);
    if (item->sprite == NULL || item->texture == NULL)
        return (NULL);
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    item = rpg_inventory_set_item_type(item, js);
    item = rpg_item_create_text(item);
    json_object_destroy(js);
    return (item);
}

inventory_t *rpg_inventory_add_item(inventory_t *last, int number, item_id id)
{
    inventory_t *tmp = NULL;
    char *path = NULL;

    if (ITEM_PATHS[id] != NULL)
        path = (char *) ITEM_PATHS[id];
    for (tmp = last; tmp; tmp = tmp->next) {
        if (tmp->id == id) {
            tmp->item_number += number;
            rpg_item_update_text(tmp);
            return (last);
        }
    }
    return (rpg_inventory_add_new_item_from_conf(last, \
    path, number));
}