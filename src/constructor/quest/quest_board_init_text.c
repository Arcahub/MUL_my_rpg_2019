/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_board_create_from_conf.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/quest/quest.h"
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "const.h"
#include "components/get_from_config.h"
#include "components/quest/board.h"

static const char *FONT_PATH_LOG = "templates/font/Roboto-LightItalic.ttf";

static quest_board_t *rpg_quest_board_init_actual_step(step_t *tmp, int x, \
quest_board_t *board, char *tmp2)
{
    if (tmp != NULL && tmp->validated == 0) {
        tmp2 = my_strcat("Actual step: ", tmp->description);
        board->actual_step = init_text(tmp2, 75, 300 + (x * 50), \
        (char *) FONT_PATH_LOG);
        if (board->actual_step == NULL)
            return (NULL);
        sfText_setCharacterSize(board->actual_step, 30);
        free(tmp2);
    }
    return (board);
}

quest_board_t *rpg_quest_board_init_text(step_t *tmp, \
quest_board_t *board)
{
    int x = 0;
    char *tmp2 = NULL;

    for (; tmp && tmp->validated == 1 && x < board->number_of_step; \
    tmp = tmp->next, x++) {
        tmp2 = my_strcat(tmp->description, " (COMPLETED)");
        board->steps[x] = init_text(tmp2, 75, 200 + (x * 50), \
        (char *) FONT_PATH_LOG);
        if (board->steps[x] == NULL)
            return (NULL);
        sfText_setCharacterSize(board->steps[x], 30);
        free(tmp2);
        board->step_to_draw++;
    }
    board = rpg_quest_board_init_actual_step(tmp, x, board, tmp2);
    return (board);
}