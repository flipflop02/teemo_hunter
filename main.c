/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** Display image
*/

#include "include/my.h"

int window(t_main *ma, t_menu *me)
{
    int fd = open("save", O_RDWR);
    if (fd == -1){
        ma->hpmax = 3;
        ma->gold = 0;
        ma->level = 1;
        ma->damage = 1;
        ma->hplevel = 1;
        ma->dmglevel = 1;
        fd = open("save", O_RDWR | O_CREAT | O_APPEND, 0644);
        saving(fd, ma);
    } else {
        load_file(fd, ma);
    }
    ma->wtype = 0;
    ma->mode = (sfVideoMode){1280, 720, 32};
    ma->window = sfRenderWindow_create(ma->mode, "Teemo Hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(ma->window, 60);
    title_screen(ma, me);
    saving(fd, ma);
}

int main(int ac, char **av)
{
    t_main *ma = malloc(sizeof(t_main));
    t_menu *me = malloc(sizeof(t_menu));
    ma->l_arg = 0;
    int i = 0;
    if (ac > 1){
        while (av[i] != NULL){
            if (my_strcmp(av[i], "-h\0") == 0){
                my_putstr(USAGE);
                return (0);
            }
            if (my_strcmp(av[i], "-L\0") == 0 && ac > 2){
                ma->filepath = my_strdup(av[2]);
                ma->l_arg = 1;
            }
            i++;
        }
    }
    window(ma, me);
}
