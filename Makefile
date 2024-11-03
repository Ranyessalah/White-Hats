prog:main.o background.o menu.o setting.o login.o selectlev.o stage1.o es.o perso.o enigme.o
	gcc main.o background.o menu.o setting.o login.o selectlev.o stage1.o es.o perso.o enigme.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lm
main.o:main.c
	gcc -c main.c
background.o:background.c
	gcc -c background.c
menu.o:menu.c
	gcc -c menu.c
setting.o:setting.c
	gcc -c setting.c -g
login.o:login.c
	gcc -c login.c -g
selectlev.o:selectlev.c
	gcc -c selectlev.c -g
stage1.o:stage1.c 
	gcc -c stage1.c -g
es.o:es.c
	gcc -c es.c
perso.o:perso.c
	gcc -c perso.c
enigme.o:enigme.c
	gcc -c enigme.c
