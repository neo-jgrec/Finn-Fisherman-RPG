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
void sound_button(rpg_t *rpg);
void music_button(rpg_t *rpg);

void res_1600_button(rpg_t *rpg);
void res_1920_button(rpg_t *rpg);

const void *buttons_functions_settings[] = {back_button, sound_button,
    music_button, res_button};

static void init_button_res_settings(menu_t *menu)
{
    button_t *button = malloc(sizeof(button_t));
    char *buttons_names[] = {"1600x900", "1920x1080"};
    void *buttons_functions[] = {res_1600_button, res_1920_button};
    sfVector2f buttons_pos[] = {{1350, 70}, {1350, 130}, {1350, 190}};
    sfVector2f buttons_size[] = {{TEXT_SIZE_LEN(buttons_names[0], 30),
    30}, {TEXT_SIZE_LEN(buttons_names[1], 30), 30}};

    for (size_t i = 0; i < 2; i++, button = malloc(sizeof(button_t))) {
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
    TAILQ_INIT(&menu->settings_buttons);
    button_t *button = malloc(sizeof(button_t));
    char *buttons_names[] = {"<-", "SOUND - 20%", "MUSIC - 20%", "FULLSCREEN"};
    sfVector2f buttons_pos[] = {{10, 10}, {100, 300}, {100, 400}, {100, 500}};

    for (size_t i = 0; i < 4; i++, button = malloc(sizeof(button_t))) {
        button->name = buttons_names[i];
        button->action = buttons_functions_settings[i];
        button->pos = buttons_pos[i];
        button->size = (sfVector2f){TEXT_SIZE_LEN(buttons_names[i], 30), 30};
        button->state = IDLE_BUTTON;
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        TAILQ_INSERT_TAIL(&menu->settings_buttons, button, next);
    }
    TAILQ_INIT(&menu->res_buttons);
    init_button_res_settings(menu);
}

static void init_buttons(menu_t *menu)
{
    TAILQ_INIT(&menu->buttons);
    button_t *button = malloc(sizeof(button_t));
    char *buttons_names[] = {"PLAY", "SETTINGS", "QUIT"};
    void *buttons_functions[] = {play_button, settings_button, quit_button};
    sfVector2f buttons_pos[] = {{100, 300}, {100, 400}, {100, 500}};

    for (size_t i = 0; i < 3; i++, button = malloc(sizeof(button_t))) {
        button->name = buttons_names[i];
        button->action = buttons_functions[i];
        button->pos = buttons_pos[i];
        button->size = (sfVector2f){TEXT_SIZE_LEN(buttons_names[i], 30), 30};
        button->state = IDLE_BUTTON;
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        TAILQ_INSERT_TAIL(&menu->buttons, button, next);
    }
    init_button_settings(menu);
    menu->scene = MAIN_MENU;
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
    rpg->menu = malloc(sizeof(menu_t));
    rpg->menu->text = sfText_create();
    rpg->menu->font = sfFont_createFromFile("assets/Inter-Medium.ttf");
    rpg->menu->bg = sfRectangleShape_create();
    rpg->menu->render_states = init_blur_renderstate(rpg->menu);
    rpg->menu->how_to_play = sfRectangleShape_create();
    sfRectangleShape_setTexture(rpg->menu->how_to_play,
    sfTexture_createFromFile("assets/how_to_play.png", NULL), sfTrue);
    sfRectangleShape_setPosition(rpg->menu->how_to_play,
    (sfVector2f){0, 0});
    rpg->menu->lore = sfRectangleShape_create();
    sfRectangleShape_setTexture(rpg->menu->lore, sfTexture_createFromFile(
    "assets/lore.png", NULL), sfTrue);
    sfRectangleShape_setPosition(rpg->menu->lore, (sfVector2f){0, 0});
    sfText_setFont(rpg->menu->text, rpg->menu->font);
    sfRectangleShape_setPosition(rpg->menu->bg, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rpg->menu->bg, (sfVector2f){1600, 900});
    sfRectangleShape_setFillColor(rpg->menu->bg, sfWhite);
    init_buttons(rpg->menu);
    parse_saves(rpg->menu);
}
