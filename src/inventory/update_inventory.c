/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** update_inventory.c
*/

#include "my_game.h"
#include "item/inventory.h"

inventory_t *rpg_update_inventory(game_object_t *object, char *path)
{
    if (object == NULL || (inventory_t *) object->extend == NULL)
        return (NULL);
    return ((inventory_t *) object->extend);
}