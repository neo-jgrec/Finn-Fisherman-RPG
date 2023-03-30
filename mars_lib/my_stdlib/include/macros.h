/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** macros
*/

#ifndef MACROS_H_
    #define MACROS_H_

    #include <stddef.h>

    /* GCC attributs */
    #define UNUSED __attribute__((unused))

    /* Math macros */
    #define ABS(x) ((x) < 0 ? -(x) : (x))
    #define MIN(x, y) ((x) < (y) ? (x) : (y))
    #define MAX(x, y) ((x) > (y) ? (x) : (y))
    #define IS_ODD(x) ((x) & 1)
    #define IS_EVEN(x) (!IS_ODD(x))
    #define IS_PRIME(x) (x > 1 && (x == 2 || x == 3 || (x % 2 && x % 3)))
    #define PRIME_SUP(x)\
    !IS_PRIME(x) ? (x < 2 ? 2 : (x == 2 ? 3 : (x % 2 ? x + 2 : x + 1))) : x

    /* Swap macros */
    #define SWAP(x, y) ((x) ^= (y) ^= (x) ^= (y))
    #define SWAP_PTR(x, y) ((x) ^= (y) ^= (x) ^= (y))

    /* String macros */
    #define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')
    #define IS_LOWER(c) ((c) >= 'a' && (c) <= 'z')
    #define IS_ALPHA(c) (IS_UPPER(c) || IS_LOWER(c))
    #define IS_NUM(c) ((c) >= '0' && (c) <= '9')
    #define IS_ALPHANUM(c) (IS_ALPHA(c) || IS_NUM(c))
    #define IS_ASCII(c) ((c) >= 0 && (c) <= 127)
    #define IS_PRINTABLE(c) ((c) >= 32 && (c) <= 126)

    #define TO_UPPER(c) (IS_LOWER(c) ? (c) - 32 : (c))
    #define TO_LOWER(c) (IS_UPPER(c) ? (c) + 32 : (c))

    /* Integer macros */
    #define IS_NEGATIVE(c) ((c) < 0)
    #define IS_POSITIVE(c) ((c) > 0)
    #define IS_ZERO(c) ((c) == 0)

    /* Array macros */
    #define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

    /* Random macros */
    #define RANDINT(min, max) ((rand() % (max - min + 1)) + min)

#endif /* !MACROS_H_ */
