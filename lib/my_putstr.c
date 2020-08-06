/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** pool
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;
    if (str == NULL)
        return (0);
    for (i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
    return (i);
}
