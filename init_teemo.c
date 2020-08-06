/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** Display image
*/

#include "include/my.h"

int init_teemo_one(t_teemo *te)
{
    te->tee_rec.width = 49;
    te->tee_rec.height = 49;
    te->tee_rec.top = 0;
    te->tee_rec.left = 0;
    te->tee_texture = sfTexture_createFromFile("src/textures/teemo_sprite.png", NULL);
    te->tee_sprite = sfSprite_create();
    te->tee_scale.x = 2.5;
    te->tee_scale.y = 2.5;
    te->tee_pos.x = 1200;
    te->tee_pos.y = 100;
    te->tee_or.x = 24.5;
    te->tee_or.y = 24.5;
    te->s_clock = sfClock_create();
    te->a_clock = sfClock_create();
    te->clock = sfClock_create();    
}

t_teemo *init_teemo(t_teemo *te)
{
    float angle = 0.0;
    te = malloc(sizeof(t_teemo));
    init_teemo_one(te);
    sfSprite_setTexture(te->tee_sprite, te->tee_texture, sfTrue);
    sfSprite_setScale(te->tee_sprite, te->tee_scale);
    sfSprite_setTextureRect(te->tee_sprite, te->tee_rec);
    sfSprite_setRotation(te->tee_sprite, angle);
    sfSprite_setPosition(te->tee_sprite, te->tee_pos);
    sfSprite_setOrigin(te->tee_sprite, te->tee_or);
    return (te);
}
