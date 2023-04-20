/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_loading
*/

#include "rpg.h"

static sprite_t *init_fishs(int nb)
{
    sprite_t *fishs = malloc(sizeof(sprite_t) * nb);

    if (fishs == NULL)
        return NULL;
    for (int i = 0; i < nb; fishs[i] = (sprite_t){0}, i++);
    fishs[0] = init_sprite("assets/loading/fish_0.jpg",
        (VEC){627, 381}, 1, 1);
    fishs[1] = init_sprite("assets/loading/ugly_fish.png",
        (VEC){1332, 655}, 1, 1);
    return fishs;
}

void init_loading(rpg_t *rpg)
{
    loading_t *loading = malloc(sizeof(loading_t));

    if (loading == NULL)
        rpg->loading = NULL;
    loading->nb_fish = 2;
    loading->fish = 0;
    loading->fishs = init_fishs(loading->nb_fish);
    loading->youdead = init_sprite("assets/youdied.png",
        (VEC){1920, 1080}, 1, 1);
    rpg->loading = loading;
    loading_screen(rpg, rpg->loading, 20, 0);
}
