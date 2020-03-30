/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_graph
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

#ifndef SPACE_H_
#define SPACE_H_

game_object_t *generate_space(void);
game_object_t *move_on_map(scene_t *scene, sfVector2f move);

#endif /* !SPACE_H_ */
