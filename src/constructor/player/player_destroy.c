/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_destroy
*/

#include "player.h"
#include <stdlib.h>

void player_destroy(player_t *player)
{
    free(player);
}