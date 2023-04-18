/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_saves
*/

#include "rpg.h"
#include <assert.h>
#include "xml_parser.h"

static void add_stats(save_menu_t *save, xml_parser_t *parser)
{
    save->name = get_value_by_tags(parser->root, ((char *[]){"SAVENAME", NULL}));
    char *tmp = get_value_by_tags(parser->root,
    ((char *[]){"SAVEEXISTS", NULL}));
    save->is_write = (tmp != NULL);
}

void parse_saves(menu_t *menu)
{
    char *saves[] = {"saves/save1.xml", "saves/save2.xml", "saves/save3.xml"};
    size_t i = 0;
    menu->saves = malloc(sizeof(save_menu_t *) * 300);
    sfVector2f size[] = {(sfVector2f){700, 185}, (sfVector2f){700, 185},
    (sfVector2f){700, 185}};
    sfVector2f pos[] = {(sfVector2f){1600 / 2 - 350, 200},
    (sfVector2f){1600 / 2 - 350, 425}, (sfVector2f){1600 / 2 - 350, 650}};

    for (; i < 3; i++) {
        menu->saves[i] = malloc(sizeof(save_menu_t));
        menu->saves[i]->button = malloc(sizeof(button_t));
        menu->saves[i]->save_file = saves[i];
        menu->saves[i]->parser = init_parser(saves[i]);
        parse_xml(menu->saves[i]->parser);
        add_stats(menu->saves[i], menu->saves[i]->parser);
        menu->saves[i]->button->shape = sfRectangleShape_create();
        sfRectangleShape_setSize(menu->saves[i]->button->shape, size[i]);
        sfRectangleShape_setPosition(menu->saves[i]->button->shape, pos[i]);
    }
    menu->saves[i] = NULL;
}
