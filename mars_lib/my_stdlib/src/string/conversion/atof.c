/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** atof
*/

float my_atof(const char *str)
{
    int i = 0;
    int sign = 1;
    float nb = 0;
    float dec = 0;

    for (; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            sign *= -1;
    }
    for (;str[i] >= '0' && str[i] <= '9'; i++)
        nb = nb * 10 + str[i] - '0';
    if (str[i] == '.')
        i++;
    for (int j = 1; str[i] >= '0' && str[i] <= '9'; j++, i++)
        dec = dec * 10 + str[i] - '0';
    return ((nb + (dec / 10)) * sign);
}
