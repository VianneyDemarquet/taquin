/*
Vianney
Demarquet
*/

#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "entete.h"

int clavier(void)
{
	unsigned long x=0;

	x=Touche();
	if (x==XK_Left)
		return 0;

	else if (x==XK_Up)
		return 1;

	else if (x==XK_Right)
		return 2;

	else if (x==XK_Down)
		return 3;
}	

int souris(void)
{

	if (_X<pos[dec[0].pose].x && _Y>pos[dec[0].pose].y && _Y<(pos[dec[0].pose].y+dec[0].yy))
		return 0;

	else if (_Y<pos[dec[0].pose].y && _X>pos[dec[0].pose].x && _Y<(pos[dec[0].pose].x+dec[0].xx))
		return 1;

	else if (_X>pos[dec[0].pose].x && _Y>pos[dec[0].pose].y && _Y<(pos[dec[0].pose].y+dec[0].yy))
		return 2;

	else if (_Y>pos[dec[0].pose].y && _X>pos[dec[0].pose].x && _Y<(pos[dec[0].pose].x+dec[0].xx))
		return 3;
}

int control(int c, int l,int image)
{
	int x=5;
	if (ToucheEnAttente()==1)
	{
		x=clavier();
	} else if (SourisCliquee()==1)
	{
		x=souris();
	}
	if (x!=5)
	{
		modif(x,c,l);
		affichage(c,l,image);
		return 1;
	}
	return 0;
}
