/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "my_game.h"
#include "item/inventory.h"

inventory_t *rpg_inventory_init(char *path)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (inventory == NULL)
        return (NULL);
    return (inventory);
}