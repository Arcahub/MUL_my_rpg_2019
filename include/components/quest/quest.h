/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** quest_handler
*/

#ifndef QUEST_HANDLER_H_
#define QUEST_HANDLER_H_

#include "my_game.h"

typedef enum {
    UNTAKEN,
    TAKEN,
    ACHIEVED
} quest_state;

typedef enum {
    DIALOG,
    FIGHT,
    REACH
} step_type;

typedef struct step {
    sfVector2f pos;
    step_type step_type;
    int step_number;
    bool validated;
    char *description;
    step_t *next;
} step_t;

typedef struct quest {
    quest_state state;
    char *name;
    int number_of_step;
    int reward;
    int actual_step;
    step_t *step;
} quest_t;

#endif /* !QUEST_HANDLER_H_ */
