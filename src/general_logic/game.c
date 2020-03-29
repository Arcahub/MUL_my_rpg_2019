/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game
*/

#include "my_game.h"
#include "my_rpg.h"
#include "galaxie/galaxie.h"
#include "main_menu/main_menu.h"
#include <stdlib.h>
#include <SFML/Audio.h>

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return (NULL);
    game->difficulty = 10;
    game->window = init_window();
    if (game->window == NULL || game->score == NULL)
        return (NULL);
    game->scene_loop[MAIN_MENU_SCENE] = &rpg_main_menu_loop;
    game->scene_loop[GALAXIE_SCENE] = &rpg_galaxie_loop;
    return (game);
}

void destroy_game(game_t *game)
{
    sfMusic_destroy(game->music);
    sfRenderWindow_destroy(game->window->window);
    free(game->window);
    free(game);
}