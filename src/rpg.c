/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg
*/

#include "rpg.h"
static void init_info_text(rpg_t *rpg)
{
    rpg->info_text = sfText_create();
    sfText_setCharacterSize(rpg->info_text, 18);
    sfText_setFont(rpg->info_text, rpg->win->font);
}

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
    info_t *info = NULL;
    rpg_t *rpg = init_rpg();

    rpg->items = &item;
    rpg->monsters = &monster;
    rpg->infos = &info;
    init_rpg_parts(rpg);
    init_fishing(rpg);
    init_info_text(rpg);
    add_info_text(rpg, sfRed, (VEC){500, 500}, my_itoa(50));
    scene_manager(rpg);
    return 0;
}
