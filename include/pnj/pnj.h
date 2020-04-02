/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef PNJ_H_
#define PNJ_H_

typedef enum {
    QUEST,
    MARKETPLACE,
    NONE
} pnj_type;

typedef struct pnj {
    char *name;
    char **dialog;
    pnj_type type;
    void *extend;
} pnj_t;

#endif /* !PNJ_H_ */
