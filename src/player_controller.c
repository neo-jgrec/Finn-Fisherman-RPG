/*
** EPITECH PROJECT, 2023
** player_controller
** File description:
** player_controller
*/

#include "rpg.h"

static void analyse_events(window_t *win, player_t *player)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        player_input(win, player);
    }
}

player_t init_player(void)
{
    player_t player = {0};

    player.rect = (sfFloatRect){0, 0, 50, 50};
    player.sprite = sfRectangleShape_create();
    sfRectangleShape_setSize(player.sprite, (sfVector2f){50, 50});
    sfRectangleShape_setFillColor(player.sprite, sfRed);
    player.pos = (sfVector2f){150, 150};
    player.keyLeft = 0;
    player.keyRight = 0;
    player.dir = (sfVector2f){0};
    return player;
}

window_t init_window(void)
{
    window_t win = {0};

    sfEvent event = {0};
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){700, 700, 32},
        "oui", sfClose, NULL);
    win.event = event;
    win.window = window;
    win.time = sfClock_create();
    win.deltaT = 0;
    return win;
}

int main_loop(window_t *win, player_t *player)
{
    while (sfRenderWindow_isOpen(win->window)) {
        win->deltaT = DELTAT(win->time);
        sfClock_restart(win->time);
        sfRenderWindow_clear(win->window, sfWhite);
        analyse_events(win, player);
        sfRenderWindow_drawRectangleShape(win->window, player->sprite, NULL);
        sfRenderWindow_display(win->window);
        player_manager(player, win);
    }
    return 1;
}

int player_controller()
{
    player_t player = init_player();
    window_t win = init_window();

    main_loop(&win, &player);
    return 0;
}
