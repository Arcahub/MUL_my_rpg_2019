/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_from_config
*/

#ifndef GET_FROM_CONFIG_H_
#define GET_FROM_CONFIG_H_

#include "my_game.h"
#include "my_json.h"

bool get_vector2f_from_conf(json_object_t *, sfVector2f *, char *);
bool get_intrect_from_conf(json_object_t *, sfIntRect *, char *);
char *get_path_from_conf(json_object_t *);

#endif /* !GET_FROM_CONFIG_H_ */
