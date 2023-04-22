/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_inventory
*/

#include "rpg.h"

static void add_to_inventory(data_t *data, item_e *item)
{
    for (int i = 0; i < 9 * 3; i++) {
        if (data->inventory[i] == NULL) {
            data->inventory[i] = item;
            return;
        }
    }
    free(item);
}

static item_e *default_item(item_e *item, int nb, int equiped)
{
    item->item_number = nb;
    item->equiped = equiped;
    item->in_inventory = 1;
    item->item_stat = (player_stat_t){0};
    item->item_stat.jump = 0;
    item->sprite = 0;
    item->type = 0;
    item->pos = (VEC){0};
    item->desc = "null item";
    item->next = NULL;
    return item;
}

static item_e *init_item(data_t *data, int nb, int equiped)
{
    item_e *item = malloc(sizeof(item_e));

    if (item == NULL)
        return NULL;
    if (nb >= data->nb_item)
        return default_item(item, nb, equiped);
    item->item_number = nb;
    item->equiped = equiped;
    item->in_inventory = 1;
    item->item_stat = data->item_list[nb].item_stat;
    item->sprite = data->item_list[nb].sprite;
    item->type = data->item_list[nb].type;
    item->pos = (VEC){0};
    item->desc = data->item_list[nb].desc;
    item->next = NULL;
    return item;
}

static void init_equiped(data_t *data)
{
    char *equiped = get_value_by_tags(data->parser->root,
        (char *[]){"EQUIPED", NULL});
    char **stw = NULL;
    item_e *item = NULL;

    if (equiped == NULL)
        return;
    if ((stw = a_mkstw(equiped, ":")) == NULL)
        return;
    for (int i = 0; stw[i]; i++) {
        item = init_item(data, my_atoi(stw[i]), 1);
        add_to_inventory(data, item);
    }
    a_freestw(stw);
}

void init_inventory_equiped(data_t *data)
{
    char *inventory = get_value_by_tags(data->parser->root,
        (char *[]){"INVENTORY", NULL});
    char **stw = NULL;
    item_e *item = NULL;

    if (inventory == NULL)
        return;
    if ((stw = a_mkstw(inventory, ":")) == NULL)
        return;
    for (int i = 0; stw[i]; i++) {
        item = init_item(data, my_atoi(stw[i]), 0);
        add_to_inventory(data, item);
    }
    a_freestw(stw);
    init_equiped(data);
}
