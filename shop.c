/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** Display image
*/

#include "include/my.h"

t_shop *init_shop(t_shop *sh)
{
    sh->q_texture = sfTexture_createFromFile("src/textures/quit.png", NULL);
    sh->q_sprite = sfSprite_create();
    sh->hp_texture = sfTexture_createFromFile("src/textures/ruby_crystal.png", NULL);
    sh->hp_sprite = sfSprite_create();
    sh->dmg_texture = sfTexture_createFromFile("src/textures/toxic_shot.png", NULL);
    sh->dmg_sprite = sfSprite_create();
    sh->b_texture = sfTexture_createFromFile("src/textures/shopbck.png", NULL);
    sh->s_font = sfFont_createFromFile("src/font/Minecraft.ttf");
    sh->price_dmg = sfText_create();
    sh->price_hp = sfText_create();
    sh->gold = sfText_create();
    sh->b_sprite = sfSprite_create();
    sh->b_scale.x = 1.0;
    sh->b_scale.y = 1.0;
    sh->q_scale.x = 0.5;
    sh->q_scale.y = 0.5;
    sh->q_pos.x = 1050;
    sh->q_pos.y = 550;
    sh->hp_pos.x = 500;
    sh->hp_pos.y = 150;
    sh->hp_scale.x = 1.25;
    sh->hp_scale.y = 1.25;
    sh->hppos.x = 650;
    sh->hppos.y = 175;
    sh->dpos.x = 650;
    sh->dpos.y = 275;
    sh->hp_size.x = 64 * sh->hp_scale.x;
    sh->hp_size.y = 64 * sh->hp_scale.y;
    sh->dmg_pos.x = 500;
    sh->dmg_pos.y = 250;
    sh->dmg_scale.x = 1.25;
    sh->dmg_scale.y = 1.25;
    sh->dmg_size.x = 64 * sh->dmg_scale.x;
    sh->dmg_size.y = 64 * sh->dmg_scale.y;
    sh->q_size.x = 384 * sh->q_scale.x;
    sh->q_size.y = 98 * sh->q_scale.y;
    sfText_setFont(sh->price_dmg, sh->s_font);
    sfText_setFont(sh->price_hp, sh->s_font);
    sfText_setFont(sh->gold, sh->s_font);
    sfText_setColor(sh->gold, sfYellow);
    sfText_setColor(sh->price_dmg, sfBlue);
    sfText_setColor(sh->price_hp, sfBlue);
    sfText_setPosition(sh->price_hp, sh->hppos);
    sfText_setPosition(sh->price_dmg, sh->dpos);
    sfSprite_setScale(sh->q_sprite, sh->q_scale);
    sfSprite_setPosition(sh->q_sprite, sh->q_pos);
    sfSprite_setPosition(sh->hp_sprite, sh->hp_pos);
    sfSprite_setScale(sh->hp_sprite, sh->hp_scale);
    sfSprite_setPosition(sh->dmg_sprite, sh->dmg_pos);
    sfSprite_setScale(sh->dmg_sprite, sh->dmg_scale);
    sfSprite_setScale(sh->b_sprite, sh->b_scale);
    sfSprite_setTexture(sh->hp_sprite, sh->hp_texture, sfTrue);
    sfSprite_setTexture(sh->dmg_sprite, sh->dmg_texture, sfTrue);
    sfSprite_setTexture(sh->b_sprite, sh->b_texture, sfTrue);
    sfSprite_setTexture(sh->q_sprite, sh->q_texture, sfTrue);
}

t_shop *draw_shop(t_main *ma, t_shop *sh)
{
    sfRenderWindow_drawSprite(ma->window, sh->b_sprite, NULL);
    sfRenderWindow_drawSprite(ma->window, sh->hp_sprite, NULL);
    sfRenderWindow_drawSprite(ma->window, sh->dmg_sprite, NULL);
    sfRenderWindow_drawSprite(ma->window, sh->q_sprite, NULL);
    sfRenderWindow_drawText(ma->window, sh->price_dmg, NULL);
    sfRenderWindow_drawText(ma->window, sh->price_hp, NULL);
    sfRenderWindow_drawText(ma->window, sh->gold, NULL);
}

int price_toxic(t_main *ma, t_menu *me, t_shop *sh, int bprice)
{
    float tax = (0.1 * (float)ma->dmglevel) + 1;
    float fprice = bprice * tax;
    int price = (int)fprice;
    sfText_setString(sh->price_dmg, my_put_nbr_base(price, "0123456789"));
    return (0);
}

int price_cryst(t_main *ma, t_menu *me, t_shop *sh, int bprice)
{
    float tax = (0.1 * (float)ma->hplevel) + 1;
    float fprice = bprice * tax;
    int price = (int)fprice;
    sfText_setString(sh->price_hp, my_put_nbr_base(price, "0123456789"));
    return (0);
}

int handle_cryst(t_main *ma, t_menu *me, t_shop *sh, int bprice)
{
    float tax = (0.1 * (float)ma->hplevel) + 1;
    float fprice = bprice * tax;
    int price = (int)fprice;
    if (ma->gold < price)
        return (0);
    sh->music = sfMusic_createFromFile("src/music/level_up.ogg");
    sfText_setString(sh->gold, my_put_nbr_base(ma->gold, "0123456789"));
    sfMusic_play(sh->music);
    ma->gold = ma->gold - price;
    ma->hplevel++;
    ma->hpmax++;
    saving(0, ma);
    price_cryst(ma, me, sh, 15);
    return (1);
}

int handle_toxic(t_main *ma, t_menu *me, t_shop *sh, int bprice)
{
    float tax = (0.1 * (float)ma->dmglevel) + 1;
    float fprice = bprice * tax;
    int price = (int)fprice;
    if (ma->gold < price)
        return (0);
    sh->music = sfMusic_createFromFile("src/music/level_up.ogg");
    sfText_setString(sh->gold, my_put_nbr_base(ma->gold, "0123456789"));
    sfMusic_play(sh->music);
    ma->gold = ma->gold - price;
    ma->dmglevel++;
    ma->damage++;
    saving(0, ma);
    price_toxic(ma, me, sh, 43);
    return (1);
}

int shop_event(t_main *ma, t_menu *me, t_shop *sh)
{
    sfEvent event;
       while (sfRenderWindow_pollEvent(ma->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(ma->window);
        if (event.type == sfEvtMouseButtonPressed) {
            if (check_coord(ma->cursor, sh->q_pos, sh->q_size) == 1){
                sfMusic_stop(sh->theme);
                title_screen(ma, me);
            }
            if (check_coord(ma->cursor, sh->hp_pos, sh->hp_size) == 1)
                handle_cryst(ma, me, sh, 15);
            if (check_coord(ma->cursor, sh->dmg_pos, sh->dmg_size) == 1)
                handle_toxic(ma, me, sh, 43);
        }
                
    }
}

int shop(t_main *ma, t_menu *me)
{
    t_shop *sh = malloc(sizeof(t_shop));
    sh->music = sfMusic_createFromFile("src/music/level_up.ogg");
    sh->theme = sfMusic_createFromFile("src/music/shop.ogg");
    sfMusic_play(sh->theme);
    sfMusic_setLoop(sh->theme, sfTrue);
    sfMusic_setVolume(sh->theme, 50);
    init_shop(sh);
    sfText_setString(sh->gold, my_put_nbr_base(ma->gold, "0123456789"));
    price_cryst(ma, me, sh, 15);
    price_toxic(ma, me, sh, 43);
    while (sfRenderWindow_isOpen(ma->window)){
        get_mouse_pos(ma);
        shop_event(ma, me, sh);
        sfRenderWindow_clear(ma->window, sfBlack);
        draw_shop(ma, sh);
        sfRenderWindow_display(ma->window);
    }
}
