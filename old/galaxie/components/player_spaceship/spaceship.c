/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** spaceship
*/

#include "my_game.h"
#include "my_rpg.h"

game_object_t *rpg_galaxie_create_ship(void)
{
    game_object_t *object = NULL;

    object = create_game_object(object, "templates/menu/ship1.png", \
    (sfVector2f) {WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 100}, SPACESHIP);
    if (object == NULL)
        return (NULL);
    return (object);
}