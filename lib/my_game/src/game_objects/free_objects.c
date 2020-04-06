/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_objects
*/

#include "my_game.h"
#include <stdlib.h>

void free_extend(void *);

void free_anim(game_object_t *object)
{
    int i = 0;
    int j = 0;

    if (object->anim == NULL)
        return;
    for (; object->anim[i].sound_buffer != NULL; i++) {
        for (j = 0; object->anim[i].frames_key[j]; j++)
            free(object->anim[i].frames_key[j]);
        free(object->anim[i].frames_key[j]);
        free(object->anim[i].frames_key);
        sfSoundBuffer_destroy(object->anim[i].sound_buffer);
    }
    if (object->anim[i].sound_buffer != NULL)
        free(object->anim[i].sound_buffer);
    free(object->anim);
}

void free_sprite_and_texture(game_object_t *object)
{
    if (object->sprite != NULL)
        sfSprite_destroy(object->sprite);
    if (object->texture != NULL)
        sfTexture_destroy(object->texture);
}

void destroy_game_object(scene_t *scene, game_object_t *object)
{
    game_object_t *tmp = scene->objects_list;
    static int i = 0;

    if (scene->objects_list == object)
        scene->objects_list = object->next;
    else {
        for (; tmp && tmp->next != object; tmp = tmp->next);
        if (tmp)
            tmp->next = object->next;
    }
    free_sprite_and_texture(object);
    if (object->sound_effect != NULL) {
        sfSound_stop(object->sound_effect);
        sfSound_destroy(object->sound_effect);
    }
    if (object->delta_t != NULL)
        sfClock_destroy(object->delta_t);
    free_anim(object);
    if (object->free_extend != NULL)
        object->free_extend(object->extend);
    free(object);
}

void destroy_object_list(scene_t *scene)
{
    while (scene->objects_list)
        destroy_game_object(scene, scene->objects_list);
}