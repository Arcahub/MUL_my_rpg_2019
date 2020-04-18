/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest.c
*/

#include "my_json.h"
#include <stdlib.h>
#include "components/get_from_config.h"
#include "components/quest/quest.h"
#include <unistd.h>
#include <fcntl.h>

quest_t *rpg_init_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));

    if (quest == NULL)
        return (NULL);
    quest->state = 0;
    quest->name = NULL;
    quest->number_of_step = 0;
    quest->reward_item_number = 0;
    quest->reward_item = 0;
    quest->reward_money = 0;
    quest->actual_step = 0;
    quest->step = NULL;
    quest->id = 0;
    return (quest);
}

quest_t *quest_load_from_save_fd(int fd)
{
    quest_t *quest = rpg_init_quest();
    ssize_t size = 0;

    if (quest == NULL)
        return (NULL);
    else if (fd < 0) {
        rpg_destroy_quest(quest);
        return (NULL);
    }
    size = read(fd, quest, sizeof(quest_t));
    if (size != sizeof(quest_t)) {
        rpg_destroy_quest(quest);
        return (NULL);
    }
    return (quest);
}

quest_t *quest_load_from_save_path(char *path)
{
    int fd = open(path, O_RDONLY);
    quest_t *quest = NULL;

    if (fd < 0)
        return (NULL);
    quest = (quest_load_from_save_fd(fd));
    close(fd);
    return (quest);
}

void quest_save(void *pt)
{
    quest_t *quest = pt;
    int fd = open("save/quest", O_CREAT | O_WRONLY, 0666);

    if (fd < 0)
        return;
    write(fd, quest, sizeof(quest_t));
}