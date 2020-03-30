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
    game->window = init_window();
    if (game->window == NULL)
        return (NULL);
    game->scene_loop[MAIN_MENU_SCENE] = &rpg_main_menu_loop;
    game->scene_loop[GALAXIE_SCENE] = &rpg_galaxie_loop;
    game->scene_loop[INFOS_SCENE] = &rpg_infos_menu_loop;
    game->scene_loop[OPTION_SCENE] = &rpg_options_menu_loop;
    game->scene_loop[END_SCENE] = &rpg_end_menu_loop;
    return (game);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window->window);
    free(game->window);
    free(game);
}