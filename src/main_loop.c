/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main_loop
*/

#include "rpg.h"

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
    sfRectangleShape_setPosition(rpg->menu->in_game_menu->bg,
        (sfVector2f){(rpg->player->pos.x - rpg->win->size.x / 1.5 / 2),
        (rpg->player->pos.y - rpg->win->size.y / 1.5 / 2)});
}

int main_loop(win_t *win, rpg_t *rpg)
{
    analyse_events(rpg->win, rpg);
    if (!rpg->menu->in_game_menu->panel_type) {
        win->deltaT = (DELTAT(win->time) > 0.1) ? 0 : DELTAT(win->time);
        sfClock_restart(win->time);
        manage_song(rpg);
        manage_player(win, rpg->player, rpg);
        manage_monster(win, rpg);
        manage_npc(rpg, rpg->npc);
        cam_management(rpg->player, win, rpg);
        manage_parall(rpg->player, rpg->parall, win);
    }
    draw(win, rpg);
    return 0;
}
