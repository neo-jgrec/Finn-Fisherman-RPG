/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** map_parser
*/

#include "mars.h"
#include <string.h>

static const char *delimiter = ",\n";

int **map_parsing(const char *src)
{
    int rows = 0, cols = 0, row = -1, col = 0, i;
    char *token, *map_copy = my_strdup(src);
    int **map;

    for (i = 0; src[i] != '\0'; rows = (src[i] == '\n') ? rows + 1 : rows, i++)
        cols = (rows == 0 && src[i] == ',') ? cols + 1 : cols;
    map = (int **)my_calloc((rows + 2), sizeof(int *));
    for (i = 0; i < (rows + 2); i++)
        map[i] = (int *)my_calloc((cols + 2), sizeof(int));
    token = my_strtok(map_copy, delimiter);
    for (; token != NULL; col++, token = my_strtok(NULL, delimiter)) {
        col = (col == (cols + 2) - 1) ? 0 : col;
        row = (col == 0) ? row + 1 : row;
        map[row][col] = my_atoi(token) - 1;
    }
    for (int i = 0; i < (rows + 2) - 1; map[i][(cols + 2) - 1] = -2, i++);
    map[rows] = NULL;
    free(map_copy);
    return map;
}
