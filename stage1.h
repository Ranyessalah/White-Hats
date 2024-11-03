#ifndef STAGE1_H
#define STAGE1_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
void initialiser_backSTAGE1(background *b);
void initialiser_door(finish *f);
void afficher_door(SDL_Surface *screen,finish f);
void animer_door(finish *f,int d);
void scrolling_door(finish *f,int dir,int v);
void initenmieSTAGE1(enmie e[]);
void initialiser_obstaclesSTAGE1(obstacles* o);
void initialiser_trapsSTAGE1(trap t[]);
void initialiser_door(finish *f);
void afficher_door(SDL_Surface *screen,finish f);
void animer_door(finish *f,int d);
void initialiser_chekpointSTAGE1(checkpoint *ch);
#endif
