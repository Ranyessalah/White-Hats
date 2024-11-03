#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"
#include"menu.h"
#include"fonctions.h"
#include "selectniv.h"
#include "quit.h"
#include "setting.h"
#include "topscore.h"
void initialiser_backtopp(backs *backtop)
{
	backtop->img=IMG_Load("image/topscore/top score without.png");
	if(backtop->img==NULL) printf("%s",SDL_GetError());
	backtop->pos.x=0;
	backtop->pos.y=0;
}
void initialiser_bt_exit_top(boutton *exit_top)
{
	exit_top->img[0]=IMG_Load("image/topscore/EXIT non selectionnee.png");
	exit_top->img[1]=IMG_Load("image/topscore/exit selectionne.png");
	exit_top->pos.x=590;
	exit_top->pos.y=874;
	exit_top->pos.w=294;
	exit_top->pos.h=95;
	exit_top->p=0;
}


void verif_topscore(player p[])
{
	int test=1,i=0;
	int n=0;
	FILE *f;
	TTF_Font *police;
	SDL_Surface *txt[3];
	SDL_Color color;
	TTF_Init();
	SDL_Rect pos[3];
	player aux;
	char num[3][10],nom[3][50];
	f=fopen("player.txt","r");
while(fscanf(f,"%s\t\t%s\t\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\n",p[n].player_name,p[n].mdp,&p[n].top_score,&p[n].top_scoreS1,&p[n].top_scoreS2,&p[n].top_scoreS3,&p[n].top_scoreS4,&p[n].nbr_stage,&p[n].nbr_perso)!=EOF)
	{
		
		n++;
	}
	
	while(test==1)
	{
		test=0;
		for(int i=1;i<n;i++)
		{
			if(p[i].top_score>p[i-1].top_score)
			{
				aux=p[i];
				p[i]=p[i-1];
				p[i-1]=aux;
				
				test=1;
			}
		}	
	}

	fclose(f);
}
void afficher_topscore(player p[])
{
	
}
