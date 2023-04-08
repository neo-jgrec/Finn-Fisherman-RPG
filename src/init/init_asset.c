/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_asset
*/

#include "rpg.h"

void init_asset(rpg_t *rpg)
{
    asset_t *asset = malloc(sizeof(asset_t));

    if (asset == NULL)
        rpg->asset = NULL;
    asset->player = init_sprite("assets/player/test.png", (VEC){32, 32}, 6, 3);
    asset->tileset = init_sprite("assets/tileset/tiles.png",
        (VEC){16, 16}, 14, 4);
    sfSprite_setOrigin(asset->tileset.sp, (VEC){0, 0});
    rpg->asset = asset;
    loading_screen(rpg, rpg->loading, 60, 1);
}
