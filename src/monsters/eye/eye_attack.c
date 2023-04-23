/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** eye_attack
*/

#include "rpg.h"

void eye_attack(rpg_t *rpg, entity_t *monster)
{
    sfFloatRect intersection = {0};
    sfFloatRect rect = {monster->pos.x,
        monster->pos.y - monster->rect.height,
            monster->rect.width * 2, monster->rect.height * 2};

    if (monster->dir == -1)
        rect.left -= monster->rect.width * 2;
    if (sfFloatRect_intersects(&rpg->player->rect,
        &rect, &intersection) == sfTrue) {
        hit_player(rpg, monster->damage, rpg->player);
        rpg->player->health.cd = 0;
    }
}
