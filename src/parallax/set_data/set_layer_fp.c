/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_layer_fp
*/

#include <sys/types.h>
#include <dirent.h>
#include "rpg.h"

static ssize_t is_valid_layer(struct dirent *files)
{
    if (files->d_type != 8)
        return -1;
    if (my_atoi(files->d_name) <= 0)
        return -1;
    return (my_atoi(files->d_name) - 1);
}

static size_t count_files(char *folder_fp)
{
    DIR *stream = opendir(folder_fp);
    struct dirent *files;
    size_t nb = 0;

    if (stream == NULL)
        return nb;
    while ((files = readdir(stream))) {
        if (is_valid_layer(files))
            nb++;
    }
    closedir(stream);
    return nb;
}

static char *get_complete_path(struct dirent *file, char *folder_fp)
{
    size_t ffp_len = my_strlen(folder_fp);
    size_t fn_len = my_strlen(file->d_name);
    size_t sup = 1;
    char *c_path = NULL;

    if (folder_fp[ffp_len - 1] != '/')
        sup++;
    c_path = malloc(sizeof(char) * (ffp_len + fn_len + sup));
    if (c_path == NULL)
        return NULL;
    for (size_t i = 0; i <= ffp_len + fn_len + sup; i++)
        c_path[i] = '\0';
    c_path = my_strcat(c_path, folder_fp);
    if (folder_fp[ffp_len - 1] != '/')
        c_path[ffp_len] = '/';
    c_path = my_strcat(c_path, file->d_name);
    return c_path;
}

static void set_fp_in_struct(parallax_t *back, char *folder_fp)
{
    DIR *stream = opendir(folder_fp);
    struct dirent *files = NULL;
    ssize_t pos;
    char *complete_path = NULL;

    while ((files = readdir(stream))) {
        pos = is_valid_layer(files);
        if (pos >= 0) {
            complete_path = get_complete_path(files, folder_fp);
            FILEPATHS[pos] = my_strdup(complete_path);
        }
    }
    closedir(stream);
    return;
}

void set_layer_fp(parallax_t *back, char *folder_fp)
{
    size_t nb_files = count_files(folder_fp);

    if (nb_files == 0)
        return;
    FILEPATHS = malloc(sizeof (char *) * (nb_files + 1));
    if (FILEPATHS == NULL)
        return;
    NB_FILES = nb_files;
    FILEPATHS[nb_files] = NULL;
    set_fp_in_struct(back, folder_fp);
    return;
}
