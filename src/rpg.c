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
    init_item_list(rpg);
    init_input(rpg);
    init_fishing(rpg);
    init_menu(rpg);
    init_npc(rpg);
    init_song(rpg);
    init_shaders(rpg);
    init_in_game_menu(rpg);
    init_parall(rpg->player, rpg);
}

int rpg(void)
{
    entity_t *monster = NULL;
    item_e *item = NULL;
    rpg_t *rpg = init_rpg();

    rpg->items = &item;
    rpg->monsters = &monster;
    add_item(rpg, 0, (VEC){1000, 500});
    add_item(rpg, 0, (VEC){1200, 500});
    add_item(rpg, 0, (VEC){1400, 500});
    init_rpg_parts(rpg);
    init_fishing(rpg);
    scene_manager(rpg);
    return 0;
}
