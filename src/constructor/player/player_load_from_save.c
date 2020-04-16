/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_load_from_save
*/

#include "player.h"
#include <unistd.h>
#include <fcntl.h>

player_t *player_load_from_save_fd(int fd)
{
    player_t *player = player_create();
    ssize_t size = 0;

    if (player == NULL)
        return (NULL);
    else if (fd < 0) {
        player_destroy(player);
        return (NULL);
    }
    size = read(fd, player, sizeof(player_t));
    if (size != sizeof(player_t)) {
        player_destroy(player);
        return (NULL);
    }
    return (player);
}

player_t *player_load_from_save_path(char *path)
{
    int fd = open(path, O_RDONLY);
    player_t *player = NULL;

    if (fd < 0)
        return (NULL);
    player = (player_load_from_save_fd(fd));
    close(fd);
    return (player);
}