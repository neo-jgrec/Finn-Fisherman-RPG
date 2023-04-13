/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_menu
*/

#include "rpg.h"

static void init_buttons(menu_t *menu)
{
    button_t *button = malloc(sizeof(button_t));
    button->name = "Play";
    button->pos = (sfVector2f){800, 400};
    button->size = (sfVector2f){300, 100};
    button->shape = sfRectangleShape_create();
    button->state = IDLE_BUTTON;
    button->action = NULL;
    TAILQ_INSERT_TAIL(&menu->buttons, button, next);
}

void init_menu(rpg_t *rpg)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/AwasetePowder.ttf");
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
    menu->text = text;
    menu->font = font;
    menu->bg = bg;
    rpg->menu = menu;
}
