/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_sign
*/

#include "rpg.h"

static void check_for_map_change(rpg_t *rpg, int map)
{
    if (rpg->input->interact.press) {
        rpg->input->interact.press = 0;
        rpg->data->location = map;
        if (rpg->data->location >= NB_MAP)
            rpg->data->location = 0;
        free_puzzle(rpg->puzzle);
        init_puzzle(rpg);
        free_monsters(rpg);
        free_items(rpg);
        init_monsters(rpg);
        switch_weather(rpg);
    }
}

void check_sign(entity_t *player, puzzle_t *puzzle, rpg_t *rpg)
{
    sfFloatRect rect = {0};
    int i = 0;

    for (; i < puzzle->nb_sign; i++)
        if (sfFloatRect_intersects(&player->rect,
            &puzzle->sign[i].rect, &rect)) {
            player->health.sign = 1;
            return check_for_map_change(rpg, puzzle->sign[i].map);
        }
    player->health.sign = 0;
}
