/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** attack_anim
*/

#include "rpg.h"

static void player_got_a_hit(rpg_t *rpg, entity_t *player, entity_t *monster)
{
    int damage = rpg->data->tot_stat.damage;

    if (player->attack.crit)
        damage *= 2;
    if (monster->id != SKELETON)
        return hit_player(rpg, damage, monster);
    if (monster->state != SHIELD)
        return hit_player(rpg, damage, monster);
    if (player->attack.crit)
        return hit_player(rpg, damage, monster);
    player->roll.cd = 0;
    monster->state = ATTACK;
    add_info_text(rpg, sfRed,
        (VEC){monster->pos.x, monster->pos.y - 50}, my_strdup("miss"));
}

static void player_attack(rpg_t *rpg, entity_t *player)
{
    sfFloatRect intersection = {0};
    entity_t **monsters = rpg->monsters;
    sfFloatRect rect = {player->pos.x, player->pos.y - 24, 80, 48};

    if (player->dir == -1)
        rect.left -= 80;
    for (entity_t *node = *monsters; node; node = node->next)
        if (sfFloatRect_intersects(&node->rect, &rect, &intersection) ==
            sfTrue && node->id != BALL && node->id != SLASH)
            player_got_a_hit(rpg, player, node);
}

static void skeleton_attack(rpg_t *rpg, entity_t *monster)
{
    sfFloatRect intersection = {0};
    sfFloatRect rect = {monster->pos.x,
        monster->pos.y - monster->rect.height / 2, 95, monster->rect.height};

    if (monster->dir == -1)
        rect.left -= 95;
    if (sfFloatRect_intersects(&rpg->player->rect,
        &rect, &intersection) == sfTrue) {
        hit_player(rpg, monster->damage, rpg->player);
        rpg->player->health.cd = 0;
    }
}

void attack_anim(rpg_t *rpg, entity_t *entity)
{
    if (entity->id == PLAYER)
        player_attack(rpg, entity);
    if (entity->id == SKELETON)
        skeleton_attack(rpg, entity);
    if (entity->id == EYE)
        eye_attack(rpg, entity);
    return_to_idle(rpg, entity);
}
