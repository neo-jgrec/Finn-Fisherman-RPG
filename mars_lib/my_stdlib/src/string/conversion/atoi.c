/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** atoi
*/

int my_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int nb = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    return (nb * sign);
}
