#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include "setting.h"
void initialiser_backsett(background *backsett)
{
	backsett->img[0]=IMG_Load("image/setting/new_sett/bg_SETTING.png");
	backsett->pos1.x=0;
	backsett->pos1.y=0;
	backsett->pos2.x=0;
	backsett->pos2.y=0;
	backsett->pos2.h=1000;
	backsett->pos2.w=1400;
	backsett->photo=0;
}
void initialiser_bt_done_set(boutton *done_set)
{
	done_set->img[0]=IMG_Load("image/setting/new_sett/DONE1.png");
	done_set->img[1]=IMG_Load("image/setting/new_sett/DONE2.png");
	done_set->pos.x=574;
	done_set->pos.y=768;
	done_set->pos.w=325;
	done_set->pos.h=105;
	done_set->p=0;
}
void initialiser_bt_full_on(boutton *full_on)
{
	full_on->img[0]=IMG_Load("image/setting/new_sett/full_off.png");
	full_on->img[1]=IMG_Load("image/setting/new_sett/full_on.png");
	full_on->pos.x=833;
	full_on->pos.y=600;
	full_on->pos.w=66;
	full_on->pos.h=60;
	full_on->p=0;
}
void initialiser_bt_plus_set(boutton *plus_set)
{
	plus_set->img[0]=IMG_Load("image/setting/new_sett/plus1.png");
	plus_set->img[1]=IMG_Load("image/setting/new_sett/plus2.png");
	plus_set->pos.x=810;
	plus_set->pos.y=180;
	plus_set->pos.w=61;
	plus_set->pos.h=71;
	plus_set->p=0;
}
void initialiser_bt_moin_set(boutton *moin_set)
{
	moin_set->img[0]=IMG_Load("image/setting/moins.png");
	moin_set->img[1]=IMG_Load("image/setting/moins.png");
	moin_set->pos.x=740;
	moin_set->pos.y=180;
	moin_set->pos.w=61;
	moin_set->pos.h=71;
	moin_set->p=0;
}
void initialiser_bt_return_set(boutton *return_set)
{
	return_set->img[0]=IMG_Load("image/setting/new_sett/return_set1.png");
	return_set->img[1]=IMG_Load("image/setting/new_sett/return_set2.png");
	return_set->pos.x=700;
	return_set->pos.y=600;
	return_set->pos.w=73;
	return_set->pos.h=71;
	return_set->p=0;
}
void initialiser_bt_option_set(boutton *option_set)
{
	option_set->img[0]=IMG_Load("image/setting/new_sett/option1.png");
	option_set->img[1]=IMG_Load("image/setting/new_sett/option2.png");
	option_set->pos.x=430;
	option_set->pos.y=323;
	option_set->pos.w=73;
	option_set->pos.h=71;
	option_set->p=0;
}
void initialiser_bt_son_set(boutton *son_set)
{
	son_set->img[0]=IMG_Load("image/setting/new_sett/son_icone.png");
	son_set->img[1]=IMG_Load("image/setting/new_sett/mute_icone.png");
	son_set->pos.x=890;
	son_set->pos.y=165;
	son_set->pos.w=73;
	son_set->pos.h=71;
	son_set->p=0;
}
void initialiser_bt_return_opset(boutton *return_opset)
{
	return_opset->img[0]=IMG_Load("image/setting/opption/return_opset1.png");
	return_opset->img[1]=IMG_Load("image/setting/opption/return_opset2.png");
	return_opset->pos.x=1305;
	return_opset->pos.y=15;
	return_opset->pos.w=73;
	return_opset->pos.h=71;
	return_opset->p=0;
}
void animer_btns_setting(int *done_s,int *full_s,int *plus_s,int *moin_s,int *return_s,int *option_s,int *son_s,int done_sx,int full_sx,int plus_sx,int moin_sx,int return_sx,int option_sx,int son_sx)
{
	*done_s=done_sx;
	*full_s=full_sx;
	*plus_s=plus_sx;
	*moin_s=moin_sx;
	*return_s=return_sx;
	*option_s=option_sx;
	*son_s=son_sx;
}
void initialiser_input(input_joueur *input)
{
	(*input).up=SDLK_UP;
	(*input).down=SDLK_DOWN;
	(*input).left=SDLK_LEFT;
	(*input).right=SDLK_RIGHT;
	(*input).attack=SDLK_l;
	(*input).choix=0;
}
