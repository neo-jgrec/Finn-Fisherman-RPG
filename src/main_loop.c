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
        check_input(win, rpg->input);
    }
}

int main_loop(win_t *win, rpg_t *rpg)
{
    win->deltaT = DELTAT(win->time);
    if (win->deltaT > 0.1)
        win->deltaT = 0;
    sfClock_restart(win->time);
    analyse_events(win, rpg);
    manage_player(win, rpg->player, rpg);
    draw(win, rpg);
    return 0;
}
