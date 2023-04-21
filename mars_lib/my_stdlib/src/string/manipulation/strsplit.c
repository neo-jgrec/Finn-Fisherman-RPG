/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strsplit
*/

#include "my_stdlib.h"
#include <stdbool.h>

static bool ml_char_is_in_lst(const char c, const char *lst)
{
    for (size_t i = 0; lst[i] != '\0'; i++){
        if (lst[i] == c)
            return (true);
    }
    return (false);
}

static size_t count_words(char const *str, char const *token)
{
    size_t nb_words = 0;
    size_t i = 0;

    while (str[i] != '\0'){
        if (!ml_char_is_in_lst(str[i], token) &&
        (str[i + 1] == '\0' || ml_char_is_in_lst(str[i + 1], token)))
            nb_words++;
        i++;
    }
    return (nb_words);
}

static size_t get_size_word(char const *str, char const *token)
{
    size_t count = 0;
    while (!ml_char_is_in_lst(str[count], token) && str[count] != '\0')
        count++;
    return (count);
}

char **my_strsplit(char const *str, char const *token)
{
    size_t nb_word = count_words(str, token);
    char **word_arr = malloc(sizeof(char *) * (nb_word + 1));
    size_t size = my_strlen(str);
    size_t size_w = 0;
    size_t pos_arr = 0;

    if (!word_arr)
        return (NULL);
    for (size_t i = 0; i < size; i++){
        if (ml_char_is_in_lst(str[i], token))
            continue;
        size_w = get_size_word(&str[i], token);
        word_arr[pos_arr] = my_strndup(&str[i], size_w);
        i += size_w;
        pos_arr++;
    }
    word_arr[pos_arr] = NULL;
    return (word_arr);
}
