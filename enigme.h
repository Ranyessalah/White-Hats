#ifndef ENIGME_H
#define ENIGME_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"time.h"
typedef struct
{
	SDL_Surface *img[12];
	SDL_Rect pos;
	int p;
}backgroundE;
typedef struct
{
	char ch[200];
	SDL_Surface *txt;
	SDL_Rect pos;
}textE;
typedef struct
{
	
	char ch[200];
	SDL_Surface *txt[2];
	SDL_Rect pos;
	int p;
}text_enigme;
typedef struct
{
	SDL_Color color[2];
	TTF_Font *police[2];
	textE question;
	text_enigme reponse1;
	text_enigme reponse2;
	text_enigme reponse3;
	int r_exact ;
	Mix_Chunk *song[2];
	backgroundE back;
}enigme;
typedef struct
{
	SDL_Surface *img ;
	int r_exact ;
	Mix_Chunk *song[2];
	backgroundE back;
	SDL_Rect pos;
}enigmeimg;
void init_enigme (enigme *e);
void afficher_text(SDL_Surface *screen , textE t);
void afficher_text_enigme(SDL_Surface *screen , text_enigme t);
void afficher_enigme(SDL_Surface *screen , enigme e);
void genererEnigme(enigme* e);
void init_backEnigme(backgroundE *back);
void initialiser_backenigme(backgroundE *back);
void animer_backenigme(backgroundE *back);

//ENIGME IMAGE
void init_enigmeimg (enigmeimg *e);
void afficher_enigmeimg(SDL_Surface *screen , enigmeimg e);
void genererEnigmeimg(enigmeimg* e);



#endif
