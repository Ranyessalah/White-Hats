#ifndef ES_H
#define ES_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
typedef struct
{
	SDL_Surface *img[4];
	SDL_Rect pos[10];
	int etat[10];
	int p;
}bonus;
int collision(SDL_Rect pos1,SDL_Rect pos2);
int collision_enemie(perso p,enmie e[]);
int collision_checkpoint(checkpoint ch,perso p);
void animer_enmie (enmie* e);
void afficher_enmie( SDL_Surface * screen,enmie e);
void move_enmie (enmie *e);
void collision_obstacles(obstacles o,perso p,int c_obstacles[]);
void afficher_obstacles(SDL_Surface *screen,obstacles o);
void movobstacle(obstacles *o);
void animer_trap(trap *t);
void afficher_trap(SDL_Surface *screen,trap t);
int collision_finish(perso p,finish f);
void initBonus(bonus*b);
void afficherBonus(SDL_Surface *screen , bonus b);
void annimerBonus(bonus*b);
void deplacerr_ennemie(enmie *e,int direction,int v);
void moveIA(enmie *e);
int collision_trigo(SDL_Rect pos_obstacle,SDL_Rect pos_perso);
void deplacerr_bonus(bonus *e,int direction,int v);
int collision_trigo(SDL_Rect pos_obstacle,SDL_Rect pos_perso);
#endif
