#ifndef MENU_H
#define MENU_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"


void initialiser_backmenu(background *back);
void initialiser_play(boutton *play);
void initialiser_exit(boutton *exit);
void initialiser_setting(boutton *setting);
void initialiser_tops(boutton *tops);
void afficher_btn(SDL_Surface *screen,boutton btn);
void animer_btnsmenu(int *p,int *e,int *t,int *s,int px,int ex,int tx,int sx);
#endif
