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
#include "stdio.h"

static inventory_t *rpg_inventory_set_item_type(inventory_t *item, json_object_t *js)
{
    if (!get_int_from_conf(js, &item->type, "item_type")) {
        free(item);
        return (NULL);
    }
    if (item->type == WEAPON && !get_int_from_conf(js, \
    &item->damage, "damage")) {
        free(item);
        return (NULL);   
    }
    if (item->type == REPAIR && !get_int_from_conf(js, \
    &item->repair_value, "repair_value")) {
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
    item->item_name = my_strdup(get_str_from_conf(js, "name"));
    item->item_description = my_strdup(get_str_from_conf(js, "description"));
    item->item_number = number;
    item->next = last;
    if (!get_int_from_conf(js, &item->id, "item_id")) {
        free(item);
        return (NULL);
    }
    item->sprite = sfSprite_create();
    item->texture = sfTexture_createFromFile(get_str_from_conf(js, "path"), NULL);
    if (item->sprite == NULL || item->texture == NULL)
        return (NULL);
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    item = rpg_inventory_set_item_type(item, js);
    return (item);
}

inventory_t *rpg_inventory_add_item(inventory_t *last, char *path, int number, \
item_id id)
{
    inventory_t *tmp = NULL;

    for (tmp = last; tmp; tmp = tmp->next) {
        if (tmp->id == id) {
            tmp->item_number += number;
            return (last);
        }
    }
    return (rpg_inventory_add_new_item_from_conf(last, \
    path, number));
}