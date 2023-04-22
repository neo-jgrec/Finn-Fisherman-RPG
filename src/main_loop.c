/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main_loop
*/

#include "rpg.h"

void button_manager(win_t *win, rpg_t *rpg, struct buttons *button_list);
void replace_elements_in_game_menus(rpg_t *rpg);

static void analyse_events(win_t *win, rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->win);
        if (win->event.type == sfEvtKeyPressed &&
            win->event.key.code == sfKeyF11)
            switch_style(win);
        if (win->event.type == sfEvtKeyPressed &&
            win->event.key.code == sfKeyEscape)
            rpg->menu->in_game_menu->panel_type = (\
                !rpg->menu->in_game_menu->panel_type)
                ? INVENTORY_PANEL : NONE_PANEL;
        check_input(win, rpg->input);
    }
}

int main_loop(win_t *win, rpg_t *rpg)
{
    analyse_events(rpg->win, rpg);
    if (!rpg->menu->in_game_menu->panel_type) {
        win->deltaT = (DELTAT(win->time) > 0.1) ? 0 : DELTAT(win->time);
        sfClock_restart(win->time);
        if (rpg->data->location % 2 == 0)
            play_loop_song(MAIN_MUSIC, rpg);
        else
            play_loop_song(MAIN_MUSIC2, rpg);
        manage_player(win, rpg->player, rpg);
        manage_monster(win, rpg);
        manage_items(rpg);
        manage_npc(rpg, rpg->npc);
        cam_management(rpg->player, win, rpg);
        manage_parall(rpg->player, rpg->parall, win);
    } else
        replace_elements_in_game_menus(rpg);
    draw(win, rpg);
    return 0;
}
