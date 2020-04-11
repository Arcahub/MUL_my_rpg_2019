/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game
*/

#include "my_game.h"
#include "my_rpg.h"
#include "player.h"
#include "components/window/window_constructor.h"
#include <stdlib.h>
#include <SFML/Audio.h>

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    player_t *player = malloc(sizeof(player_t));

    if (game == NULL || player == NULL)
        return (NULL);
    game->player = player;
    player->galaxie_dest = (sfVector2f) {960, 540};
    game->window = create_window_from_conf("./config/window.json");
    if (game->window == NULL)
        return (NULL);
    return (game);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window->window);
    free(game->window->name);
    free(game->window);
    free(game);
}