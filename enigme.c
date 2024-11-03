#include"enigme.h"
void init_enigme (enigme *e)
{
	int num , choix;
	choix = rand() % 3 ;
	FILE *fichier = fopen("enigme.txt" , "r") ;
	if(fichier !=NULL)
	{
		num=-1;
		do
		{
			fgets(e->question.ch  , 49 , fichier) ;
			fgets(e->reponse1.ch , 21 ,fichier);
			fgets(e->reponse2.ch ,21,  fichier);
			fgets(e->reponse3.ch ,21,  fichier );
			fscanf(fichier , "%d\n" ,&e->r_exact);
			num++;
		}
		while(num != choix);

/*****COULEUR*****/

		e->color[0].r=128; e->color[0].g=0; e->color[0].b=0;
		e->color[1].r=255; e->color[1].g=0; e->color[1].b=0;
/*****police*****/

		e->police[0] = TTF_OpenFont("police/Ubuntu-Bold.ttf" , 25) ;
		e->police[1] = TTF_OpenFont("police/Merriweather-Black.ttf" , 40) ;

/****SDL_Surface*****/

		e->question.txt = TTF_RenderText_Blended (e->police[0] , e->question.ch , e->color[0]) ;

		e->reponse1.txt[0] = TTF_RenderText_Blended(e->police[0] , e->reponse1.ch , e->color[0]) ;
		e->reponse1.txt[1] = TTF_RenderText_Blended(e->police[1] , e->reponse1.ch , e->color[1]) ;

		e->reponse2.txt[0] = TTF_RenderText_Blended(e->police[0] , e->reponse2.ch , e->color[0]) ;
		e->reponse2.txt[1] = TTF_RenderText_Blended(e->police[1] , e->reponse2.ch , e->color[1]) ;

		e->reponse3.txt[0] = TTF_RenderText_Blended(e->police[0] , e->reponse3.ch , e->color[0]) ;
		e->reponse3.txt[1] = TTF_RenderText_Blended(e->police[1] , e->reponse3.ch , e->color[1]) ;
/*****POSITION*****/
		e->question.pos.x=430;e->question.pos.y=300;
		e->reponse1.pos.x=103;e->reponse1.pos.y=750;e->reponse1.pos.w=e->reponse1.txt[0]->w;e->reponse1.pos.h=e->reponse1.txt[0]->h;
		e->reponse2.pos.x=550;e->reponse2.pos.y=750;e->reponse2.pos.w=e->reponse2.txt[0]->w;e->reponse2.pos.h=e->reponse2.txt[0]->h;
		e->reponse3.pos.x=1020;e->reponse3.pos.y=750;e->reponse3.pos.w=e->reponse3.txt[0]->w;e->reponse3.pos.h=e->reponse3.txt[0]->h;
/*****LA SELECTION*****/
		e->reponse1.p=0;
		e->reponse2.p=0;
		e->reponse3.p=0;
		e->song[1] = Mix_LoadWAV("song/negative_beeps-6008.wav");
		e->song[0] = Mix_LoadWAV("song/success-1-6297.wav");

/****background****/
		init_backEnigme(&e->back);
	}
}
void afficher_text(SDL_Surface *screen,textE txt)
{
        SDL_BlitSurface(txt.txt, NULL , screen, &txt.pos);
}
void afficher_text_enigme(SDL_Surface *screen,text_enigme txt)
{
        SDL_BlitSurface(txt.txt[txt.p], NULL , screen, &txt.pos);
}
void afficher_enigme(SDL_Surface *screen , enigme e)
{
	SDL_BlitSurface(e.back.img[e.back.p] , NULL , screen , &e.back.pos);
	afficher_text(screen,e.question);
	afficher_text_enigme(screen,e.reponse1);
	afficher_text_enigme(screen,e.reponse2);
	afficher_text_enigme(screen,e.reponse3);
}
void genererEnigme(enigme* e)
{
	int num , choix;
	choix = rand() % 3 ;
	FILE *fichier = fopen("enigme.txt" , "r") ;
	
	if(fichier !=NULL)
	{
		num=-1;
		do
		{
			fgets(e->question.ch  , 49 , fichier) ;
			fgets(e->reponse1.ch , 21 ,fichier);
			fgets(e->reponse2.ch ,21,  fichier);
			fgets(e->reponse3.ch ,21,  fichier );
			fscanf(fichier , "%d\n" ,&e->r_exact);
			num++;
		}
		while(num != choix);
/*****LIBERATION*****/
		
		SDL_FreeSurface(e->question.txt);
		SDL_FreeSurface(e->reponse1.txt[0]);
		SDL_FreeSurface(e->reponse1.txt[1]);
		SDL_FreeSurface(e->reponse2.txt[0]);
		SDL_FreeSurface(e->reponse2.txt[1]);
		SDL_FreeSurface(e->reponse3.txt[0]);
		SDL_FreeSurface(e->reponse3.txt[1]);
/****SDL_Surface*****/

		e->question.txt = TTF_RenderText_Blended (e->police[0] , e->question.ch , e->color[0]) ;

		e->reponse1.txt[0] = TTF_RenderText_Blended(e->police[0] , e->reponse1.ch , e->color[0]) ;
		e->reponse1.txt[1] = TTF_RenderText_Blended(e->police[1] , e->reponse1.ch , e->color[1]) ;

		e->reponse2.txt[0] = TTF_RenderText_Blended(e->police[0] , e->reponse2.ch , e->color[0]) ;
		e->reponse2.txt[1] = TTF_RenderText_Blended(e->police[1] , e->reponse2.ch , e->color[1]) ;

		e->reponse3.txt[0] = TTF_RenderText_Blended(e->police[0] , e->reponse3.ch , e->color[0]) ;
		e->reponse3.txt[1] = TTF_RenderText_Blended(e->police[1] , e->reponse3.ch , e->color[1]) ;
	}
}
void animer_backenigme(backgroundE *back)
{
	(*back).p++;
	if ((*back).p==4) (*back).p=0;
}
void init_backEnigme(backgroundE *back)
{
	
	back->img[0]=IMG_Load("image/enigme/an1.png");
	back->img[1]=IMG_Load("image/enigme/an2.png");
	back->img[2]=IMG_Load("image/enigme/an3.png");
	back->img[3]=IMG_Load("image/enigme/an3.png");
	back->p=0;
	back->pos.x=0;
	back->pos.y=0;
	back->pos.h=back->img[0]->h;
	back->pos.w=back->img[0]->w;
}
void init_enigmeimg (enigmeimg *e)
{
	int num , choix;
	choix = rand() % 3 ;
	FILE *fichier = fopen("enigmeimg.txt" , "r") ;
	char nom[80];
	if(fichier !=NULL)
	{
		num=-1;
		do
		{
			fgets(nom  , 25 , fichier) ;
			fscanf(fichier , "%d\n" ,&e->r_exact);
			num++;
		}
		while(num != choix);
		e->song[1] = Mix_LoadWAV("song/negative_beeps-6008.wav");
		e->song[0] = Mix_LoadWAV("song/success-1-6297.wav");
		e->img=IMG_Load(nom);
		if(e->img == NULL) printf("%s\n" , SDL_GetError());
		e->pos.x=0;e->pos.y=0;
		printf("%d\n" , e->r_exact);
		printf("%s\n" ,nom);
	}
}
void genererEnigmeimg(enigmeimg* e)
{
	int num , choix;
	choix = rand() % 4 ;
	FILE *fichier = fopen("enigmeimg.txt" , "r") ;
	char nom[80];
	if(fichier !=NULL)
	{
		num=-1;
		do
		{
			fgets(nom  , 25 , fichier) ;
			fscanf(fichier , "%d\n" ,&e->r_exact);
			num++;
		}
		while(num != choix);
		printf("%d\n" ,e->r_exact);
		SDL_FreeSurface(e->img);
		e->img=IMG_Load(nom);
		printf("%d\n" , e->r_exact);
		printf("%s\n" ,nom);
		fclose(fichier);
	}
}
void afficher_enigmeimg(SDL_Surface *screen , enigmeimg e)
{
	SDL_BlitSurface(e.img , NULL , screen , &e.pos);
}
