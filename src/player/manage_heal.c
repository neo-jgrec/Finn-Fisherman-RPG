/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_heal
*/

#include "rpg.h"

static void check_heal(player_t *player, rpg_t *rpg)
{
    if (player->state != HEALING &&
        player->health.save_heal != rpg->input->heal.press
        && player->roll.cd > 0.1 && player->grounded &&
        player->health.potion != 0) {
        player->health.potion -= 1;
        player->state = HEALING;
    }
}

void manage_heal(player_t *player, rpg_t *rpg)
{
    player->health.damage_cd += rpg->win->deltaT;
    player->health.not_moving += rpg->win->deltaT;
    player->health.cd += rpg->win->deltaT;
    if (player->hor != 0)
            player->health.not_moving = 0;
    if (player->health.not_moving > 0.15)
        player->health.cd = 0;
    check_heal(player, rpg);
    player->health.save_heal = rpg->input->heal.press;
}
