#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include"background.h"
void scrolling(background *b, int direction,int v)
{
	switch(direction)
	{
	case 0:
		b->pos2.x=b->pos2.x+v;
		break;
	case 1:
		b->pos2.x=b->pos2.x-v;
		break;
	case 2:
		b->pos2.y=b->pos2.y-v;
		break;
	case 3:
		b->pos2.y=b->pos2.y+v;
		break;	
	}
}
void afficher_back(SDL_Surface *screen,background b)
{
	SDL_BlitSurface(b.img[b.photo],&b.pos2,screen,&b.pos1);
}
void animerBack(background *b)
{
	(*b).photo++;
	if ((*b).photo==(*b).nbr) (*b).photo=0;
}
/*void afficher_minicris(SDL_Surface *screen,collections *c)
{
	char ch[20],num[2];
	strcpy(ch,"x");
	sprintf(num,"%d",(*c).nbr);
	
	strcat(ch,num);
	strcat(ch,"/3");
	if((*c).nbr!=(*c).nbr_a)
	{
		printf("e\n");
		SDL_FreeSurface((*c).txt);
		if((*c).nbr<3)
			(*c).txt= TTF_RenderText_Blended((*c).police,ch, (*c).color[0]);
		else 
			(*c).txt= TTF_RenderText_Blended((*c).police,ch, (*c).color[1]);
		(*c).nbr_a=(*c).nbr;
	}
        SDL_BlitSurface((*c).txt, NULL, screen, &(*c).pos_mini[1]);
	SDL_BlitSurface((*c).img_mini, NULL, screen, &(*c).pos_mini[0]);
}*/
void initialiser_back(background *b)
{
	char nom[50],num[4];
	for(int i=0;i<12;i++)
	{
		strcpy(nom,"image/backgrounds/animation_background/bg");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*b).img[i]=IMG_Load(nom);
	}
	(*b).pos1.x=0;
	(*b).pos1.y=0;
	(*b).pos2.x=0;
	(*b).pos2.y=200;
	(*b).pos2.h=1000;
	(*b).pos2.w=700;
	(*b).photo=0;
}
void init_scoreTexte(score_info *s)
{
	
	(*s).police=TTF_OpenFont("police/Ubuntu-Bold.ttf", 22);
	(*s).color.r = 225;
	(*s).color.g = 225;
	(*s).color.b = 225;
	(*s).pos.x=1245;
	(*s).pos.y=35;
	(*s).score_a=0;
	(*s).txt= TTF_RenderText_Blended((*s).police,"score:0", (*s).color);
}
void afficher_scoreTexte(SDL_Surface *screen,score_info *s)
{
	char ch1[20];
	
	if((*s).score!=(*s).score_a)
	{
		SDL_FreeSurface((*s).txt);
		strcpy(ch1,"SCORE : ");
		sprintf((*s).ch,"%d",(*s).score);
		strcat(ch1,(*s).ch);
		(*s).txt= TTF_RenderText_Blended((*s).police,ch1, (*s).color);
	}
        SDL_BlitSurface((*s).txt, NULL, screen, &(*s).pos);
}
void init_scoreTexte_2(score_info *s)
{
	
	(*s).police=TTF_OpenFont("police/Ubuntu-Bold.ttf", 30);
	(*s).color.r = 225;
	(*s).color.g = 225;
	(*s).color.b = 225;
	(*s).pos.x=50+700;
	(*s).pos.y=208;
}
void afficher_scoreTexte_2(SDL_Surface *screen,score_info s)
{
	char ch1[20];
	strcpy(ch1,"SCORE : ");
	sprintf(s.ch,"%d",s.score);
	strcat(ch1,s.ch);
	s.txt= TTF_RenderText_Blended(s.police,ch1, s.color);
        SDL_BlitSurface(s.txt, NULL, screen, &s.pos);
}



void init_imageVies(vie_player *v)
{
	char nom[50],num[4];
	for(int i=0;i<4;i++)
	{
		strcpy(nom,"image/background/vies/");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*v).img[i]=IMG_Load(nom);
	}
	(*v).pos.x=900;
	(*v).pos.y=100;
	(*v).nbr=3;
}
void afficher_imageVies(SDL_Surface *screen,vie_player v)
{
	SDL_BlitSurface(v.img[v.nbr],NULL,screen,&v.pos);
}
//scrolling
void scrolling_ennemie(enmie *e,int dir,int v)
{
	if(dir==0)
	{
		(*e).pos.x=(*e).pos.x-v;
		(*e).champs_visuelle.x=(*e).champs_visuelle.x-v;
	}
	else if(dir==1)
	{
		(*e).pos.x=(*e).pos.x+v;
		(*e).champs_visuelle.x=(*e).champs_visuelle.x+v;
	}
	else if(dir==3) 
	{
		(*e).pos.y=(*e).pos.y-v;
		(*e).champs_visuelle.y=(*e).champs_visuelle.y-v;
	}
	else
	{
		(*e).pos.y=(*e).pos.y+v;
		(*e).champs_visuelle.y=(*e).champs_visuelle.y+v;
	}
}
void scrolling_obstacles(obstacles *o,int dir,int v)
{
	for(int i=0;i<(*o).nbr;i++)
	{
		if(dir==0) 
			(*o).pos[i].x=(*o).pos[i].x-v;
		else if(dir==1)
			(*o).pos[i].x=(*o).pos[i].x+v;
		else if(dir==3)
			(*o).pos[i].y=(*o).pos[i].y-v;
		else
			(*o).pos[i].y=(*o).pos[i].y+v;
	}
	for(int i=0;i<(*o).nbr_h;i++)
	{
		if(dir==0)
		{
			(*o).pos_max[i]=(*o).pos_max[i]-v;
			(*o).pos_min[i]=(*o).pos_min[i]-v;
		}
		else if(dir==1)
		{
			(*o).pos_max[i]=(*o).pos_max[i]+v;
			(*o).pos_min[i]=(*o).pos_min[i]+v;
		}
	}
	for(int i=(*o).nbr_h;i<(*o).nbr_h+(*o).nbr_v;i++)
	{
		if(dir==2)
		{
			(*o).pos_max[i]=(*o).pos_max[i]+v;
			(*o).pos_min[i]=(*o).pos_min[i]+v;
		}
		else if(dir==3)
		{
			(*o).pos_max[i]=(*o).pos_max[i]-v;
			(*o).pos_min[i]=(*o).pos_min[i]-v;
		}
	}
}
void scrolling_shot(shot *sh,int dir,int v)
{
	for(int i=0;i<3;i++)
	{
		if(dir==0)
		{
			(*sh).pos[i].x=(*sh).pos[i].x-v;
		}
		else if(dir==1)
		{
			(*sh).pos[i].x=(*sh).pos[i].x+v;
		}
		else if(dir==2)
		{
			(*sh).pos[i].y=(*sh).pos[i].y+v;
		}
		else if(dir==3)
		{
			(*sh).pos[i].y=(*sh).pos[i].y-v;
		}
	}
}
void scrolling_trap(trap *t,int dir,int v,background back)
{
	
	if(dir==0)
	{
		(*t).pos.x=(*t).pos.x-v;
	}
	else if(dir==1)
	{
			
		(*t).pos.x=(*t).pos.x+v;
	}
	else if(dir==2)
	{
		(*t).pos.y=(*t).pos.y+v;
	}
	else if(dir==3)
	{
		(*t).pos.y=(*t).pos.y-v;
	}
}
void scrolling_chekpoint(checkpoint *ch,int dir,int v,background back)
{
	for(int i=0;i<2;i++)
	{
		if(dir==0)
		{
			if((*ch).pos1[i].x>=back.pos1.x)
			{
				(*ch).pos1[i].x=(*ch).pos1[i].x-v;
			}
			else
			{
				(*ch).pos2[i].x=(*ch).pos2[i].x+v;
			}
		}
		else if(dir==1)
		{
			if((*ch).pos2[i].x>=0)
			{
				(*ch).pos2[i].x=(*ch).pos2[i].x-v;
			}
			else
			{
				(*ch).pos1[i].x=(*ch).pos1[i].x+v;
			}
		}
		else if(dir==2)
		{
			(*ch).pos1[i].y=(*ch).pos1[i].y+v;
		}
		else if(dir==3)
		{
			(*ch).pos1[i].y=(*ch).pos1[i].y-v;
		}
	}
}
void scrolling_door(finish *f,int dir,int v)
{
	if(dir==0)
	{
		(*f).pos.x=(*f).pos.x-v;
	}
	else if(dir==1)
	{
		(*f).pos.x=(*f).pos.x+v;
	}
	else if(dir==2)
	{
		(*f).pos.y=(*f).pos.y+v;
	}
	else if(dir==3)
	{
		(*f).pos.y=(*f).pos.y-v;
	}
}
