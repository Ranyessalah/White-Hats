#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include"selectlev.h"
void initialiser_backselct_lev(background *backlvl)
{
	backlvl->img[0]=IMG_Load("image/play_/play_selct/sous menu3.png");
	backlvl->pos1.x=0;
	backlvl->pos1.y=0;
	backlvl->pos2.x=0;
	backlvl->pos2.y=0;
	backlvl->pos2.h=1000;
	backlvl->pos2.w=1400;
	backlvl->photo=0;
	backlvl->nbr=1;
}
void initialiser_bt_letsgo1(boutton *letsgo1)
{
	letsgo1->img[0]=IMG_Load("image/play_/play_selct/anas1.png");
	letsgo1->img[1]=IMG_Load("image/play_/play_selct/anas2.png");
	letsgo1->pos.x=929;
	letsgo1->pos.y=84;
	letsgo1->pos.w=325;
	letsgo1->pos.h=105;
	letsgo1->p=0;
}
void initialiser_bt_letsgo2(boutton *letsgo2)
{
	letsgo2->img[0]=IMG_Load("image/play_/play_selct/rany1.png");
	letsgo2->img[1]=IMG_Load("image/play_/play_selct/rany2.png");
	letsgo2->pos.x=760;
	letsgo2->pos.y=500;
	letsgo2->pos.w=letsgo2->img[0]->w;
	letsgo2->pos.h=letsgo2->img[0]->h;
	letsgo2->p=0;
}
void initialiser_bt_letsgo3(boutton *letsgo3)
{
	letsgo3->img[0]=IMG_Load("image/play_/play_selct/farouk1.png");
	letsgo3->img[1]=IMG_Load("image/play_/play_selct/farouk1.png");
	letsgo3->pos.x=435;
	letsgo3->pos.y=500;
	letsgo3->pos.w=325;
	letsgo3->pos.h=105;
	letsgo3->p=0;
}
void initialiser_bt_letsgo4(boutton *letsgo4)
{
	letsgo4->img[0]=IMG_Load("image/play_/play_selct/anas1.png");
	letsgo4->img[1]=IMG_Load("image/play_/play_selct/anas2.png");
	letsgo4->pos.x=100;
	letsgo4->pos.y=500;
	letsgo4->pos.w=325;
	letsgo4->pos.h=105;
	letsgo4->p=0;
}
void initialiser_bt_solo1(boutton *solo1)
{
	solo1->img[0]=IMG_Load("image/play_/play_selct/solo1.png");
	solo1->img[1]=IMG_Load("image/play_/play_selct/solo2.png");
	solo1->pos.x=930;
	solo1->pos.y=84;
	solo1->pos.w=162;
	solo1->pos.h=105;
	solo1->p=0;
}

void initialiser_bt_duo1(boutton *duo1)
{
	duo1->img[0]=IMG_Load("image/play_/play_selct/duo1.png");
	duo1->img[1]=IMG_Load("image/play_/play_selct/duo2.png");
	duo1->pos.x=1092;
	duo1->pos.y=84;
	duo1->pos.w=162;
	duo1->pos.h=105; 
	duo1->p=0;
}
void initialiser_lock1(boutton *lock1)
{
	lock1->img[0]=IMG_Load("image/play_/play_selct/lock1.png");
	lock1->pos.x=1025;
	lock1->pos.y=326;
	lock1->pos.w=133;
	lock1->pos.h=133; 
	lock1->p=0;
}
void initialiser_lock2(boutton *lock2)
{
	lock2->img[0]=IMG_Load("image/play_/play_selct/lock2.png");
	lock2->pos.x=1025;
	lock2->pos.y=579;
	lock2->pos.w=133;
	lock2->pos.h=133; 
	lock2->p=0;
}
void initialiser_lock3(boutton *lock3)
{
	lock3->img[0]=IMG_Load("image/play_/play_selct/lock3.png");
	lock3->pos.x=1025;
	lock3->pos.y=832;
	lock3->pos.w=133;
	lock3->pos.h=133; 
	lock3->p=0;
}
void initialiser_btn_skin(boutton *btn_skin)
{
	btn_skin->img[0]=IMG_Load("image/play_/perso_select/skin off.png");
	btn_skin->img[1]=IMG_Load("image/play_/perso_select/skin on.png");
	btn_skin->pos.x=1275;
	btn_skin->pos.y=15;
	btn_skin->pos.w=94;
	btn_skin->pos.h=97;
	btn_skin->p=0;
}
void animer_btns_selectlev(int *solo,int *duo,int solox,int duox)
{
	*solo=solox;
	*duo=duox;
}

