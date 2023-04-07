/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_asset
*/

#include "rpg.h"

asset_t *init_asset(void)
{
    asset_t *asset = malloc(sizeof(asset_t));

    if (asset == NULL)
        return NULL;
    asset->player = init_sprite("assets/player/run.png", (VEC){32, 32}, 6, 3);
    return asset;
}
