#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"menu.h"
#include"fonctions.h"
#include"background.h"
void initialiser_backmenu(background *b)
{
	char nom[100],num[3];
	for(int i=0;i<10;i++)
	{
		strcpy(nom,"image/menu/an");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		b->img[i]=IMG_Load(nom);
	}
	b->pos1.x=0;
	b->pos1.y=0;
	b->pos2.x=0;
	b->pos2.y=0;
	b->pos2.h=1000;
	b->pos2.w=1400;
	b->photo=0;
	b->nbr=10;
}
void initialiser_play(boutton *play)
{
	play->img[0]=IMG_Load("image/menu/play1.png");
	play->img[1]=IMG_Load("image/menu/play2.png");
	play->pos.x=500;
	play->pos.y=190;
	play->pos.h=105;
	play->pos.w=325;
	play->p=0;
}
void initialiser_exit(boutton *exit)
{
	exit->img[0]=IMG_Load("image/menu/exit1.png");
	exit->img[1]=IMG_Load("image/menu/exit2.png");
	exit->pos.x=500;
	exit->pos.y=515;
	exit->p=0;
}
void initialiser_setting(boutton *setting)
{
	setting->img[0]=IMG_Load("image/menu/setting1.png");
	setting->img[1]=IMG_Load("image/menu/setting2.png");
	setting->pos.x=500;
	setting->pos.y=275;
	setting->p=0;
}
void initialiser_tops(boutton *tops)
{
	tops->img[0]=IMG_Load("image/menu/topscore1.png");
	tops->img[1]=IMG_Load("image/menu/topscore2.png");
	tops->pos.x=500;
	tops->pos.y=435;
	tops->p=0;
}
void animer_btnsmenu(int *p,int *e,int *t,int *s,int px,int ex,int tx,int sx)
{
	*p=px;
	*e=ex;
	*t=tx;
	*s=sx;
}
void afficher_btn(SDL_Surface *screen,boutton btn)
{
	SDL_BlitSurface(btn.img[btn.p],NULL,screen,&btn.pos);
}
