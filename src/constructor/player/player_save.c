/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_save
*/

#include "player.h"
#include <unistd.h>
#include <fcntl.h>

void player_save(void *pt)
{
    player_t *player = pt;
    int fd = open("save/save", O_CREAT | O_WRONLY, 0666);

    if (fd < 0)
        return;
    write(fd, player, sizeof(player_t));
}