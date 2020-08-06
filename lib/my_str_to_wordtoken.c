/*
** EPITECH PROJECT, 2019
** main
** File description:
** c
*/

#include "../include/my.h"

int corresponding(char c, char *string)
{
    int i = 0;
    while (string[i] != '\0'){
        if (c == string[i])
            return (1);
        i++;
    }
    return (0);
}

int count_corresponding(char *str, char *string)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0'){
        if (corresponding(str[i], string) == 1)
            j++;
        i++;
    }
    return (j);
}

char **my_str_to_wordtoken(char *str, char *string)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **tab = malloc(sizeof(char *) * (count_corresponding(str, string) + 4));
    tab[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0'){
        if (corresponding(str[i], string) == 1){
            tab[j][k] = '\0';
            j++;
            k = 0;
            tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
        } else {
            tab[j][k] = str[i];
            k++;
        }
        i++;
    }
    tab[j][k] = '\0';
    tab[j + 1] = NULL;
    return (tab);
}
