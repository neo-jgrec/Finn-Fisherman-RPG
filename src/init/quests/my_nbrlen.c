/*
** EPITECH PROJECT, 2023
** ml_nbrlen
** File description:
** ml_nbrlen
*/

#include <unistd.h>

size_t my_nbrlen(int nbr)
{
    size_t count = 0;

    if (nbr < 0)
        return (my_nbrlen(-nbr) + 1);
    if (nbr == 0)
        return (1);
    while (nbr != 0){
        count++;
        nbr /= 10;
    }
    return (count);
}
