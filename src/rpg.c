/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg
*/

#include "rpg.h"

static void init_rpg_parts(rpg_t *rpg)
{
    init_win(rpg);
    init_loading(rpg);
    init_asset(rpg);
    init_quest(rpg);
    init_player(rpg->asset, rpg);
    init_puzzle(rpg);
    init_data(rpg);
    init_input(rpg);
    init_fishing(rpg);
    init_menu(rpg);
    init_npc(rpg);
    init_song(rpg);
    init_shaders(rpg);
}

int rpg(void)
{
    entity_t *monster = NULL;
    rpg_t *rpg = init_rpg();

    init_rpg_parts(rpg);
    rpg->monsters = &monster;
    add_monster(rpg, SKELETON, (VEC){500, 400});
    add_monster(rpg, SHROOM, (VEC){1400, 400});
    add_monster(rpg, EYE, (VEC){700, 400});
    init_fishing(rpg);
    init_parallax(rpg->player, rpg, CAVE);
    scene_manager(rpg);
    return 0;
}
