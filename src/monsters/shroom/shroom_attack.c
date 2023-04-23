/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** shroom_attack
*/

#include "rpg.h"

static void attack_1(rpg_t *rpg, entity_t *monster)
{
    sfFloatRect intersection = {0};
    sfFloatRect rect = {monster->pos.x,
        monster->pos.y - monster->rect.height / 2,
            monster->rect.width * 2, monster->rect.height};

    if (monster->dir == -1)
        rect.left -= monster->rect.width * 2;
    if (sfFloatRect_intersects(&rpg->player->rect,
        &rect, &intersection) == sfTrue) {
        hit_player(rpg, monster->damage, rpg->player);
        rpg->player->health.cd = 0;
    }
}

static void attack_2(rpg_t *rpg, entity_t *monster)
{
    monster_stat_t ms = {0};

    ms.pos = monster->pos;
    ms.life = 1;
    ms.damage = monster->damage / 3 * 2;
    add_monster(rpg, BALL, ms);
    (*rpg->monsters)->dir = monster->dir;
    monster->roll.cd = -1;
}

void shroom_attack(rpg_t *rpg, entity_t *monster)
{
    if (monster->attack.crit == 0)
        attack_1(rpg, monster);
    if (monster->attack.crit == 1)
        attack_2(rpg, monster);
}
