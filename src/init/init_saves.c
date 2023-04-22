/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_saves
*/

#include "rpg.h"
#include <assert.h>
#include "xml_parser.h"
#include <fcntl.h>

void launch_game(rpg_t *rpg);
void create_default_save_file(char *filename, char *save_name);
bool are_tags_in_file(char *filename);

sfVector2f size_array[] = {(sfVector2f){700, 185}, (sfVector2f){700, 185},
(sfVector2f){700, 185}};
sfVector2f pos_array[] = {(sfVector2f){1600 / 2 - 350, 200},
(sfVector2f){1600 / 2 - 350, 425}, (sfVector2f){1600 / 2 - 350, 650}};

static void add_stats(save_menu_t *save, xml_parser_t *parser, char *filename)
{
    parser = init_parser(filename);
    parse_xml(parser);
    save->name = get_value_by_tags(parser->root,
    ((char *[]){"SAVENAME", NULL}));
    save->is_write = (get_value_by_tags(parser->root,
    ((char *[]){"STARTED", NULL}))[0] == '1') ? true : false;
    save->button->name = save->name;
}

static bool is_file_exist(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

static button_t *init_button(sfVector2f size, sfVector2f pos)
{
    button_t *button = malloc(sizeof(button_t));

    button->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(button->shape, size);
    sfRectangleShape_setPosition(button->shape, pos);
    button->name = NULL;
    button->action = (void*)&launch_game;
    button->state = IDLE_BUTTON;
    return button;
}

void parse_saves(menu_t *menu)
{
    char *saves[] = {"saves/save1.xml", "saves/save2.xml", "saves/save3.xml"};
    size_t i = 0;
    char *save_name = NULL;

    menu->saves = malloc(sizeof(save_menu_t *) * 4);
    for (; i < 3; i++) {
        menu->saves[i] = malloc(sizeof(save_menu_t));
        menu->saves[i]->save_file = saves[i];
        menu->saves[i]->button = init_button(size_array[i], pos_array[i]);
        if (!is_file_exist(saves[i]) || !are_tags_in_file(saves[i])) {
            menu->saves[i]->is_write = false;
            menu->saves[i]->name = NULL;
            save_name = my_strcat_inf(2, "Save ", my_itoa(i + 1));
            create_default_save_file(saves[i], save_name);
        }
        add_stats(menu->saves[i], menu->saves[i]->parser, saves[i]);
    }
    menu->saves[i] = NULL;
}
