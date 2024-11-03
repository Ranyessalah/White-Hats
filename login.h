#ifndef LOGIN_H
#define LOGIN_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include"background.h"
void initialiser_back_login(background *back_login);
void initialiser_backsigneup(background *back_signeup);
void initialiser_bt_done_log(boutton *done_log);
void initialiser_zone_usr(boutton *zone_usr);
void initialiser_zone_psw(boutton *zone_psw);
void initialiser_btn_sign(boutton *sign);
void initialiser_eye(boutton *eye);
void initialiser_txt(text txt[]);
void initialiser_deconnect(boutton *deconnect);
void animer_btns_login(int *yes_q,int *no_q,int yes_qx,int no_qx);
void afficher_txt(SDL_Surface *screen,text txt,char log[]);
int verifier_signup(char mdp[],char log[]);
void signe_up(char mdp[],char log[]);
player verifier_log(char mdp[],char log[]);
#endif
