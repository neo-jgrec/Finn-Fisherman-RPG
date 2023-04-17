/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** attack_anim
*/

#include "rpg.h"

static void player_attack(rpg_t *rpg, entity_t *player)
{
    sfFloatRect intersection = {0};
    entity_t **monsters = rpg->monsters;
    sfFloatRect rect = {player->pos.x, player->pos.y - 16, 48, 32};

    if (player->dir == -1)
        rect.left -= 48;
    for (entity_t *node = *monsters; node; node = node->next) {
        if (sfFloatRect_intersects(&node->rect, &rect, &intersection) ==
            sfTrue) {
            hit_player(rpg, 200, node);
        }
    }
}

static void monster_1_attack(rpg_t *rpg, entity_t *monster)
{
    sfFloatRect intersection = {0};
    sfFloatRect rect = {monster->pos.x, monster->pos.y - 16, 48, 32};

    if (monster->dir == -1)
        rect.left -= 48;
    if (sfFloatRect_intersects(&rpg->player->rect,
        &rect, &intersection) == sfTrue) {
        hit_player(rpg, 40, rpg->player);
        rpg->player->health.cd = 0;
    }
}

void attack_anim(rpg_t *rpg, entity_t *entity)
{
    if (entity->id == PLAYER)
        player_attack(rpg, entity);
    if (entity->id == MONSTER_1)
        monster_1_attack(rpg, entity);
    return_to_idle(rpg, entity);
}
