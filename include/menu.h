/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>
    #include <sys/queue.h>
    #include <stdbool.h>

    #include "buttons.h"

typedef struct menu_s {
    sfText *text;
    sfFont *font;
    sfRectangleShape *bg;
    sfMusic *music;
    bool is_save;
    TAILQ_HEAD(buttons, button_s) buttons;
} menu_t;

void init_menu(rpg_t *rpg);
bool is_rect_hover(sfVector2i mouse_pos, sfVector2f rect_pos,
sfVector2f rect_size);


#endif /* !MENU_H_ */
