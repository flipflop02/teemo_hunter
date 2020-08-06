/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** Display image
*/

#include "include/my.h"

int init_one(t_engine *en)
{
    en->s_pause = sfSprite_create();
    en->t_pause = sfTexture_createFromFile("src/textures/pause.png", NULL);
    sfSprite_setTexture(en->s_pause, en->t_pause, sfTrue);
    en->s_quit_pause = sfSprite_create();
    en->t_quit_pause = sfTexture_createFromFile("src/textures/quit.png", NULL);
    en->scale_quit_pause.x = 0.5;
    en->scale_quit_pause.y = 0.5;
    en->pos_quit_pause.x = 525;
    en->pos_quit_pause.y = 350;
    en->size_quit_pause.x = 384 * en->scale_quit_pause.x;
    en->size_quit_pause.y = 98 * en->scale_quit_pause.y;
    sfSprite_setPosition(en->s_quit_pause, en->pos_quit_pause);
    sfSprite_setScale(en->s_quit_pause, en->scale_quit_pause);
    sfSprite_setTexture(en->s_quit_pause, en->t_quit_pause, sfTrue);
}

int init_two(t_engine *en)
{
    sfText_setFont(en->money, en->money_f);
    sfText_setColor(en->money, sfYellow);
    sfText_setPosition(en->money, en->mo_pos);
    sfSprite_setTexture(en->s_cursor, en->t_cursor, sfTrue);
    sfSprite_setTexture(en->m_sprite, en->m_texture, sfTrue);
    sfSprite_setTexture(en->s_sprite, en->s_texture, sfTrue);
    sfSprite_setTexture(en->s_sprite, en->s_texture, sfTrue);
    sfSprite_setTexture(en->s_health, en->t_health, sfTrue);
    sfSprite_setTextureRect(en->s_health, en->r_health);
    sfSprite_setTextureRect(en->s_sprite, en->s_rec);
    sfSprite_setPosition(en->m_sprite, en->m_pos);
    sfSprite_setPosition(en->s_health, en->p_health);
    sfSprite_setScale(en->s_sprite, en->s_scale);
    sfSprite_setScale(en->s_cursor, en->o_cursor);
    sfSprite_setScale(en->s_health, en->m_scale);
    sfSprite_setScale(en->m_sprite, en->m_scale);
    en->bk_clock = sfClock_create();
}

t_engine *init_vector(t_engine *en)
{
    en->m_pos.x = 1100;
    en->m_pos.y = -20;
    en->m_scale.x = 3;
    en->m_scale.y = 3;
    en->mo_pos.x = 1150;
    en->mo_pos.y = 600;
    en->r_health.width = 100;
    en->r_health.height = 8;
    en->r_health.top = 0;
    en->r_health.left = 0;
    en->p_health.x = 100;
    en->p_health.y = 600;
    en->o_cursor.x = 0.5;
    en->o_cursor.y = 0.5;
    en->s_scale.x = 3;
    en->s_scale.y = 3;
    en->s_rec.top = 0;
    en->s_rec.left = 0;
    en->s_rec.width = 500;
    en->s_rec.height = 250;
}

t_engine *init_engine(t_engine *en)
{    
    init_one(en);
    init_vector(en);
    en->money = sfText_create();
    en->money_f = sfFont_createFromFile("src/font/Minecraft.ttf");
    en->t_cursor = sfTexture_createFromFile("src/textures/cursor.png", NULL);
    en->s_cursor = sfSprite_create();
    en->m_texture = sfTexture_createFromFile("src/textures/mountain.png", NULL);
    en->m_sprite = sfSprite_create();
    en->s_texture = sfTexture_createFromFile("src/textures/sky.png", NULL);
    en->s_sprite = sfSprite_create();
    en->t_health = sfTexture_createFromFile("src/textures/hp.png", NULL);
    en->s_health = sfSprite_create();
    init_two(en);
    return (en);
}
