/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_sign
*/

#include "rpg.h"

#include "rpg.h"

sign_t *add_signt(sign_t *sign,
    sfFloatRect rect, int *nb_sign, int map)
{
    sign_t *new = malloc(sizeof(sign_t) * (*nb_sign + 2));

    if (new == NULL)
        return NULL;
    for (int i = 0; i < *nb_sign + 2; new[i] = (sign_t){0}, i++);
    for (int i = 0; i < *nb_sign; i++) {
        new[i].rect = sign[i].rect;
        new[i].map = sign[i].map;
    }
    new[*nb_sign].rect = rect;
    new[*nb_sign].map = map;
    *nb_sign += 1;
    if (sign != NULL)
        free(sign);
    return new;
}

static void add_sign(puzzle_t *puzzle, char *sign)
{
    sfFloatRect pos = {0};
    int map = 0;
    char **stw = a_mkstw(sign, ":");
    int len = 0;

    for (; stw[len]; len++);
    if (len != 3)
        return;
    pos.left = my_atoi(stw[0]) * 64;
    pos.top = my_atoi(stw[1]) * 64;
    map = my_atoi(stw[2]);
    pos.height = 64;
    pos.width = 192;
    puzzle->sign = add_signt(puzzle->sign,
        pos, &(puzzle->nb_sign), map);
    a_freestw(stw);
}

void init_sign(puzzle_t *puzzle, xml_parser_t *parser)
{
    char **stw = NULL;
    char *sign = get_value_by_tags(parser->root,
        (char *[]){"SIGN", NULL});

    if (sign == NULL)
        return;
    stw = a_mkstw(sign, "\n");
    for (int i = 0; stw[i]; i++)
        add_sign(puzzle, stw[i]);
    a_freestw(stw);
}
