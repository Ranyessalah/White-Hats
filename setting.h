#ifndef SETTING_H
#define SETTING_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
void initialiser_backsett(background *backsett);
void initialiser_bt_done_set(boutton *done_set);
void initialiser_bt_full_on(boutton *full_on);
void initialiser_bt_plus_set(boutton *plus_set);
void initialiser_bt_moin_set(boutton *moin_set);
void initialiser_bt_return_set(boutton *return_set);
void initialiser_bt_option_set(boutton *option_set);
void initialiser_bt_son_set(boutton *son_set);
void initialiser_bt_return_opset(boutton *return_opset);
void animer_btns_setting(int *done_s,int *full_s,int *plus_s,int *moin_s,int *return_s,int *option_s,int *son_s,int done_sx,int full_sx,int plus_sx,int moin_sx,int return_sx,int option_sx,int son_sx);
void initialiser_input(input_joueur *input);
#endif
