/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_fish_spot
*/

#include "rpg.h"

static void add_fish_spot(puzzle_t *puzzle, char *spot)
{
    sfFloatRect pos = {0};
    char **stw = a_mkstw(spot, ":");
    int len = 0;

    for (; stw[len]; len++);
    if (len != 2)
        return;
    pos.left = my_atoi(stw[0]) * 64;
    pos.top = my_atoi(stw[1]) * 64;
    pos.height = 64;
    pos.width = 64;
    puzzle->fish_spot = add_colliders(puzzle->fish_spot,
        pos, &(puzzle->nb_fish_spot));
}

void init_fish_spot(puzzle_t *puzzle, xml_parser_t *parser)
{
    char **stw = NULL;
    char *fish_spot = get_value_by_tags(parser->root,
        (char *[]){"FISH", NULL});

    if (fish_spot == NULL)
        return;
    stw = a_mkstw(fish_spot, "\n");
    for (int i = 0; stw[i]; i++)
        add_fish_spot(puzzle, stw[i]);
    a_freestw(stw);
}
