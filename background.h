#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
void afficher_back(SDL_Surface *screen,background b);
void scrolling(background *b, int direction,int v);
void animerBack(background *b);
void liberer_image(background *imge);
//void afficher_minicris(SDL_Surface *screen,collections *c);
void afficher_scoreTexte(SDL_Surface *screen,score_info *s);
void init_scoreTexte(score_info *s);
void init_imageVies(vie_player *v);
void afficher_imageVies(SDL_Surface *screen,vie_player v);
void init_scoreTexte_2(score_info *s);
void scrolling_obstacles(obstacles *o,int dir,int v);
void scrolling_ennemie(enmie *e,int dir,int v);
void scrolling_shot(shot *sh,int dir,int v);
void scrolling_trap(trap *t,int dir,int v,background back);
void scrolling_chekpoint(checkpoint *ch,int dir,int v,background back);
void scrolling_door(finish *f,int dir,int v);
#endif
