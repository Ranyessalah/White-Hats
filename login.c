#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "login.h"
void initialiser_back_login(background *back_login)
{
	back_login->img[0]=IMG_Load("image/login/back.png");
	back_login->pos1.x=0;
	back_login->pos1.y=0;
	back_login->pos2.x=0;
	back_login->pos2.y=0;
	back_login->pos2.h=1000;
	back_login->pos2.w=1400;
	back_login->photo=0;
	back_login->nbr=1;
}
void initialiser_backsigneup(background *back_signeup)
{
	back_signeup->img[0]=IMG_Load("image/signe up/backsn.png");
	back_signeup->pos1.x=0;
	back_signeup->pos1.y=0;
	back_signeup->pos2.x=0;
	back_signeup->pos2.y=0;
	back_signeup->pos2.h=1000;
	back_signeup->pos2.w=1400;
	back_signeup->photo=0;
	back_signeup->nbr=1;
}
void initialiser_bt_done_log(boutton *done_log)
{
	done_log->img[0]=IMG_Load("image/login/DONE_.png");
	done_log->img[1]=IMG_Load("image/login/DONE selectionnee.png");
	done_log->pos.x=753;
	done_log->pos.y=741;
	done_log->pos.w=316;
	done_log->pos.h=102;
	done_log->p=0;
}
void initialiser_zone_usr(boutton *zone_usr)
{
	zone_usr->img[1]=IMG_Load("image/login/rectangle selectionnee.png");
	zone_usr->img[0]=IMG_Load("image/login/rectangle_.png");
	zone_usr->pos.x=700;
	zone_usr->pos.y=464;
	zone_usr->pos.w=478;
	zone_usr->pos.h=82;
	zone_usr->p=1;
}
void initialiser_zone_psw(boutton *zone_psw)
{
	zone_psw->img[0]=IMG_Load("image/login/rectangle_.png");
	zone_psw->img[1]=IMG_Load("image/login/rectangle selectionnee.png");
	zone_psw->pos.x=700;
	zone_psw->pos.y=585;
	zone_psw->pos.w=478;
	zone_psw->pos.h=82;
	zone_psw->p=0;
}
void initialiser_btn_sign(boutton *sign)
{
	sign->img[0]=IMG_Load("image/login/Sign Up.png");
	sign->img[1]=IMG_Load("image/login/Sign Up selectionnee.png");
	sign->pos.x=620;
	sign->pos.y=723;
	sign->pos.w=138;
	sign->pos.h=34;
	sign->p=0;
}
void initialiser_eye(boutton *eye)
{
	eye->img[0]=IMG_Load("image/login/eye off.png");
	eye->img[1]=IMG_Load("image/login/eye on.png");
	eye->pos.x=1009;
	eye->pos.y=623;
	eye->pos.w=51;
	eye->pos.h=37;
	eye->p=0;
}
void initialiser_txt(text txt[])
{
	for(int i=0;i<2;i++)
	{
		txt[i].color.r = 0;
		txt[i].color.g = 0;
		txt[i].color.b = 0;
		txt[i].police = TTF_OpenFont("police/Ubuntu-Bold.ttf", 30);
	}
	txt[1].pos.x=780;
	txt[1].pos.y=600;
	txt[0].pos.x=780;
	txt[0].pos.y=480;
	txt[0].txt= TTF_RenderText_Blended(txt[0].police,"", txt[0].color);
	txt[1].txt= TTF_RenderText_Blended(txt[1].police,"", txt[1].color);
}
void initialiser_deconnect(boutton *deconnect)
{
	deconnect->img[0]=IMG_Load("image/menu/deconnect.png");
	deconnect->pos.x=9;
	deconnect->pos.y=910;
	deconnect->pos.h=86;
	deconnect->pos.w=86;
	deconnect->p=0;
}
void animer_btns_login(int *yes_q,int *no_q,int yes_qx,int no_qx)
{
	*yes_q=yes_qx;
	*no_q=no_qx;
}
void afficher_txt(SDL_Surface *screen,text txt,char log[])
{
	//txt.txt= TTF_RenderText_Blended(txt.police, log, txt.color);
        SDL_BlitSurface(txt.txt, NULL, screen, &txt.pos);
}
int verifier_signup(char mdp[],char log[])
{
	int test=1;
	if (strlen(mdp)<2) test=0;
	player p;
	FILE *f;
	f=fopen("player.txt","r");
	if(f!=NULL)
	{
	while (fscanf(f,"%s\t%s\t%d\n",p.player_name,p.mdp,&p.top_score)!=EOF && test==1)
	{
	if(strcmp(p.player_name,log)==0)
	test=0;
	}
	}
	printf("%d",test);
	fclose(f);
	return test;
}
void signe_up(char mdp[],char log[])
{
	FILE *f;
	f=fopen("player.txt","a");
	if(f!=NULL)
	{
	fprintf(f,"%s\t\t%s\t\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\n",log,mdp,0,0,0,0,0,1,1);
	}
	fclose(f);
}
player verifier_log(char mdp[],char log[])
{
	FILE *f;
	int test=2;
	player p;
	f=fopen("player.txt","r");
	if(f!=NULL)
	{
		while(test==2 && fscanf(f,"%s\t\t%s\t\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\n",p.player_name,p.mdp,&p.top_score,&p.top_scoreS1,&p.top_scoreS2,&p.top_scoreS3,&p.top_scoreS4,&p.nbr_stage,&p.nbr_perso)!=EOF )
		{
			if(strcmp(p.player_name,log)==0 && strcmp(p.mdp,mdp)==0)
				test=1;
		}
	}
	
	fclose(f);
	if(test==2)
		p.mdp[0]='\0';
	return p;
}
