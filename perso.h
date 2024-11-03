#ifndef PERSO_H
#define PERSO_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include"background.h"
void initPerso(perso *p);
void initialiser_shot(shot *sh);
void reanisyaliser(int *w,int i);
void afficherPerso(SDL_Surface * screen,perso p);
void animerPerso (perso* p);
void movePerso (perso *p);
void saut (perso* p);
void deplacer_perso(perso *p,int dir,int v);
void mouv_saut (perso* p);
void veriph_dir(obstacles o,perso *p,int c_obstacles[]);
void afficher_imageVies(SDL_Surface *screen,vie_player v);
void ajout_shot(shot *sh,SDL_Rect pos,int dir,int dif);
void move_shot(shot *sh,SDL_Rect pos1);
void afficher_shot(SDL_Surface *screen,shot sh);
void animer_checkpoint(checkpoint *ch);
void afficher_chekpoint(SDL_Surface *screen,checkpoint ch);
void retoure_debut(perso *p,background *back,checkpoint *ch,enmie e[],obstacles *o,trap t[],finish *f);
#endif
