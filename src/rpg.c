/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg
*/

#include "rpg.h"

int rpg(void)
{
    rpg_t *rpg = init_rpg();
    init_win(rpg);
    init_loading(rpg);
    init_asset(rpg);
    init_puzzle(rpg);
    init_data(rpg);
    init_player(rpg->asset, rpg);
    init_input(rpg);
    init_menu(rpg);
    scene_manager(rpg);
    return 0;
}
