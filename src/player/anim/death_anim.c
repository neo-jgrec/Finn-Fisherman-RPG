/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** death_anim
*/

#include "rpg.h"

static void player_death(rpg_t *rpg, entity_t *entity)
{
    int a = 0;

    while (DELTAT(rpg->win->time) < 2.5) {
        play_sound(DEATH_SOUND, rpg);
        youdead(rpg, rpg->loading, a);
        a += 4;
    }
    stop_loop_song(MAIN_MUSIC2, rpg);
    stop_loop_song(MAIN_MUSIC, rpg);
    entity->state = IDLE;
    entity->health.health = rpg->data->tot_stat.max_health;
    entity->health.potion = rpg->data->tot_stat.max_potion;
    rpg->data->xp = 0;
    entity->pos = rpg->puzzle->spawn;
    rpg->player->health.cd = 0;
    free_monsters(rpg);
    init_monsters(rpg);
}

void death_anim(rpg_t *rpg, entity_t *entity)
{
    entity->velocity = 0;
    if (entity->id == PLAYER) {
        player_death(rpg, entity);
    }
    return;
}
