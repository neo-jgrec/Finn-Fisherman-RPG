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
    init_data(rpg);
    init_puzzle(rpg);
    init_input(rpg);
    init_fishing(rpg);
    init_menu(rpg);
    init_npc(rpg);
    init_song(rpg);
    init_parall(rpg->player, rpg, 0);
    init_shaders(rpg);
    init_monsters(rpg);
    init_in_game_menu(rpg);
}

int rpg(void)
{
    entity_t *monster = NULL;
    rpg_t *rpg = init_rpg();

    rpg->monsters = &monster;
    init_rpg_parts(rpg);
    init_fishing(rpg);
    scene_manager(rpg);
    return 0;
}
