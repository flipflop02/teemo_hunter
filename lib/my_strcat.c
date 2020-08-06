/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "../include/my.h"

int lencat(char *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = lencat(dest);
    for (i = 0; src[i] != '\0'; i++){
        dest[j] = src[i];
        j++;
    }
    dest[j] = '\0';
    return (dest);
}
