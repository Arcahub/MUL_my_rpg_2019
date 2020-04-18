/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** free_text.c
*/

#include "SFML/Graphics.h"

void free_text(sfText *text)
{
    if (text != NULL) {
        sfText_destroy(text);
        sfFont_destroy((sfFont *) sfText_getFont(text));
    }
}