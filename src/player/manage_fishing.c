/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_fishing
*/

#include "rpg.h"

int manage_fishing(entity_t *player, rpg_t *rpg)
{
    player->health.fish_cd -= rpg->win->deltaT;
    if (rpg->input->interact.press &&
        player->health.on_fish_spot &&
        player->grounded) {
        player->state = FISHING;
        rpg->input->interact.press = 0;
        player->dir = 1;
        player->health.fish_cd = my_random(0, 100) / 10;
    }
    if (player->state != FISHING)
        return 0;
    return 1;
}
