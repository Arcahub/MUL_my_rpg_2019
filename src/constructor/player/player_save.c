/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_save
*/

#include "player.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void player_save(void *pt)
{
    player_t *player = pt;
    FILE *fd = fopen("save/save", "wb");

    if (fd == NULL)
        return;
    fwrite(player, sizeof(player_t), 1, fd);
    fclose(fd);
}