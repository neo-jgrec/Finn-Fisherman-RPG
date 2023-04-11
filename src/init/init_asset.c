/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_asset
*/

#include "rpg.h"

static pa_t init_pa(void)
{
    pa_t pa = {0};

    pa.idle = init_sprite("assets/player/idle.png", (VEC){16, 16}, 6, 4);
    pa.run = init_sprite("assets/player/run.png", (VEC){18, 18}, 8, 4);
    return pa;
}

void init_asset(rpg_t *rpg)
{
    asset_t *asset = malloc(sizeof(asset_t));

    if (asset == NULL)
        rpg->asset = NULL;
    asset->pa = init_pa();
    asset->tileset = init_sprite("assets/tileset/tiles.png",
        (VEC){16, 16}, 14, 4);
    sfSprite_setOrigin(asset->tileset.sp, (VEC){0, 0});
    rpg->asset = asset;
    loading_screen(rpg, rpg->loading, 60, 1);
}
