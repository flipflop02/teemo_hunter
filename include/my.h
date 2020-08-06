/*
** EPITECH PROJECT, 2018
** my h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/Export.h>
#include <SFML/System/Time.h>

#define USAGE "\tTeemo Hunter :\n\
Usage : './my_hunter'\n\
Goal : Hunt down the target with your mouse to gain money, upgrades \
and progess through the levels\n\n\
Controls :\nCursor -> Aim\n\
Mouse left click -> Shoot\n\n\
Additional commands :\n\
./my_hunter -h : help command\n\
./my_hunter -L <filepath> : allow to play on a custom stage\n"

typedef struct t_base{
    sfVideoMode mode;
    sfRenderWindow *window;
    int wtype;
    sfVector2i mousepos;
    sfVector2f cursor;
    int hpmax;
    int gold;
    int level;
    int damage;
    int hplevel;
    int dmglevel;
    int l_arg;
    char *filepath;
    sfEvent event;
}t_main;

typedef struct t_shop{
    sfSprite *b_sprite;
    sfTexture *b_texture;
    sfVector2f b_scale;
    sfMusic *theme;
    sfMusic *music;
    sfText *gold;
    
    sfSprite *cry_sprite;
    sfTexture *cry_texture;
    sfVector2f cry_scale;

    sfSprite *dmg_sprite;
    sfTexture *dmg_texture;
    sfVector2f dmg_scale;
    sfVector2f dmg_pos;
    sfVector2f dmg_size;

    sfSprite *hp_sprite;
    sfTexture *hp_texture;
    sfVector2f hp_scale;
    sfVector2f hp_pos;
    sfVector2f hp_size;
    
    sfSprite *q_sprite;
    sfTexture *q_texture;
    sfVector2f q_scale;
    sfVector2f q_size;
    sfVector2f q_pos;

    sfFont *s_font;
    sfText *price_dmg;
    sfText *price_hp;
    sfVector2f hppos;
    sfVector2f dpos;
}t_shop;

typedef struct t_monster{
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *s_hp;
    sfTexture *t_hp;
    sfIntRect r_hp;
    sfVector2f p_hp;
    sfVector2f sc_hp;
    int croi;
    int hp;
    int hpmax;
    int speed;
    int damage;
    int time;
    int is_alive;
    int frame;
    int width;
    int goldrop;
    float origin;
    sfVector2f size;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
}t_monster;

typedef struct t_engine{
    sfTexture *t_quit_pause;
    sfSprite *s_quit_pause;
    sfVector2f pos_quit_pause;
    sfVector2f scale_quit_pause;
    sfVector2f size_quit_pause;
    int pause;
    sfSprite *s_pause;
    sfTexture *t_pause;
    sfSprite* s_health;
    sfTexture* t_health;
    sfIntRect r_health;
    sfSprite *m_sprite;
    sfTexture *m_texture;
    sfVector2f m_pos;
    sfVector2f m_scale;
    sfSprite *s_sprite;
    sfTexture *s_texture;
    sfVector2f s_scale;
    sfVector2f p_health;
    sfSprite *s_cursor;
    sfTexture *t_cursor;
    sfVector2f c_cursor;
    sfVector2f o_cursor;
    sfText *money;
    sfFont *money_f;
    sfVector2f mo_pos;
    sfIntRect s_rec;
    float bk_sec;
    sfTime bk_time;
    sfClock *bk_clock;
    int c;
    int hp;
}t_engine;

typedef struct t_teemo{
    sfSprite *tee_sprite;
    sfTexture *tee_texture;
    sfVector2f tee_scale;
    sfVector2f tee_pos;
    sfVector2f tee_or;
    sfVector2f dif;
    sfIntRect tee_rec;
    sfClock *clock;
    sfClock *s_clock;
    sfTime s_time;
    float miliseconds;
    sfTime time;
    sfClock *a_clock;
    sfTime a_time;
    float a_sec;
    float second;
    sfMusic *t_sound;
}t_teemo;

typedef struct t_menu{
    sfSprite *b_sprite;
    sfTexture *b_texture;
    sfSprite *s_sprite;
    sfVector2f s_pos;
    sfTexture *s_texture;
    sfVector2f scale;
    sfSprite *s_play;
    sfTexture *t_play;
    sfVector2f p_play;
    sfVector2f c_play;
    sfSprite *s_exit;
    sfTexture *t_exit;
    sfVector2f p_exit;
    sfMusic *music;
}t_menu;

t_engine *draw_engine(t_main *ma, t_engine *en, t_teemo *te);
int check_hitbox(t_monster *mo, int c, t_main *ma);
int animate_teemo(float second, t_teemo *te);
t_engine *draw_gui(t_main *ma, t_engine *en);
t_teemo *init_teemo(t_teemo *te);
t_engine *init_engine(t_engine *en);
char *my_strdup(char *str);
int my_putstr(char const *str);
int victory(t_main *ma, t_menu *me);
int game_over(t_main *ma, t_menu *me);
int price_toxic(t_main *ma, t_menu *me, t_shop *sh, int price);
int shop(t_main *ma, t_menu *me);
int saving(int fd, t_main *ma);
int load_file(int fd, t_main *ma);
char *my_strcat(char *dest, char const *src);
int len_nbr(int nb);
char *my_put_nbr_base(int nb, char *base);
char *my_revstr(char *str);
float my_fgetnbr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char *str);
t_menu *init_menu(t_menu *me);
int my_strlen(char const *str);
char **my_str_to_wordtoken(char *str, char *cmp);
int get_mouse_pos(t_main *ma);
int title_screen(t_main *ma, t_menu *me);
int engine(t_main *ma, t_menu *me, char const *path);
int check_coord(sfVector2f cursor, sfVector2f pos, sfVector2f size);
#endif
