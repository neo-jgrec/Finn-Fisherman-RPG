/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_monster_collision
*/

#include "rpg.h"

void check_monster_collision(rpg_t *rpg, entity_t *player)
{
    sfFloatRect rect = {0};
    entity_t **monsters = rpg->monsters;

    for (entity_t *node = *monsters; node; node = node->next) {
        if (node->id == SHROOM && node->health.health > 0 &&
            sfFloatRect_intersects(&player->rect, &node->rect, &rect) &&
                rect.width > 20) {
            hit_player(rpg, 25, player);
            return;
        }
    }
}