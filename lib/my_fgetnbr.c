/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** pool
*/

#include "../include/my.h"

float my_fgetnbr(char *str)
{
    int first = my_getnbr(str);
    int i = 0;
    float res = (float)first;
    while (str[i] != '\0'){
        if (str[i] == '.')
            res = res + (0.1 * my_getnbr(&str[i]));
        i++;
    }
    return (res);
}
