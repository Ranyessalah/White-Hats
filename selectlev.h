#ifndef SELECTNIV_H
#define SELECTNIV_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"
#include"fonctions.h"
void initialiser_backselct_lev(background *backlvl);
void initialiser_bt_letsgo1(boutton *letsgo1);
void initialiser_bt_letsgo2(boutton *letsgo2);
void initialiser_bt_letsgo3(boutton *letsgo3);
void initialiser_bt_letsgo4(boutton *letsgo4);
void initialiser_bt_solo1(boutton *solo1);
void initialiser_bt_duo1(boutton *duo1);
void initialiser_lock1(boutton *lock1);
void initialiser_lock2(boutton *lock2);
void initialiser_lock3(boutton *lock3);
void initialiser_btn_skin(boutton *btn_skin);
void animer_btns_selectlev(int *solo,int *duo,int solox,int duox);
#endif
