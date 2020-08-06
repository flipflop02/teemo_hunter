/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** epitech
*/

#include "../include/my.h"

int lenr(const char *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

char *my_revstr(char *str)
{
    char tmp[lenr(str)];
    int i;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++)
        tmp[i] = str[i];

    for (i = lenr(str) - 1; i >= 0; i--){
        str[j] = tmp[i];
        j++;
    }
    return (str);
}
