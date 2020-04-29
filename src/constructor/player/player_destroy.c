/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_destroy
*/

#include "player.h"
#include "components/quest/quest.h"
#include <stdlib.h>

void player_destroy(player_t *player)
{
    rpg_destroy_quest(&player->quest);
    free(player);
}