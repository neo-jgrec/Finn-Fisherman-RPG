/*
** EPITECH PROJECT, 2023
** destroy_rpg
** File description:
** destroy_rpg
*/

#include "rpg.h"

void destroy_rpg(rpg_t *rpg)
{
    if (!rpg)
        return;
    free_fishing(rpg);
    free_quest(rpg->quests);
    free_song(rpg->music);
    free_window(rpg->win);
}
