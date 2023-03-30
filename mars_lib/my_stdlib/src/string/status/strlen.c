/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strlen
*/

int my_strlen(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
