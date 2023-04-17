/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_menu
*/

#include "rpg.h"

void parse_saves(menu_t *menu);

void settings_button(rpg_t *rpg);
void quit_button(rpg_t *rpg);
void play_button(rpg_t *rpg);

void back_button(rpg_t *rpg);
void res_button(rpg_t *rpg);

void res_1600_button(rpg_t *rpg);
void res_1920_button(rpg_t *rpg);
void res_800_button(rpg_t *rpg);

static void init_buttons(menu_t *menu)
{
    TAILQ_INIT(&menu->buttons);
    button_t *button = malloc(sizeof(button_t));
    char *buttons_names[] = {"PLAY", "SETTINGS", "QUIT"};
    void *buttons_functions[] = {play_button, settings_button, quit_button};
    sfVector2f buttons_pos[] = {{100, 300}, {100, 400}, {100, 500}};
    sfVector2f buttons_size[] = {{TEXT_SIZE_LEN(buttons_names[0], 30), 30},
    {TEXT_SIZE_LEN(buttons_names[1], 30), 30},
    {TEXT_SIZE_LEN(buttons_names[2], 30), 30}};

    for (size_t i = 0; i < 3; i++, button = malloc(sizeof(button_t))) {
        button->name = buttons_names[i];
        button->action = buttons_functions[i];
        button->pos = buttons_pos[i];
        button->size = buttons_size[i];
        button->state = IDLE_BUTTON;
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        TAILQ_INSERT_TAIL(&menu->buttons, button, next);
    }
}

static void init_button_res_settings(menu_t *menu)
{
    button_t *button = malloc(sizeof(button_t));
    char *buttons_names[] = {"1600x900", "1920x1080", "800x600"};
    void *buttons_functions[] = {res_1600_button, res_1920_button,
    res_800_button};
    sfVector2f buttons_pos[] = {{1350, 70}, {1350, 130}, {1350, 190}};
    sfVector2f buttons_size[] = {{TEXT_SIZE_LEN(buttons_names[0], 30),
    30}, {TEXT_SIZE_LEN(buttons_names[1], 30), 30},
    {TEXT_SIZE_LEN(buttons_names[2], 30), 30}};

    for (size_t i = 0; i < 3; i++, button = malloc(sizeof(button_t))) {
        button->name = buttons_names[i];
        button->action = buttons_functions[i];
        button->pos = buttons_pos[i];
        button->size = buttons_size[i];
        button->state = IDLE_BUTTON;
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        TAILQ_INSERT_TAIL(&menu->res_buttons, button, next);
    }
}

static void init_button_settings(menu_t *menu)
{
    button_t *button = malloc(sizeof(button_t));
    char *buttons_names[] = {"<- BACK", "SOUND", "MUSIC", "FULLSCREEN"};
    void *buttons_functions[] = {back_button, NULL, NULL, res_button};
    sfVector2f buttons_pos[] = {{10, 10}, {100, 300}, {100, 400}, {100, 500}};
    sfVector2f buttons_size[] = {{TEXT_SIZE_LEN(buttons_names[0], 30), 30},
    {TEXT_SIZE_LEN(buttons_names[1], 30), 30}, {TEXT_SIZE_LEN(buttons_names[2],
    30), 30}, {TEXT_SIZE_LEN(buttons_names[3], 30), 30}};
    for (size_t i = 0; i < 4; i++, button = malloc(sizeof(button_t))) {
        button->name = buttons_names[i];
        button->action = buttons_functions[i];
        button->pos = buttons_pos[i];
        button->size = buttons_size[i];
        button->state = IDLE_BUTTON;
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        TAILQ_INSERT_TAIL(&menu->settings_buttons, button, next);
    }
    TAILQ_INIT(&menu->res_buttons);
    init_button_res_settings(menu);
}

static sfRenderStates *init_blur_renderstate(menu_t *menu)
{
    menu->bg_shader = sfShader_createFromFile(NULL, NULL,
    "assets/menu/menu.frag");
    sfShader_setFloatUniform(menu->bg_shader, "time", 0);
    sfShader_setVec2Uniform(menu->bg_shader, "resolution",
    (sfVector2f){1920, 1080});
    sfShader_setFloatUniform(menu->bg_shader, "blur", 1.0);
    sfShader_setFloatUniform(menu->bg_shader, "brightness", 1.0);
    sfRenderStates *states = malloc(sizeof(sfRenderStates) * 10);
    states->shader = menu->bg_shader;
    states->transform = sfTransform_Identity;
    states->texture = NULL;
    states->blendMode = sfBlendAlpha;
    return states;
}

void init_menu(rpg_t *rpg)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->text = sfText_create();
    menu->font = sfFont_createFromFile("assets/Inter-Medium.ttf");
    menu->bg = sfRectangleShape_create();
    menu->render_states = init_blur_renderstate(menu);
    sfText_setString(menu->text, "THE RPG");
    sfText_setFont(menu->text, menu->font);
    sfRectangleShape_setPosition(menu->bg, (sfVector2f){0, 0});
    sfRectangleShape_setSize(menu->bg, (sfVector2f){1600, 900});
    sfRectangleShape_setFillColor(menu->bg, sfWhite);
    init_buttons(menu);
    TAILQ_INIT(&menu->settings_buttons);
    init_button_settings(menu);
    menu->scene = MAIN_MENU;
    parse_saves(menu);
    rpg->menu = menu;
}
