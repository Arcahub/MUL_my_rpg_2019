/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game
*/

#include "my_game.h"
#include "my_rpg.h"
#include <stdlib.h>
#include <SFML/Audio.h>

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return (NULL);
    game->window = create_window_from_conf("./config/window.json");
    if (game->window == NULL)
        return (NULL);
    return (game);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window->window);
    free(game->window);
    free(game);
}