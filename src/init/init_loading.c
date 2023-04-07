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
        (VEC){800, 450}, 1, 1);
    return fishs;
}

loading_t *init_loading(void)
{
    loading_t *loading = malloc(sizeof(loading_t));

    if (loading == NULL)
        return NULL;
    loading->nb_fish = 1;
    loading->fish = 0;
    loading->fishs = init_fishs(1);
    return loading;
}
