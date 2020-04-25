/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_create
*/

#include "player.h"
#include <stdlib.h>

player_t *player_create(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (NULL);
    player->galaxie_dest = (sfVector2f) {0, 0};
    player->item_list = NULL;
    return (player);
}