/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save_in_game
*/

#include "rpg.h"

void save_data_3(data_t *data, xml_parser_t *ps);
void save_data_2(data_t *data, xml_parser_t *ps);

static char *save_inventory(data_t *data, int equiped)
{
    char *str = malloc(sizeof(char));
    char *nb = NULL;

    if (str == NULL)
        return NULL;
    str[0] = '\0';
    for (int i = 0; i < 9 * 3; i++) {
        if (data->inventory[i] != NULL &&
            data->inventory[i]->equiped == equiped) {
            nb = my_itoa(data->inventory[i]->item_number);
            str = my_strcat_inf(3, str, nb, ":");
        }
    }
    return str;
}

void save_data_in_game(rpg_t *rpg, char *filename, char *save_name)
{
    xml_parser_t *ps = rpg->data->parser;
    char *str = NULL;
    data_t *data = rpg->data;

    if (ps == NULL)
        return;
    if ((str = save_inventory(rpg->data, 1)) != NULL) {
        update_value_by_tags(ps->root, (char *[]){"EQUIPED", NULL}, str);
        free(str);
    }
    if ((str = save_inventory(rpg->data, 0)) != NULL) {
        update_value_by_tags(ps->root, (char *[]){"INVENTORY", NULL}, str);
        free(str);
    }
    update_value_by_tags(ps->root, (char *[]){"SAVENAME", NULL}, save_name);
    save_data_2(data, ps);
    save_data_3(data, ps);
    save_xml(ps, filename);
}
