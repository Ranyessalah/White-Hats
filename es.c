#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include"es.h"
#include"math.h"
//colision
int collision(SDL_Rect pos1,SDL_Rect pos2)
{
    if(pos1.x + pos1.w > pos2.x && pos1.x < pos2.x + pos2.w && pos1.y + pos1.h 		> pos2.y && pos1.y < pos2.y + pos2.h) 
	{
		return 1;
	}
    return 0;
}
void collision_obstacles(obstacles o,perso p,int c_obstacles[])
{
	int i=0,j=0;
	c_obstacles[0]=-1;
	c_obstacles[1]=-1;
	c_obstacles[2]=-1;
	c_obstacles[3]=-1;
	
	while(c_obstacles[3]==-1 && i<o.nbr)
	{
		if(collision(o.pos[i],p.pos)==1)
		{
			c_obstacles[j]=i;
			j++;
		}
		i++;
	}
}
int collision_enemie(perso p,enmie e[])
{
	int pos=-1,i=0;
	if(p.etat==5)p.pos.w=p.pos.w+40;
	while(pos==-1 && i<2)
	{
		if(collision(e[i].pos,p.pos)==1)
			pos=i;
		i++;
	}
	return pos;
	if(p.etat==5)p.pos.x=p.pos.x+100;
}

int collision_checkpoint(checkpoint ch,perso p)
{
	int pos=-1,i=0;
	while(pos==-1 && i<2)
	{
		if(collision(ch.pos1[i],p.pos)==1)
			pos=i;
		i++;
	}
	return pos;
}
int collision_finish(perso p,finish f)
{
	int test=0;
	if(p.pos.x>=11000)
	{
		test=2;
		if(collision(p.pos,f.pos)==1)
		{
			test=2;
		}
	}
	return test;
}
//animations
void animer_enmie (enmie* e)
{
	(*e).mouvment++;
	if((*e).etat==1)
		(*e).mouvment=0;
	else if((*e).mouvment==4)
	{
		(*e).mouvment=0;
		(*e).pas++;
		if((*e).pas==10)
		{
			(*e).pas=0;
			if((*e).dir==0)(*e).dir=1;
			else (*e).dir=0;
		}
	}
}
void animer_trap(trap *t)
{
	int time;
	time=SDL_GetTicks()/1000;
	if(time%(*t).time==0)
	{
		if((*t).r==0)
		{
			if((*t).etat==0)(*t).etat=1;
			else (*t).etat=0;
			(*t).r=1;
		}
	}
	else
	{
		(*t).r=0;
	}
}
//AFFICHAGE
void afficher_enmie( SDL_Surface * screen,enmie e)
{
	if(e.pos.w!=0 && e.pos.h!=0)
	{
		if(e.dir==0)
			SDL_BlitSurface(e.etat_droite.img,&e.etat_droite.pos[e.etat][e.mouvment],screen,&e.pos);
		else 
			SDL_BlitSurface(e.etat_gauche.img,&e.etat_gauche.pos[e.etat][e.mouvment],screen,&e.pos);
	}
}
void afficher_obstacles(SDL_Surface *screen,obstacles o)
{
	for(int i=0;i<o.nbr_h+o.nbr_v;i++)
	{
		SDL_BlitSurface(o.img_obS[i],NULL,screen,&o.pos[i]);
	}
	for(int i=o.nbr_h+o.nbr_v;i<o.nbr_h+o.nbr_v+o.nbr_a;i++)
	{
		SDL_BlitSurface(o.img_obA[o.p[i-o.nbr_h-o.nbr_v]],NULL,screen,&o.pos[i]);
	}
}
void afficher_trap(SDL_Surface *screen,trap t)
{
	if(t.etat==1)
		SDL_BlitSurface(t.img,NULL,screen,&t.pos);
}
//mouvment
void move_enmie (enmie *e)
{
	if((*e).dir==0)
	{
		(*e).pos.x=(*e).pos.x+10;
		(*e).champs_visuelle.x=(*e).champs_visuelle.x+10;
		
	}
	else 
	{
		(*e).pos.x=(*e).pos.x-10;
		(*e).champs_visuelle.x=(*e).champs_visuelle.x-10;
	}
}
void movobstacle(obstacles *o)
{
	for(int i=0;i<(*o).nbr_h;i++)
	{
		if((*o).etat[i]==1)
		{
			if((*o).dir[i]==0)
			{
				(*o).pos[i].x=(*o).pos[i].x+5;
			}
			else
			{
				(*o).pos[i].x=(*o).pos[i].x-5;
			}
			
			if((*o).pos[i].x>=(*o).pos_max[i]) (*o).dir[i]=1;
			else if((*o).pos[i].x<=(*o).pos_min[i])(*o).dir[i]=0;
		}
	}
	for(int i=(*o).nbr_h;i<(*o).nbr_h+(*o).nbr_v;i++)
	{
		if((*o).etat[i]==1)
		{
			if((*o).dir[i]==2)
			{
				(*o).pos[i].y=(*o).pos[i].y+5;
			}
			else
			{
				(*o).pos[i].y=(*o).pos[i].y-5;
			}
			
			if((*o).pos[i].y>=(*o).pos_max[i]) (*o).dir[i]=3;
			else if((*o).pos[i].y<=(*o).pos_min[i])(*o).dir[i]=2;
		}
	}
}
void initBonus(bonus*b)
{
	b->img[0] = IMG_Load("1ES.png");
	b->img[1] = IMG_Load("2ES.png");
	b->img[2] = IMG_Load("3ES.png");
	b->img[3] = IMG_Load("4ES.png");
	b->p=0;
	for(int i=0 ; i<10 ; i++)
	{
		b->etat[i]=1;
		b->pos[i].x= i*500 + 700;
		if(i%2==0)
			b->pos[i].y=200;
		else
			b->pos[i].y=300;
		b->pos[i].h=150;
		b->pos[i].w=150;
	}
}
void afficherBonus(SDL_Surface *screen , bonus b)
{
	for(int i=0 ; i<10 ;i++)
	{
		
		if(b.etat[i]==1)
			SDL_BlitSurface(b.img[b.p] , NULL , screen , &b.pos[i]);
	}
}
void annimerBonus(bonus*b)
{
	b->p++;
	if(b->p==4)
	{
		b->p=0;
	}
}

void deplacerr_bonus(bonus *e,int direction,int v)
{
	for(int i=0;i<10;i++)
	{
		if(direction==0)
		{
			(*e).pos[i].x=(*e).pos[i].x-v;
		}
		else if(direction==1)
		{
			(*e).pos[i].x=(*e).pos[i].x+v;
		}
	}
}
int collision_trigo(SDL_Rect pos_obstacle,SDL_Rect pos_perso)
{

	int X_perso,Y_perso,X_obstacle,Y_obstacle;
	double R1,R2,D1,D2;


	X_perso=pos_perso.x+pos_perso.w/2;
	Y_perso=pos_perso.y+pos_perso.h/2;


	X_obstacle=pos_obstacle.x+pos_obstacle.w/2;
	Y_obstacle=pos_obstacle.y+pos_obstacle.h/2;


	R1=sqrt(   (pos_perso.w/2)*(pos_perso.w/2) +(pos_perso.h/2)*(pos_perso.h/2) );
	R2=sqrt(   (pos_obstacle.w/2)*(pos_obstacle.w/2) +(pos_obstacle.h/2)*(pos_obstacle.h/2)   );

	D1=sqrt( (X_perso-X_obstacle)*(X_perso-X_obstacle) + (Y_perso-Y_obstacle)*(Y_perso-Y_obstacle)  );

	D2=R1+R2;
	
	if(D1<D2)
		return 0;
	else
	{
		return 1;
	}
}

