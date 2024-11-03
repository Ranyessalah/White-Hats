#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
	SDL_Surface *img[2];
	SDL_Rect pos;
	int p;
}boutton;
typedef struct
{
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface *img[12];
	int photo;
	int nbr;
}background;
typedef struct
{
	SDL_Rect pos;
	TTF_Font *police;
	SDL_Surface *txt;
	SDL_Color color;
	int score;
	int score_a;
	char temps[20];
	char ch[20];
	char player_name[20];
}score_info;
typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img[4];
	int nbr;
}vie_player;
typedef struct
{
	SDL_Rect pos;
	TTF_Font *police;

	SDL_Surface *txt;
	SDL_Color color;
}text;
typedef struct
{
	char player_name[20];
	char mdp[20];
	int top_score;
	int top_scoreS1;
	int top_scoreS2;
	int top_scoreS3;
	int top_scoreS4;
	int nbr_perso;
	int nbr_stage;
}player;
typedef struct
{
	SDL_Surface *img[20];
	int nbr;
	int photo;
	SDL_Rect pos;
}finish;
typedef struct
{
	SDL_Surface *img;    
	SDL_Rect pos[3][8];
	
}image_enmie;
typedef struct
{
	image_enmie etat_droite;
	image_enmie etat_gauche;
	SDL_Rect pos;
	SDL_Rect champs_visuelle;
	int dir;
	int etat;
	int mouvment;
	int pas;
}enmie;
typedef struct
{
	SDL_Surface *img[20];
	SDL_Rect pos[7][6];
	
}image_perso;
typedef struct
{
	image_perso etat_droite;
	image_perso etat_gauche;
	SDL_Rect pos;
	int dir;
	int etat;
	int haut;
	int mouvment;
	int movsaut;
	int saut;
	int vitesse;
	int maxsaut;
	int vie;
	int score;
	int h;
	int b;
	int d;
	int g;
	int p;
}perso;
typedef struct
{
	SDL_Surface *img_obS[5];
	SDL_Surface *img_obA[5];
	SDL_Rect pos[20];
	SDL_Rect pos2[10];
	int pos_max[10];
	int pos_min[10];
	int dir[10];
	int etat[10];
	int p[5];
	int tomber[5];
	int nbr_h;
	int nbr_v;
	int nbr_a;
	int nbr;
	int nbr_pA;
	int r[5];
	
}obstacles;
typedef struct
{
	int up;
	int down;
	int left;
	int right;
	int attack;
	int choix;
}input_joueur;
typedef struct
{
	SDL_Surface *img[2];
	SDL_Rect pos[20];
	int dir[20];
	int nbr;
	int r;
}shot;
typedef struct
{
	SDL_Surface *img;
	SDL_Rect pos;
	int time;
	int etat;
	int r;
	
}trap;
typedef struct
{
	SDL_Surface *img[2];
	SDL_Rect pos1[3];
	SDL_Rect pos2[3];
	int etat;
	int p[3];
}checkpoint;
#endif
