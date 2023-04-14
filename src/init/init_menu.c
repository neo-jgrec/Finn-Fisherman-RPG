/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_menu
*/

#include "rpg.h"

void settings_button(rpg_t *rpg);
void quit_button(rpg_t *rpg);
void play_button(rpg_t *rpg);

static void init_buttons(menu_t *menu)
{
    button_t *button = malloc(sizeof(button_t));
    char *buttons_names[] = {"PLAY", "SETTINGS", "QUIT"};
    void *buttons_functions[] = {play_button, settings_button, quit_button};
    sfVector2f buttons_pos[] = {{100, 300}, {100, 400}, {100, 500}};
    sfVector2f buttons_size[] = {{200, 50}, {200, 50}, {200, 50}};
    size_t nb_buttons = sizeof(buttons_names) / sizeof(char *);

    for (size_t i = 0; i < nb_buttons; i++) {
        button = malloc(sizeof(button_t));
        button->name = buttons_names[i];
        button->action = buttons_functions[i];
        button->pos = buttons_pos[i];
        button->size = buttons_size[i];
        button->state = IDLE_BUTTON;
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        sfRectangleShape_setFillColor(button->shape, sfWhite);
        TAILQ_INSERT_TAIL(&menu->buttons, button, next);
    }
}

void init_menu(rpg_t *rpg)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/Inter-Medium.ttf");
    sfRectangleShape *bg = sfRectangleShape_create();

    if (menu == NULL)
        rpg->menu = NULL;
    sfText_setString(text, "THE RPG");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 100);
    sfText_setPosition(text, (sfVector2f){500, 100});
    sfRectangleShape_setSize(bg, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(bg, sfBlack);
    TAILQ_INIT(&menu->buttons);
    init_buttons(menu);
    menu->scene = MAIN_MENU;
    menu->text = text;
    menu->font = font;
    menu->bg = bg;
    rpg->menu = menu;
}
