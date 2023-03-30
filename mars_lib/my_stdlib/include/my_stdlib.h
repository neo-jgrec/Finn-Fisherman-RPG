/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** stdlib
*/

#ifndef STDLIB_H_
    #define STDLIB_H_

    #include <stddef.h>

    #include "memory.h"
    #include "macros.h"

    /**
    * @brief Converts a string to a long integer.
    *
    * @param str String to convert.
    * @return long
    */
    long my_atol(const char *str);

    /**
    * @brief Converts a string to an integer.
    *
    * @param str String to convert.
    * @return int
    */
    int my_atoi(const char *str);

    /**
    * @brief Converts a string to a float.
    *
    * @param str String to convert.
    * @return float
    */
    float my_atof(const char *str);

    /**
    * @brief Converts a string to a double.
    *
    * @param str String to convert.
    * @return double
    */
    double my_strtod(const char *str, char **endptr);

    /**
    * @brief Concatenates n first characters of src to dest.
    *
    * @param dest String to concatenate to.
    * @param src String to concatenate.
    * @param n Number of characters to concatenate.
    * @return char*
    */
    char *my_strncat(char *dest, const char *src, size_t n);

    /**
    * @brief Concatenates src to dest.
    *
    * @param dest String to concatenate to.
    * @param src String to concatenate.
    * @return char*
    */
    char *my_strcat(char *dest, const char *src);

    /**
    * @brief Concatenate a char to a string
    *
    * @param dest string to concatenate to
    * @param src char to concatenate
    * @return char*
    */
    char *my_strcat_char(char *dest, const char src);

    /**
    * @brief Get the length of a string
    *
    * @param str String to get the length
    */
    int my_strlen(const char *str);

    /**
    * @brief Get the length of a string
    *
    * @param str String to duplicate
    * @return char*
    */
    char *my_strdup(const char *str);

    /**
    * @brief Duplicate n first char of a string
    *
    * @param str string to duplicate
    * @param n number of char to duplicate
    * @return char*
    */
    char *my_strndup(const char *str, size_t n);

    /**
    * @brief Split a string into an array of string
    *
    * @param str String to split
    * @param delim Selimiter (ex: '\\t')
    * @return char**
    */
    char **my_strsplit(const char *str, const char delim);

    /**
    * @brief Reverse a string
    *
    * @param str String to reverse
    * @return char*
    */
    char *my_revstr(char *str);

    /**
    * @brief Compare two strings
    *
    * @param s1 first string to compare
    * @param s2 second string to compare
    * @return int
    * @note my_strncmp is better
    */
    int my_strcmp(const char *s1, const char *s2);

    /**
    * @brief Compare two strings
    *
    * @param s1 first string to compare
    * @param s2 second string to compare
    * @param n number of char to compare
    * @return int
    */
    int my_strncmp(const char *s1, const char *s2, size_t n);

    /**
    * @brief Look for the first occurence of c in str
    *
    * @param str the string to look in
    * @param c the char to look for
    * @return char*
    */
    char *my_strchr(const char *str, int c);

    /**
    * @brief Clean a string from a set of char
    *
    * @param str the string to clean
    * @param to_clean the set of char to remove from str
    * @return char*
    */
    char *clean_str(char *str, const char *to_clean);

    /**
    * @brief Copy a string
    *
    * @param dest The string to copy to
    * @param src The string to copy
    * @return char*
    */
    char *my_strcpy(char *dest, const char *src);

    /**
    * @brief Copy n first char of a string
    *
    * @param dest string to copy to
    * @param src string to copy
    * @param n number of char to copy
    * @return char*
    */
    char *my_strncpy(char *dest, const char *src, size_t n);

    /**
    * @brief Look for the first occurence of substring in fullstring
    *
    * @param fullstring the string to look in
    * @param substring the string to look for
    * @return char*
    */
    char *my_strstr(const char *fullstring, const char *substring);

    /**
    * @brief Remove a set of char from a string
    *
    * @param str string to remove char from
    * @param str_to_remove set of char to remove
    * @return char*
    */
    char *my_strremove(char *str, const char *str_to_remove);

    /**
    * @brief Look for the first occurence of substring in fullstring
    * and return the index of the first char of substring
    *
    * @param fullstring string to look in
    * @param substring string to look for
    * @return int
    */
    int my_strstr_index(const char *fullstring, const char *substring);

    /**
    * @brief Concatenate a string with an infinite number of string
    *
    * @param nb number of string to concatenate
    * @param ... strings to concatenate
    * @return char* - the concatenated string
    */
    char *my_strcat_inf(int nb, ...);

#endif /* !STDLIB_H_ */
