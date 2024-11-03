#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include"menu.h"
#include"background.h"
#include "setting.h"
#include "login.h"
#include"selectlev.h"
#include"stage1.h"
#include"es.h"
#include"perso.h"
#include"enigme.h"
#include<time.h>
int main()
{
	srand(time(NULL));
	TTF_Init();
	int etat_enigme=0;
	bonus b;
	//***** DECLARATIONS DES VARIABLE *****//
	char num[2];
	int boocle=1,etat_menu=0,full=0,select=0,volum=10,sing_up=0,etat=1,lv1,stage=0,c_obstacles[4],c_enmie=-1,c_checkpoint,r_enigme=0,c_finish;
	enigme e;
	SDL_Surface *screen;
	SDL_Event event;
	Mix_Music *musique;
	player pl;
	enmie e_s1[3];
	perso p;
	input_joueur input;
	obstacles o[3];
	shot p_sh;
	trap t_s1[2];
	finish f;
	vie_player v;
	init_imageVies(&v);
	checkpoint ch[3];
	text txt[2];
	int l_log=0,l_mdp=0;
	char mdp[20],log[20],secret[20];
	//***** LES BACKGROUND *****//
		background back_menu,back_setting,back_login,back_signeup,backlvl,back_enigme;
		background back_stage[3];

	//***** LES BOUTTON ***** //
	//boutton de menu

		boutton play,exit,setting,tops;

	//boutton de setting

		boutton done_set,full_on,plus_set,moin_set,return_set,option_set,son_set;

	//boutton de login

		boutton done_log,zone_usr,zone_psw,sign,eye,deconnect;

	//boutton de select lev

		boutton letsgo1,letsgo2,letsgo3,letsgo4,solo1,duo1,btn_skin,lock3,lock2,lock1;
	//
	
	mdp[0]='\0';
	log[0]='\0';
	secret[0]='\0';
	screen=SDL_SetVideoMode(1400,1000,32,SDL_HWSURFACE|SDL_SRCALPHA);
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	TTF_Init();
	initialiser_input(&input);
	initialiser_backmenu(&back_menu);
	initialiser_backsett(&back_setting);
	
	//menu
	initialiser_play(&play);
	initialiser_exit(&exit);
	initialiser_setting(&setting);
	initialiser_tops(&tops);
	
	//setting
	initialiser_backsett(&back_setting);
	initialiser_bt_done_set(&done_set);
	initialiser_bt_full_on(&full_on);
	initialiser_bt_plus_set(&plus_set);
	initialiser_bt_moin_set(&moin_set);
	initialiser_bt_return_set(&return_set);
	initialiser_bt_option_set(&option_set);
	initialiser_bt_son_set(&son_set);
	
	//login
	initialiser_back_login(&back_login);
	initialiser_backsigneup(&back_signeup);
	initialiser_txt(txt);
	initialiser_btn_sign(&sign);
	initialiser_zone_usr(&zone_usr);
	initialiser_zone_psw(&zone_psw);
	initialiser_bt_done_log(&done_log);
	initialiser_eye(&eye);
	initialiser_deconnect(&deconnect);
	
	// select lev
	initialiser_backselct_lev(&backlvl);
	printf("e\n" );
	initialiser_bt_letsgo1(&letsgo1);
	initialiser_bt_letsgo2(&letsgo2);
	initialiser_bt_letsgo3(&letsgo3);
	initialiser_bt_letsgo4(&letsgo4);
	
	initialiser_bt_solo1(&solo1);
	initialiser_bt_duo1(&duo1);
	initialiser_btn_skin(&btn_skin);
	initialiser_lock1(&lock1);
	initialiser_lock2(&lock2);
	initialiser_lock3(&lock3);
	//intiialiser_shot(&p_sh);
	//***** LES ENMIE *****//
		
		initenmieSTAGE1(e_s1);
		
	//***** LES PERSO *****//
	
		initPerso(&p);
		
	//***** obstacles *****//
		initialiser_obstaclesSTAGE1(&o[0]);
		initialiser_trapsSTAGE1(t_s1);
	//shot
		initialiser_shot(&p_sh);


	initialiser_door(&f);
	initialiser_chekpointSTAGE1(&ch[0]);
	initialiser_backSTAGE1(&back_stage[0]);
	init_enigme(&e);
	musique=Mix_LoadMUS("son/music audio.mp3");
	Mix_PlayMusic(musique,-1);
	initBonus(&b);
	
	while (boocle==1)
	{
		if(etat_enigme==1)
		{
			afficher_enigme(screen,e);
		}
		else if(stage>0)
		{
			afficher_back(screen,back_stage[stage-1]);
			
			afficherBonus(screen , b);
			//afficher_obstacles(screen,o[stage-1]);
			afficher_shot(screen,p_sh);
			afficher_imageVies(screen,v);
			collision_obstacles(o[stage-1],p,c_obstacles);
			
			//afficher_chekpoint(screen,ch[stage-1]);
			afficher_enmie(screen,e_s1[0]);
			afficher_enmie(screen,e_s1[1]);
			c_checkpoint=collision_checkpoint(ch[stage-1],p);
			veriph_dir(o[stage-1],&p,c_obstacles);
			printf("%d\n",o[0].pos[0].x);
			if(stage==1)
			{
				afficher_trap(screen,t_s1[0]);
				afficher_trap(screen,t_s1[1]);
				//afficher_door(screen,f);
				c_enmie=collision_enemie(p,e_s1);
				c_finish=collision_finish(p,f);
				//SDL_BlitSurface(o[0].img_obS[0] , NULL , screen , &o[0].pos[4]);
			}
			afficherPerso(screen,p);
		}
		else if(etat_menu==0)
		{
			if(sing_up==0)
			{
				afficher_back(screen,back_login);
				//afficher_btn(screen,sign);
			}
			else
			{
				afficher_back(screen,back_signeup);
				//afficher_btn(screen,deconnect);
			}
			//afficher_btn(screen,done_log);
			afficher_btn(screen,zone_usr);
			afficher_btn(screen,zone_psw);
			
			afficher_txt(screen,txt[1],mdp);
			afficher_txt(screen,txt[0],log);
			//afficher_btn(screen,eye);
		}
		else if(etat_menu==1)
		{
			afficher_btn(screen,deconnect);
			afficher_back(screen,back_menu);
			afficher_btn(screen,play);
			afficher_btn(screen,exit);
			afficher_btn(screen,setting);
			afficher_btn(screen,tops);
			afficher_btn(screen,deconnect);
		}
		else if(etat_menu==2)
		{
			afficher_back(screen,back_setting);
			afficher_btn(screen,done_set);
			afficher_btn(screen,full_on);
			afficher_btn(screen,plus_set);
			afficher_btn(screen,moin_set);
			afficher_btn(screen,return_set);
			//afficher_btn(screen,option_set);
			afficher_btn(screen,son_set);
			full_on.p=full;
		}
		else if(etat_menu==3)
		{
			afficher_back(screen,backlvl);
			afficher_btn(screen,btn_skin);
			afficher_btn(screen,letsgo1);
			afficher_btn(screen,letsgo2);
			afficher_btn(screen,letsgo3);
			afficher_btn(screen,letsgo4);
		}
		
		SDL_Flip(screen);
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
			case SDL_QUIT:
				boocle=0;
				break;
			case SDL_MOUSEMOTION:
				
				if(etat_menu==0)
				{
					if((event.motion.x>=done_log.pos.x && event.motion.x<=done_log.pos.x+done_log.pos.w) && 
					   (event.motion.y>=done_log.pos.y && event.motion.y<=done_log.pos.y+done_log.pos.h))
					{
						animer_btns_login(&done_log.p,&sign.p,1,0);	
					}
					else if ((event.motion.x>=sign.pos.x && event.motion.x<=sign.pos.x+sign.pos.w) && 
						(event.motion.y>=sign.pos.y && event.motion.y<=sign.pos.y+sign.pos.h))
					{
						animer_btns_login(&done_log.p,&sign.p,0,1);
					}
					else animer_btns_login(&done_log.p,&sign.p,0,0);
				}
				else if(etat_menu==1)//menu
				{
					if(event.motion.x>=play.pos.x && event.motion.x<=play.pos.x+play.pos.w)
					{
						if(event.motion.y>=play.pos.y && event.motion.y<=play.pos.y+play.pos.h)
						{
							animer_btnsmenu(&play.p,&exit.p,&setting.p,&tops.p,1,0,0,0);
							select=1;
						}
						else if(event.motion.y>=exit.pos.y && event.motion.y<=exit.pos.y+play.pos.h)
						{
							animer_btnsmenu(&play.p,&exit.p,&setting.p,&tops.p,0,1,0,0);
							select=4;
						}
						else if(event.motion.y>=setting.pos.y && event.motion.y<=setting.pos.y+play.pos.h)
						{
							animer_btnsmenu(&play.p,&exit.p,&setting.p,&tops.p,0,0,1,0);
							select=2;
						}
						else if(event.motion.y>=tops.pos.y && event.motion.y<=tops.pos.y+play.pos.h)
						{
							animer_btnsmenu(&play.p,&exit.p,&setting.p,&tops.p,0,0,0,1);
							select=3;
						}
					}
					else 
					{
						animer_btnsmenu(&play.p,&exit.p,&setting.p,&tops.p,0,0,0,0);
						select=0;
					}
				}
				else if(etat_menu==2)//setting
				{
					if((event.motion.x>=done_set.pos.x && event.motion.x<=done_set.pos.x+done_set.pos.w) && 
				  	 (event.motion.y>=done_set.pos.y && event.motion.y<=done_set.pos.y+done_set.pos.h))
					{
						animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,1,full_on.p,0,0,0,0,son_set.p);
					}
					else if((event.motion.x>=plus_set.pos.x && event.motion.x<=plus_set.pos.x+plus_set.pos.w) && 
					   (event.motion.y>=plus_set.pos.y && event.motion.y<=plus_set.pos.y+plus_set.pos.h))
					{
						animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,0,full_on.p,1,0,0,0,son_set.p);
					}
					else if((event.motion.x>=moin_set.pos.x && event.motion.x<=moin_set.pos.x+moin_set.pos.w) && 
					   (event.motion.y>=moin_set.pos.y && event.motion.y<=moin_set.pos.y+moin_set.pos.h))
					{
animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,0,full_on.p,0,1,0,0,son_set.p);
					}
					else if((event.motion.x>=return_set.pos.x && event.motion.x<=return_set.pos.x+return_set.pos.w) && 
					   (event.motion.y>=return_set.pos.y && event.motion.y<=return_set.pos.y+return_set.pos.h))
					{
						animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,0,full_on.p,0,0,1,0,son_set.p);
					}
					else if((event.motion.x>=option_set.pos.x && event.motion.x<=option_set.pos.x+option_set.pos.w) && 
					   (event.motion.y>=option_set.pos.y && event.motion.y<=option_set.pos.y+option_set.pos.h))
					{
						animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,0,full_on.p,0,0,0,1,son_set.p);
					}
					else 
					{
					animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,0,full_on.p,0,0,0,0,son_set.p);
					}
				}
				else if(etat_menu==3)
				{
					if(pl.nbr_stage>=1) 
					{
						if((event.motion.x>=letsgo1.pos.x && event.motion.x<=letsgo1.pos.x+letsgo1.pos.w) && 
				   			(event.motion.y>=letsgo1.pos.y && event.motion.y<=letsgo1.pos.y+letsgo1.pos.h))
							{
								
								etat=0;
								if((event.motion.x>=solo1.pos.x && event.motion.x<=solo1.pos.x+solo1.pos.w) && 
								   (event.motion.y>=solo1.pos.y && event.motion.y<=solo1.pos.y+solo1.pos.h))
								{
									lv1=1;
									animer_btns_selectlev(&solo1.p,&duo1.p,1,0);
								}
								else if((event.motion.x>=duo1.pos.x && event.motion.x<=duo1.pos.x+duo1.pos.w) && 
								   	(event.motion.y>=duo1.pos.y && event.motion.y<=duo1.pos.y+duo1.pos.h))
								{
									lv1=1;
									animer_btns_selectlev(&solo1.p,&duo1.p,0,1);
								}
								
							}
						else
							{
								animer_btns_selectlev(&solo1.p,&duo1.p,0,0);
								lv1=0;
								etat=1;
							}
					}
				
					if(pl.nbr_stage>=2)  
					{
						if((event.motion.x>=letsgo2.pos.x && event.motion.x<=letsgo2.pos.x+letsgo2.pos.w) && 
				   		(event.motion.y>=letsgo2.pos.y && event.motion.y<=letsgo2.pos.y+letsgo2.pos.h))
						{
							letsgo2.p=1;
						}
						else letsgo2.p=0;
					}
					
					if(pl.nbr_stage>=3)  
					{
						if((event.motion.x>=letsgo3.pos.x && event.motion.x<=letsgo3.pos.x+letsgo3.pos.w) && 
						   (event.motion.y>=letsgo3.pos.y && event.motion.y<=letsgo3.pos.y+letsgo3.pos.h))
						{
							letsgo3.p=1;
						}
						else letsgo3.p=0;
					}
					
					if(pl.nbr_stage>=4)  
					{
						if((event.motion.x>=letsgo4.pos.x && event.motion.x<=letsgo4.pos.x+letsgo4.pos.w) && 
					   	(event.motion.y>=letsgo4.pos.y && event.motion.y<=letsgo4.pos.y+letsgo4.pos.h))
						{
							letsgo4.p=1;
						}
						else letsgo4.p=0;
					}
					
				 	if ((event.motion.x>=btn_skin.pos.x && event.motion.x<=btn_skin.pos.x+btn_skin.pos.w) && 
				   	(event.motion.y>=btn_skin.pos.y && event.motion.y<=btn_skin.pos.y+btn_skin.pos.h))
					{
						btn_skin.p=1;
					}
					else btn_skin.p=0;
				}
				if(etat_enigme==1)
				{
					if(event.motion.x>e.reponse1.pos.x && event.motion.x<e.reponse1.pos.x+e.reponse1.pos.w
					&& event.motion.y>e.reponse1.pos.y && event.motion.y<e.reponse1.pos.y+e.reponse1.pos.h)
					{
						e.reponse1.p = 1;
						e.reponse2.p = 0;
						e.reponse3.p = 0;
					}
					else if(event.motion.x>e.reponse2.pos.x && event.motion.x<e.reponse2.pos.x+e.reponse2.pos.w
					&& event.motion.y>e.reponse2.pos.y && event.motion.y<e.reponse2.pos.y+e.reponse2.pos.h)
					{
						e.reponse1.p = 0;
						e.reponse2.p = 1;
						e.reponse3.p = 0;
					}
					else if(event.motion.x>e.reponse3.pos.x && event.motion.x<e.reponse3.pos.x+e.reponse3.pos.w
					&& event.motion.y>e.reponse3.pos.y && event.motion.y<e.reponse3.pos.y+e.reponse3.pos.h)
					{
						e.reponse1.p = 0;
						e.reponse2.p = 0;
						e.reponse3.p = 1;
					}
					else
					{
						e.reponse1.p = 0;
						e.reponse2.p = 0;
						e.reponse3.p = 0;
					}
				}
				break;
			case SDL_MOUSEBUTTONUP:
				
				if(etat_menu==0)
				{
					if(event.motion.x>=593 && event.motion.x<=1071)
					{
						if(event.motion.y>=464 && event.motion.y<=546)
						{
							animer_btns_login(&zone_usr.p,&zone_psw.p,1,0);
						}
						else if(event.motion.y>=593 && event.motion.y<=675)
						{
							animer_btns_login(&zone_usr.p,&zone_psw.p,0,1);
						}
					}
					if((event.motion.x>=eye.pos.x && event.motion.x<=eye.pos.x+eye.pos.w) && 
					(event.motion.y>=eye.pos.y&& event.motion.y<=eye.pos.y+eye.pos.h))
					{
						if(eye.p==1) eye.p=0;
						else eye.p=1;
					}
					if ((event.motion.x>=sign.pos.x && event.motion.x<=sign.pos.x+sign.pos.w) && 
						(event.motion.y>=sign.pos.y && event.motion.y<=sign.pos.y+sign.pos.h))
					{
						sing_up=1;
						mdp[0]='\0';
						log[0]='\0';
						secret[0]='\0';
						l_mdp=0;
						l_log=0;
						txt[0].txt= TTF_RenderText_Blended(txt[0].police, mdp, txt[0].color);
						txt[1].txt= TTF_RenderText_Blended(txt[1].police, log, txt[1].color);
					}
					else if((event.motion.x>=deconnect.pos.x && event.motion.x<=deconnect.pos.x+deconnect.pos.w) && 
				   	(event.motion.y>=deconnect.pos.y && event.motion.y<=deconnect.pos.y+deconnect.pos.h))
					{
						sing_up=0;
					}
					if((event.motion.x>=done_log.pos.x && event.motion.x<=done_log.pos.x+done_log.pos.w) && 
				   	(event.motion.y>=done_log.pos.y && event.motion.y<=done_log.pos.y+done_log.pos.h))
					{
						if(sing_up==1)
						{
							if(verifier_signup(mdp,log)==1)
							{
								signe_up(mdp,log);
								sing_up=0;
							}
							else
							{
								mdp[0]='\0';
								secret[0]='\0';
								log[0]='\0';
								l_log=0;
								l_mdp=0;
							}
						}
						else
						{
							pl=verifier_log(mdp,log);
							if(pl.mdp[0]!='\0')
							{
								SDL_FreeSurface(screen);
								screen=SDL_SetVideoMode(1200,675,32,SDL_HWSURFACE|SDL_SRCALPHA);
								etat_menu=1;
							}
						}
					}
				}
				else if(etat_menu==1)
				{
					if(event.motion.x>=play.pos.x && event.motion.x<=play.pos.x+play.pos.w)
					{
						if(event.motion.y>=exit.pos.y && event.motion.y<=exit.pos.y+play.pos.h)
						{
							boocle=0;
						}
						else if(event.motion.y>=setting.pos.y && event.motion.y<=setting.pos.y+play.pos.h)
						{
							
							etat_menu=2;
						}
						else if(event.motion.y>=play.pos.y && event.motion.y<=play.pos.y+play.pos.h)
						{
							etat_menu=3;
						}
					}
					else if((event.motion.x>=deconnect.pos.x && event.motion.x<=deconnect.pos.x+deconnect.pos.w) && 
				   	(event.motion.y>=deconnect.pos.y && event.motion.y<=deconnect.pos.y+deconnect.pos.h))
					{
						etat_menu=0;
					}
				}
				else if(etat_menu==2)
				{
					if((event.motion.x>=return_set.pos.x && event.motion.x<=return_set.pos.x+return_set.pos.w) && 
					   (event.motion.y>=return_set.pos.y && event.motion.y<=return_set.pos.y+return_set.pos.h))
						etat_menu--;
					else if ((event.motion.x>=done_set.pos.x && event.motion.x<=done_set.pos.x+done_set.pos.w) && 
				   (event.motion.y>=done_set.pos.y && event.motion.y<=done_set.pos.y+done_set.pos.h))
					etat_menu--;
					else if((event.motion.x>=plus_set.pos.x && event.motion.x<=plus_set.pos.x+plus_set.pos.w) && 
					   (event.motion.y>=plus_set.pos.y && event.motion.y<=plus_set.pos.y+plus_set.pos.h) && volum<10)
					{
						volum++;
						if(volum==1) son_set.p=0;
						Mix_VolumeMusic((128*volum*10)/100);
					}
					else if((event.motion.x>=moin_set.pos.x && event.motion.x<=moin_set.pos.x+moin_set.pos.w) && 
					(event.motion.y>=moin_set.pos.y && event.motion.y<=moin_set.pos.y+moin_set.pos.h))
					{
						volum--;
						if (volum==0) son_set.p=1;			
						Mix_VolumeMusic((128*volum*10)/100);
					}
					else if((event.motion.x>=full_on.pos.x && event.motion.x<=full_on.pos.x+full_on.pos.w) && 
					(event.motion.y>=full_on.pos.y && event.motion.y<=full_on.pos.y+full_on.pos.h))
					{
						SDL_WM_ToggleFullScreen(screen);
						if (full==0) full=1;
						else full=0;
							
					}
					else if((event.motion.x>=son_set.pos.x && event.motion.x<=son_set.pos.x+son_set.pos.w) && 
					(event.motion.y>=son_set.pos.y && event.motion.y<=son_set.pos.y+son_set.pos.h))
					{
						if(volum!=0)
						{
							volum=0;
							son_set.p=1;
							Mix_VolumeMusic((128*volum*10)/100);
						}
						else
						{
							volum=1;
							son_set.p=0;
							Mix_VolumeMusic((128*volum*10)/100);
						}
					}
				}
				else if(etat_menu==3)
				{
					if(pl.nbr_stage>=1) 
					{
						if((event.motion.x>=letsgo1.pos.x && event.motion.x<=letsgo1.pos.x+letsgo1.pos.w) && 
					   	(event.motion.y>=letsgo1.pos.y && event.motion.y<=letsgo1.pos.y+letsgo1.pos.h))
						{
									
							etat=0;
							if((event.motion.x>=solo1.pos.x && event.motion.x<=solo1.pos.x+solo1.pos.w) && 
							 (event.motion.y>=solo1.pos.y && event.motion.y<=solo1.pos.y+solo1.pos.h))
							{
								SDL_FreeSurface(screen);
								screen=SDL_SetVideoMode(1400,1000,32,SDL_HWSURFACE|SDL_SRCALPHA);
								stage=1;
								p.maxsaut=17;
							}
						}
					}
				}
				if(etat_enigme==1)
				{
					if(e.reponse1.p == 1 && e.r_exact==1
					|| e.reponse2.p == 1 && e.r_exact==2
					|| e.reponse3.p == 1 && e.r_exact==3)
					{
						printf("bien\n") ;
						Mix_PlayChannel( -1,e.song[0],0);
					}
					else
					{
						printf("pas bien\n");
						Mix_PlayChannel( -1,e.song[1],0);
					}
					genererEnigme(&e);
				}
				break;			
				break;
			case SDL_KEYDOWN:
				
				if (event.key.keysym.sym==SDLK_ESCAPE)
				{
					SDL_WM_ToggleFullScreen(screen);
					if(full==1)full=0;
					else full=1;
				}
				else if (event.key.keysym.sym==SDLK_r)
				{
					if(etat_menu!=0)
						etat_menu--;
					stage=0;
					r_enigme=0;
				}
				else if (event.key.keysym.sym==SDLK_e && etat_menu!=0)
				{
					etat_enigme=1;
				}
				if(stage>0)
				{
					if(event.key.keysym.sym==input.right)
					{
						
						p.etat=2;
						p.dir=0;
						p.vitesse=20;
					}
					else if(event.key.keysym.sym==input.down)
					{
						if(p.saut!=1)
						{
							p.etat=4;
							p.mouvment=0;
						}
					}
					else if(event.key.keysym.sym==input.up)
					{
						if(p.saut!=1)
						{
							p.saut=1;
							p.mouvment=-1;
							p.haut=1;
						}
					}
					if(event.key.keysym.sym==input.left)
					{
						p.etat=2;
						p.dir=1;
						p.vitesse=20;
					}
					else if(event.key.keysym.sym==input.attack)
					{
						if(p.saut!=1)
						{
							//p.etat=5;
							p.mouvment=0;
							
						}
						ajout_shot(&p_sh,p.pos,p.dir,60);
						
					}
					else if(event.key.keysym.sym==SDLK_c)
					{
						p.etat=1;
						p.vitesse=10;
					}
				}
				else if(etat_menu==0)
				{
					if (event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z) 
					{
						if(zone_usr.p==1)
						{
							log[l_log]=event.key.keysym.sym;
							l_log++;
							log[l_log]='\0';
							SDL_FreeSurface(txt[0].txt);
							txt[0].txt= TTF_RenderText_Blended(txt[0].police, log, txt[0].color);
							
						}
						else
						{
							mdp[l_mdp]=event.key.keysym.sym;
							l_mdp++;
							mdp[l_mdp]='\0';
							SDL_FreeSurface(txt[1].txt);
							txt[1].txt= TTF_RenderText_Blended(txt[1].police, mdp, txt[1].color);
						}
					}
					else if((event.key.keysym.sym >= SDLK_KP0 && event.key.keysym.sym <= SDLK_KP9))
					{
						if(zone_usr.p==1)
						{
							sprintf(num,"%d",event.key.keysym.sym-256);
							strcat(log,num);
							l_log++;
							log[l_log]='\0';
							SDL_FreeSurface(txt[0].txt);
							txt[0].txt= TTF_RenderText_Blended(txt[0].police, log, txt[0].color);
						}
						else
						{
							sprintf(num,"%d",event.key.keysym.sym-256);
							strcat(mdp,num);
							l_mdp++;
							mdp[l_mdp]='\0';
							SDL_FreeSurface(txt[1].txt);
							txt[1].txt= TTF_RenderText_Blended(txt[1].police, mdp, txt[1].color);
						}
					}
					else if(event.key.keysym.sym==SDLK_BACKSPACE)
					{
						if(zone_usr.p==1 && log[0]!='\0')
						{
							log[l_log-1]='\0';
							l_log--;
							SDL_FreeSurface(txt[0].txt);
							txt[0].txt= TTF_RenderText_Blended(txt[0].police, log, txt[0].color);
						}
						else
						{
							mdp[l_mdp-1]='\0';
							l_mdp--;
							SDL_FreeSurface(txt[1].txt);
							txt[1].txt= TTF_RenderText_Blended(txt[1].police, mdp, txt[1].color);
						}
					}
					
				}
				else if(etat_menu==1)
				{
					if(event.key.keysym.sym==SDLK_DOWN)
					{
						select++;
						if(select>4) select=1;
					}
					else if(event.key.keysym.sym==SDLK_UP)
					{
						select--;
						if(select<1) select=4;
					}
					else if (event.key.keysym.sym==SDLK_RETURN)
					{
						if(select==4) boocle=0;
					}
					else if(event.key.keysym.sym==SDLK_p) select=1;
					else if(event.key.keysym.sym==SDLK_s) select=2;
					else if(event.key.keysym.sym==SDLK_t) select=3;
					else if(event.key.keysym.sym==SDLK_q) select=4;
					switch(select)
					{
						case 1:
							animer_btnsmenu(&play.p,&exit.p,&setting.p,&tops.p,1,0,0,0);
							break;
						case 2:
							animer_btnsmenu(&play.p,&exit.p,&setting.p,&tops.p,0,0,1,0);
							break;
						case 3:
							animer_btnsmenu(&play.p,&exit.p,&setting.p,&tops.p,0,0,0,1);
							break;
						case 4:
							animer_btnsmenu(&play.p,&exit.p,&setting.p,&tops.p,0,1,0,0);
							break;
					}
					
				}
				if(etat_enigme==1)
				{
					if(event.key.keysym.sym == SDLK_a)
					{
						e.reponse1.p = 1;
						e.reponse2.p = 0;
						e.reponse3.p = 0;
					}
					else if(event.key.keysym.sym == SDLK_b)
					{
						e.reponse1.p = 0;
						e.reponse2.p = 1;
						e.reponse3.p = 0;
					}
					else if(event.key.keysym.sym == SDLK_c)
					{
						e.reponse1.p = 0;
						e.reponse2.p = 0;
						e.reponse3.p = 1;
					}
					else if(event.key.keysym.sym == SDLK_RETURN)
					{
						if(e.reponse1.p == 1 && e.r_exact==1
						|| e.reponse2.p == 1 && e.r_exact==2
						|| e.reponse3.p == 1 && e.r_exact==3)
						{
							printf("bien\n") ;
							Mix_PlayChannel( -1,e.song[0],0);
						}
						else
						{
							printf("pas bien\n");
							Mix_PlayChannel( -1,e.song[1],0);
						}
						genererEnigme(&e);
					}
				}
				break;
				case SDL_KEYUP:
					p.pos.w=80;
				
					if(event.key.keysym.sym==input.right && p.dir==0)
					{
						p.mouvment=0;
						p.etat=0;
					}
					else if(event.key.keysym.sym==input.down && p.etat==4)
					{
						p.mouvment=0;
						p.etat=0;
					}
					else if(event.key.keysym.sym==input.left && p.dir==1)
					{
						p.mouvment=0;
						p.etat=0;
					}
					else if(event.key.keysym.sym==input.up)
					{
						p.haut=0;
					}
				break;
		}
		}
		//ANIMATION
		if(r_enigme==1)
		{
			animerBack(&back_enigme);
			
		}
		else if(stage==1)
		{
			animer_backenigme(&e.back);
			animer_enmie(&e_s1[0]);
			animer_enmie(&e_s1[1]);
			animerPerso(&p);
			animer_trap(&t_s1[0]);
			animer_trap(&t_s1[1]);
			animer_checkpoint(&ch[0]);
			animer_door(&f,c_finish);
			SDL_Delay(40);
		}
		else if(etat_menu==1)
		{
			animerBack(&back_menu);
			SDL_Delay(40);
		}
		//DEPLACEMENT
		
		if(stage==1 && r_enigme!=1)
		{
			move_enmie(&e_s1[0]);
			move_enmie(&e_s1[1]);
			//movobstacle(&o[stage-1]);
			move_shot(&p_sh,p.pos);
			if(p.etat==1 ||p.etat==2 )
			{
				if((p.dir==0 && (p.pos.x<=700 || (back_stage[stage-1].pos2.x>=back_stage[stage-1].pos1.w-back_stage[stage-1].pos2.w && p.pos.x<=back_stage[stage-1].pos2.w-p.pos.w-10))) 
				||  p.dir==1 && (p.pos.x>=100 || (back_stage[stage-1].pos2.x<=10 && p.pos.x>=10)))
					movePerso(&p);
				else 
				{
					if((p.dir==1 && p.pos.x>back_stage[stage-1].pos1.x) || (p.dir==0 && p.pos.x<back_stage[stage-1].pos1.x+back_stage[stage-1].pos2.w-p.pos.w-10))
					{
						if((p.dir==0 && p.d!=0) || p.dir==1 && p.g!=0)
						{
							scrolling(&back_stage[stage-1],p.dir,p.vitesse);
							scrolling_ennemie(&e_s1[0],p.dir,p.vitesse);
							scrolling_ennemie(&e_s1[1],p.dir,p.vitesse);
							scrolling_obstacles(&o[stage-1],p.dir,p.vitesse);
							scrolling_shot(&p_sh,p.dir,p.vitesse);
							scrolling_trap(&t_s1[0],p.dir,p.vitesse,back_stage[stage-1]);
							scrolling_trap(&t_s1[1],p.dir,p.vitesse,back_stage[stage-1]);
							scrolling_chekpoint(&ch[0],p.dir,p.vitesse,back_stage[stage-1]);
							scrolling_door(&f,p.dir,p.vitesse);
							deplacerr_bonus(&b , p.dir , p.vitesse);
						}
					}
				}
			}
			if(p.saut==1)
			{
				saut(&p);
				if(((p.movsaut<19 && p.haut==1) && p.pos.y>=200) || ((p.movsaut>19 || p.haut==0) && p.pos.y<=550) || ((p.movsaut>19 || p.haut==0) && back_stage[stage-1].pos2.y>=200) || ((p.movsaut<19 && p.haut==1) && back_stage[stage-1].pos2.y<=22))				
						mouv_saut(&p);
				else if((p.movsaut<19 && p.haut==1) && p.h==1)
				{
					scrolling(&back_stage[stage-1],2,22);
					scrolling_ennemie(&e_s1[0],2,22);
					scrolling_ennemie(&e_s1[1],2,22);
					scrolling_obstacles(&o[stage-1],2,22);	
					scrolling_shot(&p_sh,2,22);
					scrolling_trap(&t_s1[0],2,22,back_stage[stage-1]);
					scrolling_trap(&t_s1[1],2,22,back_stage[stage-1]);
					scrolling_chekpoint(&ch[0],2,22,back_stage[stage-1]);
					scrolling_door(&f,2,22);
					deplacerr_bonus(&b ,2,22);
				}
				else if((p.movsaut>p.maxsaut || p.haut==0) && p.b==1)
				{
					scrolling(&back_stage[stage-1],3,22);
					scrolling_ennemie(&e_s1[0],3,22);
					scrolling_ennemie(&e_s1[1],3,22);
					scrolling_obstacles(&o[stage-1],3,22);
					scrolling_shot(&p_sh,3,22);
					scrolling_trap(&t_s1[0],3,22,back_stage[stage-1]);
					scrolling_trap(&t_s1[1],3,22,back_stage[stage-1]);
					scrolling_chekpoint(&ch[0],3,22,back_stage[stage-1]);
					scrolling_door(&f,3,22);
					deplacerr_bonus(&b ,3,22);	
				}
			}
			if(p.b==1 && p.saut!=1) 
			{
				p.saut=1;
				p.movsaut=17;
			}
		}
		if(v.nbr==0 || c_finish==1)
		{
			retoure_debut(&p,&back_stage[stage-1],&ch[stage-1], e_s1,&o[stage-1],t_s1,&f);
			v.nbr=3;
			stage=0;
			
		}
		//LORS DE LA COLLISION
		//***** collision de stage 1 ***** //
		if(stage==1 && r_enigme!=1)
		{
			if(c_obstacles[0]==0)
			{
				//deplacer_perso(&p,o[0].dir[0],5);
			}
			else if(c_enmie!=-1 && e_s1[c_enmie].pos.h!=0)
			{
				e_s1[c_enmie].pos.h=0;
				v.nbr--;
				retoure_debut(&p,&back_stage[stage-1],&ch[stage-1], e_s1,&o[stage-1],t_s1,&f);
			}
			else if(c_checkpoint!=-1)
			{
				ch[0].etat=c_checkpoint;
			}
		}
		for(int i=0;i<10;i++)
		{
			if(collision_trigo(b.pos[i],p.pos)==0)
			{
					
				b.etat[i]=0;
			}
		}
	}
}
