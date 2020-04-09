/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_ennemy.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/fight_handler/ennemy.h"
#include "components/fight_handler/fight_handler.h"

void rpg_ennemy_destroy(ennemy_t *ennemy)
{
    if (ennemy == NULL)
        return;
    if (!ennemy->name)
        free(ennemy->name);
    if (!ennemy)
        free(ennemy);
}