/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_loading
*/

#include "rpg.h"

static sprite_t **init_fishs(int nb)
{
    sprite_t **fishs = malloc(sizeof(sprite_t *) * nb);

    if (fishs == NULL)
        return NULL;
    for (int i = 0; i < nb; fishs[i] = NULL, i++);
    fishs[0] = init_sprite("assets/loading/fish_0.jpg",
        (VEC){627, 381}, 1, 1);
    return fishs;
}

void init_loading(rpg_t *rpg)
{
    loading_t *loading = malloc(sizeof(loading_t));

    if (loading == NULL)
        rpg->loading = NULL;
    loading->nb_fish = 1;
    loading->fish = 0;
    loading->fishs = init_fishs(1);
    rpg->loading = loading;
    loading_screen(rpg, rpg->loading, 20, 1);
}
