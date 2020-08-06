/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** Display image
*/

#include "include/my.h"

int engine_event(t_main *ma, t_engine *en, t_monster *mo, t_teemo *te, t_menu *me)
{
    while (sfRenderWindow_pollEvent(ma->window, &ma->event)){
        if (ma->event.type == sfEvtClosed) {
            sfRenderWindow_close(ma->window);
        }
        if (ma->event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape)){
            if (en->pause == 1)
                en->pause = 0;
            else
                en->pause = 1;
        }
        if (ma->event.type == sfEvtMouseButtonPressed){
            if (en->pause == 0){
                sfMusic_play(te->t_sound);
                sfClock_restart(te->a_clock);
                check_hitbox(mo, en->c, ma);
            }
            if (en->pause == 1){
                if (check_coord(ma->cursor, en->pos_quit_pause, en->size_quit_pause) == 1){
                    sfRenderWindow_setMouseCursorVisible(ma->window, sfTrue);
                    title_screen(ma, me);
                }
            }
        }
    }
}

char **get_content(char const *path)
{
    int fd;
    char *buffer = malloc(30000);
    char *output;
    char **tab;
    fd = open(path, O_RDONLY);
    read(fd, buffer, 10000);
    tab = my_str_to_wordtoken(buffer, "\n");
    return (tab);
}

int count_monster(char *content)
{
    int i = 0;
    if (my_strcmp(content, "MONSTER") == 0)
        return (1);
    return (0);
}

t_monster *get_monster(t_monster *mo, char **content, int *c)
{
    int i = 0;
    int j = 0;
    char **pars;
    while (content[i] != NULL){
        pars = my_str_to_wordtoken(content[i], ":");
        *c = *c + count_monster(pars[0]);
        free(pars);
        i++;
    }
    i = 0;
    mo = malloc(sizeof(t_monster) * *c + 10);
    while (content[i] != NULL){
        pars = my_str_to_wordtoken(content[i], ":");
        if (count_monster(pars[0]) == 1){
            mo[j].r_hp.width = 100;
            mo[j].r_hp.height = 8;
            mo[j].r_hp.top = 0;
            mo[j].r_hp.left = 0;
            mo[j].hp = my_getnbr(pars[1]);
            mo[j].hpmax = my_getnbr(pars[1]);
            mo[j].speed = my_getnbr(pars[2]);
            mo[j].time = my_getnbr(pars[4]);
            mo[j].is_alive = 1;
            mo[j].t_hp = sfTexture_createFromFile("src/textures/ev_hp.png", NULL);
            mo[j].s_hp = sfSprite_create();
            mo[j].texture = sfTexture_createFromFile(pars[8], NULL);
            mo[j].sprite = sfSprite_create();
            mo[j].scale.x = my_fgetnbr(pars[9]);
            mo[j].scale.y = my_fgetnbr(pars[9]);
            mo[j].damage = my_getnbr(pars[10]);
            mo[j].goldrop = my_getnbr(pars[11]);
            mo[j].pos.x = my_getnbr(pars[5]) * -1 * mo[j].scale.x;
            mo[j].pos.y = my_getnbr(pars[3]);
            mo[j].origin = mo[j].pos.y;
            mo[j].rect.top = 0;
            mo[j].rect.left = 0;
            mo[j].rect.width = my_getnbr(pars[5]);
            mo[j].rect.height = my_getnbr(pars[6]);
            mo[j].size.x = my_getnbr(pars[5]) * mo[j].scale.x;
            mo[j].size.y = my_getnbr(pars[6]) * mo[j].scale.y;
            mo[j].sc_hp.x = mo[j].size.x / 100;
            mo[j].sc_hp.y = mo[j].scale.y;
            mo[j].width = my_getnbr(pars[5]);
            mo[j].frame = my_getnbr(pars[7]);
            mo[j].p_hp.x = mo[j].pos.x;
            mo[j].p_hp.y = mo[j].pos.y;
            sfSprite_setTexture(mo[j].sprite, mo[j].texture, sfTrue);
            sfSprite_setTexture(mo[j].s_hp, mo[j].t_hp, sfTrue);
            sfSprite_setPosition(mo[j].sprite, mo[j].pos);
            sfSprite_setScale(mo[j].sprite, mo[j].scale);
            sfSprite_setScale(mo[j].s_hp, mo[j].sc_hp);
            sfSprite_setTextureRect(mo[j].sprite, mo[j].rect);
            sfSprite_setTextureRect(mo[j].s_hp, mo[j].r_hp);
            sfSprite_setPosition(mo[j].s_hp, mo[j].p_hp);
            j++;
        }
        i++;
    }
    return (mo);
}

int start_time(t_monster *mo, int c)
{
    int i = 0;
    while (i < c){
        mo[i].time = mo[i].time - 1;
        i++;
    }
}

int loot(t_monster *mo, t_engine *en, t_main *ma, int c)
{
    int i = 0;
    while (i < c){
        if (mo[i].is_alive == 1 && mo[i].hp <= 0){
            mo[i].is_alive = 0;
            mo[i].pos.x = -5000;
            ma->gold = ma->gold + mo[i].goldrop;
            sfSprite_setPosition(mo[i].sprite, mo[i].pos);
            sfSprite_setPosition(mo[i].s_hp, mo[i].pos);
            saving(0, ma);
            sfText_setString(en->money, my_put_nbr_base(ma->gold, "0123456789"));

        }
        i++;
    }
}

int animate(t_monster *mo, int c)
{
    int i = 0;
    while (i < c){
        if (mo[i].rect.left >= mo[i].width * mo[i].frame){
            mo[i].rect.left = 0;
            sfSprite_setTextureRect(mo[i].sprite, mo[i].rect);
        } else {
            mo[i].rect.left = mo[i].rect.left + mo[i].width;
            sfSprite_setTextureRect(mo[i].sprite, mo[i].rect);
        }
        i++;
    }
}

int is_dead(t_monster *mo, t_main *ma, int c)
{
    int i = 0;
    while (i < c){
        if (mo[i].is_alive == 1)
            return (0);
        i++;
    }
    return (1);
}

int draw_monster(t_monster *me, t_main *ma, int c)
{
    int i = 0;
    while (i < c){
        sfRenderWindow_drawSprite(ma->window, me[i].sprite, NULL);
        sfRenderWindow_drawSprite(ma->window, me[i].s_hp, NULL);
        i++;
    }
}

int go_monster(t_monster *mo, int c, int *hp)
{
    int i = 0;
    while (i < c){
        if (mo[i].pos.x > 1280){
            mo[i].pos.x = mo[i].width * -1 * mo[i].scale.x;
            mo[i].pos.y = mo[i].origin;
            sfSprite_setPosition(mo[i].sprite, mo[i].pos);
            *hp = *hp - mo[i].damage;
        }
        if (mo[i].is_alive == 1 && mo[i].time <= 0){
            mo[i].pos.x = mo[i].pos.x + mo[i].speed;
            mo[i].p_hp.x = mo[i].pos.x;
            mo[i].p_hp.y = mo[i].pos.y;
            sfSprite_setPosition(mo[i].s_hp, mo[i].p_hp);
            sfSprite_setPosition(mo[i].sprite, mo[i].pos);
        }
        i++;
    }
}

int a_sec_inter(t_teemo *te)
{
    if (te->a_sec < 1){
        te->tee_rec.top = 49;
        sfSprite_setRotation(te->tee_sprite, 0);
        sfSprite_setTextureRect(te->tee_sprite, te->tee_rec);
    }
    if (te->a_sec > 1 && te->a_sec < 2){
        te->tee_rec.top = 49*2;
        sfSprite_setRotation(te->tee_sprite, 0);
        sfSprite_setTextureRect(te->tee_sprite, te->tee_rec);
    }
    if (te->a_sec > 2) {
        te->tee_rec.top = 0;
        sfSprite_setTextureRect(te->tee_sprite, te->tee_rec);
        animate_teemo(te->second, te);
    }
}

int get_clock_time(t_teemo *te)
{
    te->time = sfClock_getElapsedTime(te->clock);
    te->a_time = sfClock_getElapsedTime(te->a_clock);
    te->a_sec = te->a_time.microseconds/100000.0;
    te->second = te->time.microseconds/1000000.0;
    te->s_time = sfClock_getElapsedTime(te->s_clock);
    te->miliseconds = te->s_time.microseconds/100000.0;
}

int move_bck(t_engine *en)
{
    if (en->bk_sec > 1.0){
        if (en->s_rec.left >= 1000){
            en->s_rec.left = 0;
            sfSprite_setTextureRect(en->s_sprite, en->s_rec);
        } else {
            en->s_rec.left = en->s_rec.left + 1;
            sfSprite_setTextureRect(en->s_sprite, en->s_rec);
        }
        sfClock_restart(en->bk_clock);
    }
}

int tee_move(t_teemo *te)
{
    if (te->dif.y > 5 && te->tee_pos.y < 510){
        te->tee_pos.y = te->tee_pos.y + 5;
        sfSprite_setPosition(te->tee_sprite, te->tee_pos);
    }
    if (te->dif.y < -5){
        te->tee_pos.y = te->tee_pos.y - 5;
        sfSprite_setPosition(te->tee_sprite, te->tee_pos);
    }
}

int engine(t_main *ma, t_menu *me, char const *path)
{
    t_engine *en = malloc(sizeof(t_engine));
    t_teemo *te = init_teemo(te);
    char **content = get_content(path);
    int croi;
    en->pause = 0;
    en->c = 0;
    en->hp = ma->hpmax;
    t_monster *mo = get_monster(mo, content, &en->c);
    init_engine(en);
    te->t_sound = sfMusic_createFromFile("src/music/toxicatk.ogg");
    sfRenderWindow_setMouseCursorVisible(ma->window, sfFalse);
    sfText_setString(en->money, my_put_nbr_base(ma->gold, "0123456789"));
    while (sfRenderWindow_isOpen(ma->window)){
        if(is_dead(mo, ma, en->c) == 1){
            sfRenderWindow_setMouseCursorVisible(ma->window, sfTrue);
            if(ma->level < 10 && ma->l_arg == 0)
                ma->level++;
            saving(0, ma);
            victory(ma, me);
        }
        if (en->pause == 0)
            a_sec_inter(te);
        get_mouse_pos(ma);
        en->c_cursor.x = ma->cursor.x - (50 * en->o_cursor.x);
        en->c_cursor.y = ma->cursor.y - (50 * en->o_cursor.y);
        sfSprite_setPosition(en->s_cursor, en->c_cursor);
        te->dif.y = ma->cursor.y - te->tee_pos.y;
        if (en->pause == 0){
            tee_move(te);
            go_monster(mo, en->c, &en->hp);
            move_bck(en);
        }
        if (te->second > 2.0)
            sfClock_restart(te->clock);
        if (te->miliseconds > 1.0){
            start_time(mo, en->c);
            if (en->pause == 0)
                animate(mo, en->c);
            sfClock_restart(te->s_clock);
        }
        get_clock_time(te);
        en->bk_time = sfClock_getElapsedTime(en->bk_clock);
        en->bk_sec = en->bk_time.microseconds/10000.0;
        engine_event(ma, en, mo, te, me);
        loot(mo, en, ma, en->c);
        if (en->hp <= 0) {
            sfRenderWindow_setMouseCursorVisible(ma->window, sfTrue);
            game_over(ma, me);
        }
        croi = 100 - (en->hp * 100)/ma->hpmax;
        en->r_health.left = croi;
        sfSprite_setTextureRect(en->s_health, en->r_health);
        sfRenderWindow_clear(ma->window, sfBlack);
        draw_engine(ma, en, te);
        draw_monster(mo, ma, en->c);
        sfRenderWindow_drawSprite(ma->window, en->s_health, NULL);
        draw_gui(ma, en);
        if (en->pause == 1){
            sfRenderWindow_drawSprite(ma->window, en->s_pause, NULL);
            sfRenderWindow_drawSprite(ma->window, en->s_quit_pause, NULL);
        }
        sfRenderWindow_drawSprite(ma->window, en->s_cursor, NULL);
        sfRenderWindow_display(ma->window);
    }
}
