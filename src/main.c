/*
** EPITECH PROJECT, 2023
** project-maker
** File description:
** main
*/

#include "rpg.h"

int verifier2000(void);

static void help(void)
{
    my_printf("USAGE\t\t./my_rpg\n");
    my_printf("DESCRIPTION\tThis is a RPG game made with CSFML.\n");
    my_printf("\t\tFor more information, please read the documentation\
:\n\t\t https://neo-19.gitbook.io/the-fisherman/\n");
    my_printf("\nNOTE : If you do not have all the assets,\
the game will not start at all.\n");
}

int main(int ac, UNUSED char **av)
{
    srand(time(NULL));
    if (ac == 2
        && (!my_strcmp(av[1], "-h") || !my_strcmp(av[1], "--help"))) {
        help();
        return 0;
    }
    if (ac != 1)
        return 0;
    if (verifier2000() == 84)
        return 84;
    return rpg();
}
