/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include "my_json.h"
#include "unistd.h"
#include "components/fight_handler/fight_handler.h"
#include "spaceship/ship.h"
#include "components/fight_handler/ennemy.h"

int rpg_fight_handler_dodge_handle(int number)
{
    int num = (rand() % (100 - 0 + 1)) + 0;

    if (num < number * 10)
        return (1);
    return (0);
}