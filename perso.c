#include"fonctions.h"
#include"perso.h"
void initPerso(perso *p)
{
	(*p).etat_droite.img[0]=IMG_Load("image/perso/walking right 1.png");
	(*p).etat_droite.img[1]=IMG_Load("image/perso/walking right 2.png");
	(*p).etat_droite.img[2]=IMG_Load("image/perso/walking right 3.png");
	int x,y=0,h=(*p).etat_droite.img[1]->h/4,w=(*p).etat_droite.img[1]->w/6;
	(*p).etat=0;
	(*p).dir=0;
	(*p).mouvment=0;
	(*p).movsaut=0;
	(*p).pos.w=105;
	(*p).pos.h=206;
	(*p).saut=0;
	(*p).haut=0;
	(*p).vie=3;
	(*p).h=1;
	(*p).d=1;
	(*p).b=1;
	(*p).g=1;
	for(int i=0;i<7;i++)
	{
		x=0;
		//reanisyaliser(&w,i);
		for(int j=0;j<6;j++)
		{
			(*p).etat_droite.pos[i][j].x=x;
			(*p).etat_droite.pos[i][j].y=y;
			(*p).etat_droite.pos[i][j].h=h;
			(*p).etat_droite.pos[i][j].w=w;
			x=x+w;
		}
		y=y+h;
	}
	(*p).etat_gauche.img[0]=IMG_Load("image/perso/walking left 1.png");
	(*p).etat_gauche.img[1]=IMG_Load("image/perso/walking left 2.png");
	(*p).etat_gauche.img[2]=IMG_Load("image/perso/walking left 3.png");
	y=0;
	for(int i=0;i<7;i++)
	{
		x=888;
		//reanisyaliser(&w,i);
		for(int j=0;j<6;j++)
		{
			x=x-w;
			(*p).etat_gauche.pos[i][j].x=x;
			(*p).etat_gauche.pos[i][j].y=y;
			(*p).etat_gauche.pos[i][j].h=h;
			(*p).etat_gauche.pos[i][j].w=w;
			
		}
		y=y+h;
	}
	(*p).pos.x=100;
	(*p).pos.y=560;
	(*p).p=1;
}
void reanisyaliser(int *w,int i)
{
	if(i==0) *w=105;
	else if(i==1) *w=136;
	else if(i==2) *w=149;
	else if(i==3) *w=145;
	else if(i==4) *w=109;
	else if(i==5) *w=145;
}
void afficherPerso(SDL_Surface * screen,perso p)
{
	if (p.dir==0 && p.saut==1)
	{
		SDL_BlitSurface(p.etat_droite.img[p.p],&p.etat_droite.pos[3][p.mouvment],screen,&p.pos);
	}
	else if (p.dir==1 && p.saut==1)
	{
		SDL_BlitSurface(p.etat_gauche.img[p.p],&p.etat_gauche.pos[3][p.mouvment],screen,&p.pos);
	}
	else if(p.dir==0)
	{
		SDL_BlitSurface(p.etat_droite.img[p.p],&p.etat_droite.pos[p.etat][p.mouvment],screen,&p.pos);
	}
	else
	{
		SDL_BlitSurface(p.etat_gauche.img[p.p],&p.etat_gauche.pos[p.etat][p.mouvment],screen,&p.pos);
	}
}
void animerPerso (perso* p)
{
	(*p).mouvment++;
	if((p->mouvment==2 && p->etat==0) || (p->mouvment==2 && p->etat==0) ||(p->mouvment==3 && p->etat==2)  )
	{
		(*p).mouvment=0;
	}
	else if(p->etat==4 || (p->etat==5 && p->mouvment==5))
	{
		(*p).mouvment=0;
		if((*p).etat==5)(*p).etat=0;
	}
}
void movePerso (perso *p)
{
	if((*p).dir==0) 
	{
		if((*p).d!=0)
			(*p).pos.x=(*p).pos.x+p->vitesse;
		
	}		
	else if((*p).dir==1)
	{
			if((*p).g!=0)
				(*p).pos.x=(*p).pos.x-p->vitesse;
	}
}
void saut (perso* p)
{
	if ((*p).movsaut>1 && (*p).movsaut<(*p).maxsaut && (*p).haut==1) 
	{
		(*p).mouvment=1;
	}
	else if((*p).movsaut>(*p).maxsaut || (*p).haut==0)
	{
		(*p).haut=0;
		(*p).mouvment=3;
	}
	(*p).movsaut++;
	if((*p).haut==0 && (*p).b==0)
	{ 
		(*p).saut=0;
		(*p).movsaut=0;
	}
}
void mouv_saut (perso* p)
{
	
	if((*p).mouvment<3)
	{
		if((*p).h==1)
			
			(*p).pos.y=(*p).pos.y-22;
	}
	else if((*p).b==1)
	{
		(*p).pos.y=(*p).pos.y+22;
	}
}
void veriph_dir(obstacles o,perso *p,int c_obstacles[])
{
	(*p).h=1;
	(*p).d=1;
	(*p).b=1;
	(*p).g=1;
	for(int i=0;i<4;i++)
	{
		
		if(c_obstacles[i]!=-1)
		{
			
			if (o.pos[c_obstacles[i]].y+o.pos[c_obstacles[i]].h-22<=(*p).pos.y)
			{
				(*p).h=0;
			}
			else if ((*p).pos.y+(*p).pos.h<=o.pos[c_obstacles[i]].y+50)
			{
				(*p).b=0;
			}
			else if((*p).dir==0 && (*p).pos.x<o.pos[c_obstacles[i]].x)
			{
				(*p).d=0;
			}
			else if((*p).dir==1 && (*p).pos.x>o.pos[c_obstacles[i]].x)
			{
				(*p).g=0;
			}
		}
	}
	if((*p).pos.y<=0)
	{
		(*p).h=0;
	}
}
void deplacer_perso(perso *p,int dir,int v)
{
	if(dir==0) (*p).pos.x=(*p).pos.x+v;
	else if (dir==1)(*p).pos.x=(*p).pos.x-v;
	else if(dir==2) (*p).pos.y=(*p).pos.y+v;
	else if (dir==3)(*p).pos.y=(*p).pos.y-v;
	
}
void init_imageVies1(vie_player *v)
{
	char nom[50],num[4];
	for(int i=0;i<4;i++)
	{
		strcpy(nom,"image/backgrounds/vies/");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*v).img[i]=IMG_Load(nom);
	}
	(*v).pos.x=50;
	(*v).pos.y=50;
	(*v).nbr=3;
}
void init_imageVies2(vie_player *v)
{
	char nom[50],num[4];
	for(int i=0;i<4;i++)
	{
		strcpy(nom,"image/backgrounds/vies/");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*v).img[i]=IMG_Load(nom);
	}
	(*v).pos.x=50+700;
	(*v).pos.y=258;
	(*v).nbr=3;
}
void initialiser_shot(shot *sh)
{
	(*sh).img[1]=IMG_Load("image/es/sho0t/shoot.png");
	(*sh).img[0]=IMG_Load("image/es/sho0t/gunblast2.png");
	for(int i=0;i<20;i++)
	{
		(*sh).pos[i].h=50;
		(*sh).pos[i].w=50;
	}
	(*sh).nbr=0;
	(*sh).r=0;
}
void ajout_shot(shot *sh,SDL_Rect pos,int dir,int dif)
{
	if ((*sh).nbr!=20)
	{
		(*sh).nbr++;
		if(dir==0)
		{
			(*sh).pos[(*sh).nbr-1].x=pos.x+pos.w;
		}
		else if(dir==1)
		{
			(*sh).pos[(*sh).nbr-1].x=pos.x;	
		}
		(*sh).pos[(*sh).nbr-1].h=50;
		(*sh).dir[(*sh).nbr-1]=dir;
		(*sh).pos[(*sh).nbr-1].y=pos.y+dif;	
	}
}
void move_shot(shot *sh,SDL_Rect pos1)
{
	SDL_Rect pos;
	for(int i=0;i<(*sh).nbr;i++)
	{
		if((*sh).dir[i]==0)
		{
			(*sh).pos[i].x=(*sh).pos[i].x+30;
		}
		else
		{
			(*sh).pos[i].x=(*sh).pos[i].x-30;
		}
	}
	if((*sh).nbr!=0)
	{
		if((*sh).dir[0]==1  &&   (*sh).pos[0].x<=pos1.x-1205)
		{
			for(int i =0;i<(*sh).nbr-1;i++)
			{
				(*sh).pos[i]=(*sh).pos[i+1];
				(*sh).dir[i]=(*sh).dir[i+1];
			}
			(*sh).nbr--;
			(*sh).pos[(*sh).nbr].h=0;
			
		}
		else if ((*sh).dir[0]==0  &&   (*sh).pos[0].x>=pos1.x+1205)
		{
			for(int i =0;i<(*sh).nbr;i++)
			{
				(*sh).pos[i]=(*sh).pos[i+1];
				(*sh).dir[i]=(*sh).dir[i+1];
			}
			(*sh).nbr--;
			(*sh).pos[(*sh).nbr].h=0;
		}
	}
}
void afficher_shot(SDL_Surface *screen,shot sh)
{
	for(int i=0;i<sh.nbr;i++)
	{
		if(sh.pos[i].h!=0)
			SDL_BlitSurface(sh.img[sh.dir[i]],NULL,screen,&sh.pos[i]);
	}
}
void animer_checkpoint(checkpoint *ch)
{
	switch((*ch).etat)
	{
		case 0:
			(*ch).p[0]=1;
			break;
		case 1:
			(*ch).p[1]=1;
			break;
		case 2:
			(*ch).p[2]=1;
			break;
	}
}
void afficher_chekpoint(SDL_Surface *screen,checkpoint ch)
{
	for(int i=0;i<3;i++)
	{
		SDL_BlitSurface(ch.img[ch.p[i]],&ch.pos2[i],screen,&ch.pos1[i]);
	}
}
void retoure_debut(perso *p,background *back,checkpoint *ch,enmie e[],obstacles *o,trap t[],finish *f)
{
	for(int i=0;i<o->nbr;i++)
	{
		o->pos[i].x=o->pos[i].x+back->pos2.x;
		o->pos[i].y=o->pos[i].y-200+back->pos2.y;
	}
	for(int i=0;i<o->nbr_h;i++)
	{
		o->pos_max[i]=o->pos_max[i]+back->pos2.x;
		o->pos_min[i]=o->pos_min[i]+back->pos2.x;
	}
	for(int i=0;i<2;i++)
	{
		e[i].pos.x=e[i].pos.x+back->pos2.x;
		e[i].pos.y=e[i].pos.y-200+back->pos2.y;
	}
	for(int i=0;i<2;i++)
	{
		t[i].pos.x=t[i].pos.x+back->pos2.x;
		t[i].pos.y=t[i].pos.y-200+back->pos2.y;
	}
	for(int i=0;i<3;i++)
	{
		ch->pos1[i].x=ch->pos1[i].x+back->pos2.x;
		ch->pos1[i].y=ch->pos1[i].y-200+back->pos2.y;
		ch->pos2[i].w=107;
		ch->pos2[i].h=141;
	}
	f->pos.x=f->pos.x+back->pos2.x;
	f->pos.y=f->pos.y-200+back->pos2.y;
	back->pos2.x=0;
	back->pos2.y=200;
	p->pos.x=100;
	p->pos.y=500;
	
	
}
