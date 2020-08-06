/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** Display image
*/

#include "include/my.h"

int check_coord(sfVector2f pos, sfVector2f box, sfVector2f size)
{
    if (pos.x >= box.x && pos.x <= box.x + size.x
        && pos.y >= box.y && pos.y <= box.y + size.y)
        return (1);
    return (0);
}

t_menu *init_menu(t_menu *me)
{
    me->b_texture = sfTexture_createFromFile("src/textures/background.png", NULL);
    me->b_sprite = sfSprite_create();
    me->s_texture = sfTexture_createFromFile("src/textures/shop.png", NULL);
    me->s_sprite = sfSprite_create();
    me->t_play = sfTexture_createFromFile("src/textures/play.png", NULL);
    me->s_play = sfSprite_create();
    me->t_exit = sfTexture_createFromFile("src/textures/exit.png", NULL);
    me->s_exit = sfSprite_create();
    me->scale.x = 0.5;
    me->scale.y = 0.5;
    me->p_play.x = 225;
    me->p_play.y = 250;
    me->s_pos.x = 225;
    me->s_pos.y = 350;
    me->p_exit.x = 225;
    me->p_exit.y = 450;
    me->c_play.x = 384 * me->scale.x;
    me->c_play.y = 98 * me->scale.y;
    sfSprite_setTexture(me->s_play, me->t_play, sfTrue);
    sfSprite_setTexture(me->s_sprite, me->s_texture, sfTrue);
    sfSprite_setTexture(me->s_exit, me->t_exit, sfTrue);
    sfSprite_setTexture(me->b_sprite, me->b_texture, sfTrue);
    sfSprite_setScale(me->s_play, me->scale);
    sfSprite_setScale(me->s_exit, me->scale);
    sfSprite_setScale(me->s_sprite, me->scale);
    sfSprite_setPosition(me->s_exit, me->p_exit);
    sfSprite_setPosition(me->s_sprite, me->s_pos);
    sfSprite_setPosition(me->s_play, me->p_play);
    me->music = sfMusic_createFromFile("src/music/title_theme.ogg");
    sfMusic_play(me->music);
    sfMusic_setLoop(me->music, sfTrue);
    return (me);
}

t_menu *draw_menu(t_main *ma, t_menu *me)
{
    sfRenderWindow_drawSprite(ma->window, me->b_sprite, NULL);
    sfRenderWindow_drawSprite(ma->window, me->s_play, NULL);
    sfRenderWindow_drawSprite(ma->window, me->s_exit, NULL);
    sfRenderWindow_drawSprite(ma->window, me->s_sprite, NULL);
}

void handle_engine(t_main *ma, t_menu *me)
{
    char *level = my_put_nbr_base(ma->level, "0123456789");
    char *src = strdup("src/maps/");
    src = strcat(src, level);
    if (ma->l_arg == 0)
        engine(ma, me, src);
    else
        engine(ma, me, ma->filepath);
}

int title_event(t_main *ma, t_menu *me)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(ma->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(ma->window);
        if (event.type == sfEvtMouseButtonPressed) {
            if(check_coord(ma->cursor, me->p_play, me->c_play) == 1){
                sfMusic_stop(me->music);
                handle_engine(ma, me);
            }
            if(check_coord(ma->cursor, me->p_exit, me->c_play) == 1)
                sfRenderWindow_close(ma->window);
            if(check_coord(ma->cursor, me->s_pos, me->c_play) == 1){
                sfMusic_stop(me->music);
                shop(ma, me);
            }
        }
          
    }
}

int get_mouse_pos(t_main *ma){
    ma->mousepos = sfMouse_getPositionRenderWindow(ma->window);
    ma->cursor.x = (float)ma->mousepos.x;
    ma->cursor.y = (float)ma->mousepos.y;
}

int saving(int fd, t_main *ma)
{
    fd = open("save", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0644);
    write(fd, my_put_nbr_base(ma->gold, "0123456789"), len_nbr(ma->gold));
    write(fd, "\n", 1);
    write(fd, my_put_nbr_base(ma->hpmax, "0123456789"), len_nbr(ma->hpmax));
    write(fd, "\n", 1);
    write(fd, my_put_nbr_base(ma->level, "0123456789"), len_nbr(ma->level));
    write(fd, "\n", 1);
    write(fd, my_put_nbr_base(ma->damage, "0123456789"), len_nbr(ma->damage));
    write(fd, "\n", 1);
    write(fd, my_put_nbr_base(ma->hplevel, "0123456789"), len_nbr(ma->hplevel));
    write(fd, "\n", 1);
    write(fd, my_put_nbr_base(ma->dmglevel, "0123456789"), len_nbr(ma->dmglevel));
}

int load_file(int fd, t_main *ma)
{
    char *buffer = malloc(30001);
    char **tab;
    read(fd, buffer, 30000);
    tab = my_str_to_wordtoken(buffer, "\n");
    ma->gold = my_getnbr(tab[0]);
    ma->hpmax = my_getnbr(tab[1]);
    ma->level = my_getnbr(tab[2]);
    ma->damage = my_getnbr(tab[3]);
    ma->hplevel = my_getnbr(tab[4]);
    ma->dmglevel = my_getnbr(tab[5]);
}

int title_screen(t_main *ma, t_menu *me)
{
    me = init_menu(me);
    while (sfRenderWindow_isOpen(ma->window)){
        get_mouse_pos(ma);
        title_event(ma, me);
        sfRenderWindow_clear(ma->window, sfBlack);
        draw_menu(ma, me);
        sfRenderWindow_display(ma->window);
    }
    //   sfMusic_destroy(me->music);
}
