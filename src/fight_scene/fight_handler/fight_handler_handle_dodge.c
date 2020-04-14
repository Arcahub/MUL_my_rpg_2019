/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include <unistd.h>
#include <stdlib.h>

int rpg_fight_handler_dodge_handle(int number)
{
    int num = (rand() % (100 - 0 + 1)) + 0;

    if (num < number * 10)
        return (1);
    return (0);
}