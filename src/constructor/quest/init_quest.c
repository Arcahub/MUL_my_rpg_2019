/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest->c
*/

#include "my_json.h"
#include <stdlib.h>
#include "components/get_from_config.h"
#include "components/quest/quest.h"

quest_t *rpg_init_quest(game_t *game)
{
    quest_t *quest = malloc(sizeof(quest_t));

    if (quest == NULL)
        return (NULL);
    quest->state = UNTAKEN;
    quest->actual_step = 1;
    quest->step = NULL;
    return (quest);
}