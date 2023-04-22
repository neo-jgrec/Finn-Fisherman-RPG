/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_parall
*/

#include "rpg.h"

static void init_parall_0(entity_t *player, parall_t *parall)
{
    parall->layers = malloc(sizeof(sprite_t) * parall->nb);
    parall->pos = malloc(sizeof(sfVector2f) * parall->nb);
    if (parall->layers == NULL) {
        parall->nb = 0;
        return;
    }
    parall->layers[5] = init_sprite("assets/Layers/trees.png",
        (VEC){240, 240}, 1, 5);
    parall->layers[4] = init_sprite("assets/Layers/mountains.png",
        (VEC){320, 240}, 1, 5);
    parall->layers[3] = init_sprite("assets/Layers/farmountains.png",
        (VEC){160, 240}, 1, 5);
    parall->layers[2] = init_sprite("assets/Layers/nearclouds.png",
        (VEC){144, 240}, 1, 5);
    parall->layers[1] = init_sprite("assets/Layers/farclouds.png",
        (VEC){128, 240}, 1, 5);
    parall->layers[0] = init_sprite("assets/Layers/sky.png",
        (VEC){320, 240}, 1, 5);
    for (int i = 0; i < parall->nb; i++)
        parall->pos[i] = (VEC){player->pos.x, player->pos.y -150};
}

void init_parall(entity_t *player, rpg_t *rpg)
{
    parall_t *parall = malloc(sizeof(parall_t));

    if (parall == NULL)
        return;
    parall->y_spawn = player->pos.y;
    parall->nb = 6;
    init_parall_0(player, parall);
    rpg->parall = parall;
}
