/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_qest_from_save
*/

#include "components/quest/quest_conf.h"
#include "components/quest/quest.h"
#include "components/quest/board.h"

void rpg_quest_load_from_save(quest_t *quest)
{
    int step_id = quest->actual_step;

    *quest = rpg_quest_get_from_conf(QUEST_CONF[quest->id], NULL);
    quest->actual_step = step_id;
    quest->state = TAKEN;
}