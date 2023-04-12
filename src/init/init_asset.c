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

    pa.idle = init_sprite("assets/player/idle.png", (VEC){32, 32}, 6, 4);
    pa.healing = init_sprite("assets/player/healing.png", (VEC){32, 32}, 6, 4);
    pa.run = init_sprite("assets/player/run.png", (VEC){32, 32}, 8, 4);
    pa.death = init_sprite("assets/player/death.png", (VEC){32, 32}, 5, 4);
    pa.jump_1 = init_sprite("assets/player/jump_1.png", (VEC){32, 32}, 6, 4);
    pa.jump_2 = init_sprite("assets/player/jump_2.png", (VEC){32, 32}, 6, 4);
    pa.jump_1.cd = 0.025;
    pa.jump_1.cd = 0.025;
    pa.roll = init_sprite("assets/player/roll.png", (VEC){48, 24}, 8, 4);
    pa.roll.cd = 0.03;
    pa.damage = init_sprite("assets/player/take_damage.png",
        (VEC){32, 32}, 3, 4);
    pa.attack_1 = init_sprite("assets/player/attack_1.png",
        (VEC){48, 48}, 10, 4);
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
    loading_screen(rpg, rpg->loading, 35, 0);
}
