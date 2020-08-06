/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** Display image
*/

#include "include/my.h"

t_engine *destroy_engine(t_engine *en, t_teemo *te)
{
    sfSprite_destroy(te->tee_sprite);
    sfSprite_destroy(en->m_sprite);
    sfSprite_destroy(en->s_sprite);
}

t_engine *draw_gui(t_main *ma, t_engine *en)
{
    sfRenderWindow_drawText(ma->window, en->money, NULL);
}

t_engine *draw_engine(t_main *ma, t_engine *en, t_teemo *te)
{
    sfRenderWindow_drawSprite(ma->window, en->s_sprite, NULL);
    sfRenderWindow_drawSprite(ma->window, en->m_sprite, NULL);
    sfRenderWindow_drawSprite(ma->window, te->tee_sprite, NULL);
}

int animate_teemo(float second, t_teemo *te){
    if (second <= 1.0){
        sfSprite_setRotation(te->tee_sprite, 15.0);
    } else {
        sfSprite_setRotation(te->tee_sprite, 0.0);
    }
}

int check_hitbox(t_monster *mo, int c, t_main *ma)
{
    int i = 0;
    while (i < c){
        if (check_coord(ma->cursor, mo[i].pos, mo[i].size) == 1){
            mo[i].hp = mo[i].hp - ma->damage;
            mo[i].croi = 100 - (mo[i].hp * 100)/mo[i].hpmax;
            mo[i].r_hp.left = mo[i].croi;
            sfSprite_setTextureRect(mo[i].s_hp, mo[i].r_hp);
        }
        i++;
    }
}
