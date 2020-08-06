/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** Display image
*/

#include "include/my.h"

int victory_event(t_main *ma, t_menu *me, sfMusic *music)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(ma->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(ma->window);
        if (event.type == sfEvtMouseButtonPressed) {
            sfMusic_stop(music);
            title_screen(ma, me);
        }
                
    }
}

int victory(t_main *ma, t_menu *me)
{
    sfMusic *music;
    sfTexture *texture = sfTexture_createFromFile("src/textures/beemo.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    music = sfMusic_createFromFile("src/music/victory.ogg");
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(ma->window)){
        victory_event(ma, me, music);
        sfRenderWindow_clear(ma->window, sfBlack);
        sfRenderWindow_drawSprite(ma->window, sprite, NULL);
        sfRenderWindow_display(ma->window);
    }
}
