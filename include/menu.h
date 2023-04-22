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
    #include "xml_parser.h"

    #define TEXT_SIZE_LEN(str, char_size) (my_strlen(str) * char_size / 4) * 3
    #define TEXT_SIZE_HEIGHT(char_size) (char_size * 1.5)

    #define ALPHA_WHITE (sfColor) {\
    255, 255, 255, 200\
    }

    #define NAV_BUTTONS_DETECTION (rpg->menu->in_game_menu\
->panel_type == CHARACTERISTICS_PANEL && !my_strcmp(button->name,\
"SKILLS")) || (rpg->menu->in_game_menu\
->panel_type == INVENTORY_PANEL && !my_strcmp(button->name,\
"INVENTORY")) || (rpg->menu->in_game_menu\
->panel_type == SETTINGS_PANEL && !my_strcmp(button\
->name, "SETTINGS")) || (rpg->menu->in_game_menu\
->panel_type == SAVE_PANEL && !my_strcmp(button->name, "SAVE"))

typedef enum main_menu_scene {
    MAIN_MENU,
    SETTINGS_MENU,
    SAVES_MENU
} main_menu_scene_t;

typedef struct save_menu_s {
    char *save_file;
    int is_write;
    char *name;
    char *class;
    char *level;
    char *xp;
    char *gold;
    xml_parser_t *parser;
    button_t *button;
} save_menu_t;

typedef enum panel_type {
    NONE_PANEL,
    SETTINGS_PANEL,
    SAVE_PANEL,
    INVENTORY_PANEL,
    CHARACTERISTICS_PANEL,
    HOW_TO_PLAY_PANEL
} panel_type_t;

typedef struct in_game_menu_s {
    sfRectangleShape *bg;
    sfText *text;
    panel_type_t panel_type;
    TAILQ_HEAD(nav_buttons, button_s) nav_buttons;
    TAILQ_HEAD(skill_buttons, button_s) skill_buttons;
} in_game_menu_t;

typedef struct menu_s {
    sfText *text;
    sfFont *font;
    sfRectangleShape *bg;
    main_menu_scene_t scene;
    sfShader *bg_shader;
    sfRenderStates *render_states;
    save_menu_t **saves;
    char *selected_save;
    int save_reference;
    sfRectangleShape *how_to_play;
    sfRectangleShape *lore;
    TAILQ_HEAD(buttons, button_s) buttons;
    TAILQ_HEAD(settings_buttons, button_s) settings_buttons;
    TAILQ_HEAD(res_buttons, button_s) res_buttons;
    in_game_menu_t *in_game_menu;
} menu_t;

void init_menu(rpg_t *rpg);
bool is_rect_hover(sfVector2i mouse_pos, sfVector2f rect_pos,
sfVector2f rect_size);
void init_in_game_menu(rpg_t *rpg);

#endif /* !MENU_H_ */
