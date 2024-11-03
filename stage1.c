#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include"stage1.h"
#include"es.h"
void initialiser_backSTAGE1(background *b)
{
	char nom[50],num[4];
	(*b).nbr=1;
	for(int i=0;i<(*b).nbr;i++)
	{
		strcpy(nom,"image/background/stage1/animation_background/bg");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*b).img[i]=IMG_Load(nom);
	}
	(*b).pos1.x=0;
	(*b).pos1.y=0;
	(*b).pos2.x=0;
	(*b).pos1.h=1200;
	(*b).pos1.w=14956;
	(*b).pos2.y=200;
	(*b).pos2.h=1000;
	(*b).pos2.w=1400;
	(*b).photo=0;
}
void initenmieSTAGE1(enmie e[])
{
	
	e[0].etat_droite.img=IMG_Load("image/es/enmie/alien walk droite(1).png");
	e[1].etat_droite.img=IMG_Load("image/es/enmie/alien walk droite(1).png");
	int x,w=e[0].etat_droite.img->w/4,h=e[0].etat_droite.img->h,y=0;
	for(int k=0;k<3;k++)
	{
		y=0;
		for(int i=0;i<3;i++)
		{
			x=0;
			for(int j=0;j<7;j++)
			{
				e[k].etat_droite.pos[i][j].x=x;
				e[k].etat_droite.pos[i][j].y=y;
				e[k].etat_droite.pos[i][j].h=h;
				e[k].etat_droite.pos[i][j].w=w;
				x=x+w;
				if((i==1 && j==1) || (i==2 && j==2)) break;
			}
			y=y+h;
		}
	}
	e[0].etat_gauche.img=IMG_Load("image/es/enmie/alien walk gauche(1).png");
	e[1].etat_gauche.img=IMG_Load("image/es/enmie/alien walk gauche(1).png");
	for(int k=0;k<3;k++)
	{
		
		y=0;
		for(int i=0;i<3;i++)
		{
			x=e[0].etat_droite.img->w;
			for(int j=0;j<7;j++)
			{
				x=x-w;
				e[k].etat_gauche.pos[i][j].x=x;
				e[k].etat_gauche.pos[i][j].y=y;
				e[k].etat_gauche.pos[i][j].h=h;
				e[k].etat_gauche.pos[i][j].w=w;
				
				if((i==1 && j==1) || (i==2 && j==2)) break;
			}
			y=y+h;
		}
	}
	e[0].pos.x=1538;
	e[0].pos.y=710;
	e[0].pos.w=100;
	e[0].pos.h=226;
	e[1].pos.x=7160;
	e[1].pos.y=420;
	e[1].pos.w=80;
	e[1].pos.h=226;
	for(int i=0;i<2;i++)
	{
		e[i].mouvment=0;
		e[i].pas=0;
		e[i].dir=0;
		e[i].etat=0;
	}
	e[0].champs_visuelle.x=e[0].pos.x-500;
	e[0].champs_visuelle.y=e[0].pos.y;
	e[0].champs_visuelle.w=1000+e[0].pos.w;
	e[0].champs_visuelle.h=e[0].pos.h+1000;
}
void initialiser_obstaclesSTAGE1(obstacles* o)
{
	(*o).img_obS[0]=IMG_Load("image/es/obstacledynamique/16.png");
	(*o).pos[16].x=0;
	(*o).pos[16].y=760;
	(*o).pos[16].h=240;
	(*o).pos[16].w=3915;
	//
	(*o).pos[1].x=4969;
	(*o).pos[1].y=760;
	(*o).pos[1].h=240;
	(*o).pos[1].w=1337;
	//
	(*o).pos[2].x=7727;
	(*o).pos[2].y=760;
	(*o).pos[2].h=240;
	(*o).pos[2].w=1821;
	//
	(*o).pos[3].x=11749;
	(*o).pos[3].y=760;
	(*o).pos[3].h=240;
	(*o).pos[3].w=3207;
	//f1: w=211 / h=144 / x=777 / y=555
	(*o).pos[4].x=777;
	(*o).pos[4].y=340;
	(*o).pos[4].h=144;
	(*o).pos[4].w=211;
	//f2: w=334 / h=161 / x=1185 / y=408
	(*o).pos[5].x=1185;
	(*o).pos[5].y=200;
	(*o).pos[5].h=161;
	(*o).pos[5].w=334;
	//f3 : w=226 / h=162 / x=1763 / y=519
	(*o).pos[6].x=1763;
	(*o).pos[6].y=300;
	(*o).pos[6].h=162;
	(*o).pos[6].w=226;
	//f4: w=310 / h=75 / x=2623 / y=451
	(*o).pos[7].x=2623;
	(*o).pos[7].y=250;
	(*o).pos[7].h=75;
	(*o).pos[7].w=310;
	//f5: w=217 / h=151 / x=3103 / y=569
	(*o).pos[8].x=3103;
	(*o).pos[8].y=369;
	(*o).pos[8].h=151;
	(*o).pos[8].w=217;
	//f6: w=211 / h=144 / x=6449 / y=681
	(*o).pos[9].x=6449;
	(*o).pos[9].y=470;
	(*o).pos[9].h=144;
	(*o).pos[9].w=211;
	//f7: w=334 / h=161 / x=6847 / y=439
	(*o).pos[10].x=6847;
	(*o).pos[10].y=218;
	(*o).pos[10].h=161;
	(*o).pos[10].w=334;
	//f8: w=226 / h=162 / x=7318 / y=708
	(*o).pos[11].x=7318;
	(*o).pos[11].y=508-11;
	(*o).pos[11].h=162;
	(*o).pos[11].w=226;
	//f10: w=310 / h=75 / x=8657 / y=439
	(*o).pos[12].x=8657;
	(*o).pos[12].y=239;
	(*o).pos[12].h=75;
	(*o).pos[12].w=310;
	//f11: w=448 / h=359 / x=9728 / y=841
	(*o).pos[13].x=9728;
	(*o).pos[13].y=641;
	(*o).pos[13].h=359;
	(*o).pos[13].w=448;
	//f12: w=435 / h=591 / x=10392 / y=609
	(*o).pos[14].x=10392;
	(*o).pos[14].y=409;
	(*o).pos[14].h=591;
	(*o).pos[14].w=435;
	//f13: w=435 / h=120 / x=11044 / y=1080
	(*o).pos[15].x=11044;
	(*o).pos[15].y=880;
	(*o).pos[15].h=120;
	(*o).pos[15].w=435;
	//x=3915 hatta tosal x=4684   f9: w=285 / h=90 /y=960 / x=(3915 -> 4684)
	(*o).pos[0].x=3915;
	(*o).pos[0].y=760;
	(*o).pos[0].h=90;
	(*o).pos[0].w=285;
	//
	(*o).pos[17].x=12350;
	(*o).pos[17].y=581;
	(*o).pos[17].h=178;
	(*o).pos[17].w=150;
	(*o).pos[18].x=13025;
	(*o).pos[18].y=557;
	(*o).pos[18].h=225;
	(*o).pos[18].w=141;
	(*o).pos_min[0]=3915;
	(*o).pos_max[0]=4684;
	(*o).nbr=19;
	(*o).nbr_h=1;
	(*o).nbr_v=0;
	(*o).nbr_a=0;
	(*o).dir[0]=0;
	(*o).etat[0]=1;
	(*o).pos[0].x=1520;
	(*o).pos[0].y=554;
	(*o).pos[0].h=419;
	(*o).pos[0].w=200;	

	(*o).pos[1].x=0;
	(*o).pos[1].y=900;
	(*o).pos[1].h=120;
	(*o).pos[1].w=2684;
	//
	(*o).pos[2].x=2683;
	(*o).pos[2].y=851-200;
	(*o).pos[2].h=341;
	(*o).pos[2].w=1337;
	//
	(*o).pos[3].x=4020;
	(*o).pos[3].y=900;
	(*o).pos[3].h=130;
	(*o).pos[3].w=1340;
	//f1: w=211 / h=144 / x=777 / y=555
	(*o).pos[4].x=5500;
	(*o).pos[4].y=921-200;
	(*o).pos[4].h=100;
	(*o).pos[4].w=180;
	//f2: w=334 / h=161 / x=1185 / y=408
	(*o).pos[5].x=5743;
	(*o).pos[5].y=885;
	(*o).pos[5].h=131;
	(*o).pos[5].w=4511;
	//f3 : w=226 / h=162 / x=1763 / y=519
	(*o).pos[6].x=10300;
	(*o).pos[6].y=884-200;
	(*o).pos[6].h=80;
	(*o).pos[6].w=345;
	//f4: w=310 / h=75 / x=2623 / y=451
	(*o).pos[7].x=2623;
	(*o).pos[7].y=250-200;
	(*o).pos[7].h=100;
	(*o).pos[7].w=1300;
	//f5: w=217 / h=151 / x=3103 / y=569
	(*o).nbr=8;
}
void initialiser_trapsSTAGE1(trap t[])
{
	for(int i=0;i<2;i++)
	{
		t[i].img=IMG_Load("image/es/traps/stage1/laser.png");
		t[i].etat=0;
		t[i].time=3;
		t[i].r=0;
		t[i].pos.w=300;
		t[i].pos.h=899;
	}
	t[0].pos.x=6565;
	t[0].pos.y=825-200;
	t[1].pos.x=6565;
	t[1].pos.y=825-200;
	
}
void initialiser_door(finish *f)
{
	char nom[50],num[4];
	(*f).nbr=11;
	for(int i=0;i<(*f).nbr;i++)
	{
		strcpy(nom,"image/dore/");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*f).img[i]=IMG_Load(nom);
	}
	(*f).pos.x=14650;
	(*f).pos.y=333;
	(*f).pos.h=525;
	(*f).pos.w=533;
	(*f).photo=0;
}
void afficher_door(SDL_Surface *screen,finish f)
{

	SDL_BlitSurface(f.img[f.photo],NULL,screen,&f.pos);
}
void animer_door(finish *f,int d)
{
	if(d==0)
	{
		if(f->photo!=0)
			f->photo--;
	}
	else
	{
		if(f->photo!=10)
			f->photo++;
	}
}
void initialiser_chekpointSTAGE1(checkpoint *ch)
{
	(*ch).img[1]=IMG_Load("image/checkpoint/allumee.png");
	(*ch).img[0]=IMG_Load("image/checkpoint/eteinte.png");
	(*ch).pos1[0].w=107;
	(*ch).pos1[0].h=141;
	(*ch).pos1[0].x=2284;
	(*ch).pos1[0].y=620;
	(*ch).pos2[0].w=107;
	(*ch).pos2[0].h=141;
	(*ch).pos2[0].x=0;
	(*ch).pos2[0].y=0;
	//
	(*ch).pos1[1].w=107;
	(*ch).pos1[1].h=141;
	(*ch).pos1[1].x=5667;
	(*ch).pos1[1].y=620;
	(*ch).pos2[1].w=107;
	(*ch).pos2[1].h=141;
	(*ch).pos2[1].x=0;
	(*ch).pos2[1].y=0;
	//
	(*ch).pos1[2].w=107;
	(*ch).pos1[2].h=141;
	(*ch).pos1[2].x=9357;
	(*ch).pos1[2].y=620;
	(*ch).pos2[2].w=107;
	(*ch).pos2[2].h=141;
	(*ch).pos2[2].x=0;
	(*ch).pos2[2].y=0;
	(*ch).etat=-1;
	
	for(int i=0;i<3;i++)
	{
		(*ch).p[i]=0;
	}	
}

