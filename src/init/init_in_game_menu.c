/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_in_game_menu
*/

#include "rpg.h"

void menu_button_action(rpg_t *rpg);
void settings_button_action(rpg_t *rpg);
void save_button_action(rpg_t *rpg);
void resume_button_action(rpg_t *rpg);
void inventory_button_action(rpg_t *rpg);
void skills_button_action(rpg_t *rpg);
void how_to_play_button_action(rpg_t *rpg);

static const char *button_name_main[] = {
    "MAIN MENU",
    "SETTINGS",
    "INVENTORY",
    "SKILLS",
    "SAVE",
    "RESUME",
    "HOW TO PLAY"
};

void replace_elements_in_game_menus(rpg_t *rpg)
{
    const sfView *view = sfRenderWindow_getView(rpg->win->win);
    sfVector2f view_pos = sfView_getCenter(view);
    sfVector2f view_size = sfView_getSize(view);

    sfRectangleShape_setSize(rpg->menu->in_game_menu->bg,
        (sfVector2f){view_size.x, view_size.y});
    sfRectangleShape_setPosition(rpg->menu->in_game_menu->bg,
        (sfVector2f){view_pos.x - view_size.x / 2,
        view_pos.y - view_size.y / 2});
}

static void init_buttons(rpg_t *rpg)
{
    TAILQ_INIT(&rpg->menu->in_game_menu->nav_buttons);
    button_t *button = malloc(sizeof(button_t));
    void (*action_array[])(rpg_t *) = {&menu_button_action,
    &settings_button_action, &inventory_button_action,
    &skills_button_action, &save_button_action, &resume_button_action,
    &how_to_play_button_action};
    sfVector2f pos[] = {{10, 10}, {275, 10}, {540, 10}, {805, 10}, {1070, 10},
    {1335, 10}, {10, sfRenderWindow_getSize(rpg->win->win).y - 40}};

    for (size_t i = 0; i < 7; i++, button = malloc(sizeof(button_t))) {
        button->name = (char *)button_name_main[i];
        button->size = (sfVector2f){TEXT_SIZE_LEN(button_name_main[i], 30),
            30};
        button->pos = pos[i];
        button->shape = sfRectangleShape_create();
        button->action = (void*)action_array[i];
        button->state = IDLE_BUTTON;
        TAILQ_INSERT_TAIL(&rpg->menu->in_game_menu->nav_buttons, button, next);
    }
}

static void init_skills_buttons(rpg_t *rpg)
{
    TAILQ_INIT(&rpg->menu->in_game_menu->skill_buttons);
    button_t *button = malloc(sizeof(button_t));
    char *names[] = {"[HEAL POWER]", "[MAX HEALTH]",
    "[SPEED]", "[DAMAGE]", "[CRITICAL CHANCE]"};
    sfVector2f pos[] = {{100, 300}, {100, 400}, {100, 500}, {100, 600},
    {100, 700}, {100, 800}};

    for (size_t i = 0; i < 5; i++, button = malloc(sizeof(button_t))) {
        button->name = names[i];
        button->size = (sfVector2f){TEXT_SIZE_LEN(names[i], 30), 30};
        button->pos = pos[i];
        button->shape = sfRectangleShape_create();
        button->action = NULL;
        button->state = IDLE_BUTTON;
        TAILQ_INSERT_TAIL(&rpg->menu->in_game_menu->skill_buttons,
            button, next);
    }
}

void init_in_game_menu(rpg_t *rpg)
{
    rpg->menu->in_game_menu = malloc(sizeof(in_game_menu_t));
    rpg->menu->in_game_menu->bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rpg->menu->in_game_menu->bg, sfBlack);
    rpg->menu->in_game_menu->panel_type = NONE_PANEL;
    rpg->menu->in_game_menu->text = sfText_create();
    init_buttons(rpg);
    init_skills_buttons(rpg);
    rpg->menu->title = sfRectangleShape_create();
    sfRectangleShape_setTexture(rpg->menu->title,
        sfTexture_createFromFile("assets/title.png", NULL), sfTrue);
    sfRectangleShape_setSize(rpg->menu->title, (sfVector2f){500, 500});
    sfRectangleShape_setPosition(rpg->menu->title, (sfVector2f){725, 100});
}
