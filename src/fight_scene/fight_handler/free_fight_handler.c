/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "fight_scene/fight_handler.h"
#include <stdlib.h>

void rpg_fight_handler_free_extend(fight_handler_t *fight_handler)
{
    if (fight_handler == NULL)
        return;
    if (!fight_handler->id)
        free(fight_handler->id);
    if (!fight_handler)
        free(fight_handler);
}
