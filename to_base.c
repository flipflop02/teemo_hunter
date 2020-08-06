/*
** EPITECH PROJECT, 2019
** evalexpr
** File description:
** bistro
*/

#include "include/my.h"

char *conv(char *str, char *base){
    int i = 0;
    while (str[i] != '\0'){
        str[i] = base[str[i] - '0'];
        i++;
    }
    return (str);
}

int len_base(int nb, int b)
{
    int i = 0;
    while (nb > 0){
        nb = nb / b;
        i++;
    }
    return (i);
}

char *my_put_nbr_base(int nb, char *base)
{
    int i = 0;
    int b = my_strlen(base);
    char *str = malloc(sizeof(char) * (len_base(nb, b)));
    if (nb == 0) {
        return ("0");
    }
    while (nb > 0){
        str[i] = base[nb % b];
        nb = nb / b;
        i++;
    }
    str[i] = '\0';
    return (my_revstr(str));
}
