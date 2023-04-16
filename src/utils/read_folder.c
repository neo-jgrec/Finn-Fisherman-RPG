/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** read_folder
*/

#include <dirent.h>
#include "rpg.h"

char **read_dir(char *folder)
{
    DIR *dir = opendir(folder);
    struct dirent *file = NULL;
    size_t i = 0;
    char **saves;

    if (dir == NULL)
        return (NULL);
    while ((file = readdir(dir)) != NULL) {
        saves = my_realloc(saves, sizeof(char *) * (i + 1));
        if (file->d_name[0] != '.') {
            saves[i] = my_strdup(file->d_name);
            i++;
        }
    }
    saves[i] = NULL;
    closedir(dir);
    return (saves);
}
