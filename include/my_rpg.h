/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#define ABS(x)  x = (x < 0) ? - x : x

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "const.h"
#include "my_game.h"
#include "button_function.h"
#include "item/inventory.h"
#include "tmp.h"

typedef struct game_object game_object_t;

typedef enum {
    MAIN_MENU_SCENE,
    OPTION_SCENE,
    INFOS_SCENE,
    END_SCENE,
    IN_GAME_MENU_SCENE,
    GALAXIE_SCENE,
    FIGHT_SCENE,
    FIGHT_PAUSE_SCENE,
    NULL_SCENE,
} scene_index;

int rpg_galaxie_loop(game_t *game, sfRenderWindow *window);
int rpg_end_menu_loop(game_t *game, sfRenderWindow *window);
int rpg_options_menu_loop(game_t *game, sfRenderWindow *window);
int rpg_infos_menu_loop(game_t *game, sfRenderWindow *window);
int rpg_main_menu_loop(game_t *game, sfRenderWindow *window);

game_t *init_game();
void destroy_game(game_t *);
int check_error(int, char **, char **);

#endif /* !MY_RUNNER_H_ */
