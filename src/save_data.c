/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** save_data
*/

#include "rpg.h"

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

static void save_nb(xml_parser_t *ps, int nb, char **tags)
{
    char *str = NULL;

    if ((str = my_itoa(nb)) != NULL) {
        update_value_by_tags(ps->root, tags, str);
        free(str);
    }
}

void save_data_3(data_t *data, xml_parser_t *ps)
{
    save_nb(ps, data->player_stat.damage,
        (char *[]){"STATS", "DAMAGE", NULL});
    save_nb(ps, data->player_stat.jump,
        (char *[]){"STATS", "JUMP", NULL});
    save_nb(ps, data->lvl,
        (char *[]){"STATS", "LVL", NULL});
    save_nb(ps, data->xp,
        (char *[]){"STATS", "EXP", NULL});
    save_nb(ps, data->xp_to_lvl_up,
        (char *[]){"STATS", "EXP_TO_NEXT_LEVEL", NULL});
    save_nb(ps, data->lvl_point,
        (char *[]){"STATS", "LVL_POINT", NULL});
}

void save_data_2(data_t *data, xml_parser_t *ps)
{
    save_nb(ps, 1, (char *[]){"STARTED", NULL});
    save_nb(ps, data->location, (char *[]){"LOCATION", NULL});
    save_nb(ps, data->player_stat.heal_power,
        (char *[]){"STATS", "POTION", "HEALTH_POWER", NULL});
    save_nb(ps, data->player_stat.max_potion,
        (char *[]){"STATS", "POTION", "MAX_POTION", NULL});
    save_nb(ps, data->player_stat.crit_chance,
        (char *[]){"STATS", "CRIT_CHANCE", NULL});
    save_nb(ps, data->player_stat.max_health,
        (char *[]){"STATS", "MAX_HEALTH", NULL});
    save_nb(ps, data->player_stat.speed,
        (char *[]){"STATS", "SPEED", NULL});
}

void save_data(rpg_t *rpg)
{
    xml_parser_t *ps = rpg->data->parser;
    char *str = NULL;
    data_t *data = rpg->data;

    if ((str = save_inventory(rpg->data, 1)) != NULL) {
        update_value_by_tags(ps->root, (char *[]){"EQUIPED", NULL}, str);
        free(str);
    }
    if ((str = save_inventory(rpg->data, 0)) != NULL) {
        update_value_by_tags(ps->root, (char *[]){"INVENTORY", NULL}, str);
        free(str);
    }
    save_data_2(data, ps);
    save_data_3(data, ps);
}
