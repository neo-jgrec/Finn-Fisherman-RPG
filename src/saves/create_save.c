/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** create_save
*/

#include "rpg.h"
#include <fcntl.h>

static char *my_strreplace(const char *str_to_edit, char *str_to_replace, char *str_to_put)
{
    char *str = malloc(sizeof(char) * (my_strlen(str_to_edit) + my_strlen(str_to_put) + 1));
    char *tmp = str;
    char *tmp2 = (char*)str_to_edit;
    char *tmp3 = str_to_replace;
    int i = 0;

    for (; *tmp2; *tmp = *tmp2, tmp++, tmp2++) {
        if (my_strncmp(tmp2, tmp3, my_strlen(tmp3) != 0))
            continue;
        tmp2 += my_strlen(tmp3);
        for (; str_to_put[i]; *tmp = str_to_put[i], tmp++, i++);
        i = 0;
    }
    *tmp = '\0';
    return str;
}

void create_default_save_file(char *filename, char *save_name)
{
    int file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);

    write (file, my_strreplace(data_default_xml,
        "9667854", save_name),
        my_strlen(data_default_xml) + my_strlen(save_name) - 7);
    close(file);
}
