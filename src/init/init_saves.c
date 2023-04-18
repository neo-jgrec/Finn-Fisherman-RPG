/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_saves
*/

#include "rpg.h"
#include <assert.h>
#include "xml_parser.h"

void launch_game(rpg_t *rpg);

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
    save->is_write = (save->name != NULL);
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
    return button;
}

void parse_saves(menu_t *menu)
{
    char *saves[] = {"saves/save1.xml", "saves/save2.xml", "saves/save3.xml"};
    size_t i = 0;
    menu->saves = malloc(sizeof(save_menu_t *) * 4);

    for (; i < 3; i++) {
        menu->saves[i] = malloc(sizeof(save_menu_t));
        menu->saves[i]->save_file = saves[i];
        menu->saves[i]->button = init_button(size_array[i], pos_array[i]);
        if (!is_file_exist(saves[i])) {
            menu->saves[i]->is_write = false;
            menu->saves[i]->name = NULL;
            continue;
        }
        add_stats(menu->saves[i], menu->saves[i]->parser, saves[i]);
    }
    menu->saves[i] = NULL;
}
