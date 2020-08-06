/*
** EPITECH PROJECT, 2019
** main
** File description:
** c
*/

#include "include/my.h"

int u_len_nbr(unsigned int nb)
{
    int i = 0;
    if (nb == 0)
        return (1);
    while (nb > 9){
        nb = nb / 10;
        i++;
    }
    return (i);
}

int len_nbr(int nb)
{
    int i = 0;
    if (nb == 0)
        return (1);
    if (nb < 0) {
        nb = nb * -1;
        i++;
    }
    while (nb > 0){
        nb = nb / 10;
        i++;
    }
    return (i);
}
