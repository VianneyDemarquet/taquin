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

	x= Touche();
	if (x==65361lu)
		return 0;

	else if (x==65362lu)
		return 1;

	else if (x==65363lu)
		return 2;

	else if (x==65364lu)
		return 3;
}	

int souris(void)
{
	printf("%3u %3u %3u %3u %3u %3u\n",pos[dec[0].pose].x, pos[dec[0].pose].y, _X,_Y, dec[0].xx, dec[0].yy);

	if (_X<pos[dec[0].pose].x && _Y>pos[dec[0].pose].y && _Y<(pos[dec[0].pose].y+dec[0].yy))
		return 0;

	else if (_Y<pos[dec[0].pose].y && _X>pos[dec[0].pose].x && _Y<(pos[dec[0].pose].x+dec[0].xx))
		return 1;

	else if (_X>pos[dec[0].pose].x && _Y>pos[dec[0].pose].y && _Y<(pos[dec[0].pose].y+dec[0].yy))
		return 2;

	else if (_Y>pos[dec[0].pose].y && _X>pos[dec[0].pose].x && _Y<(pos[dec[0].pose].x+dec[0].xx))
		return 3;
}

void changement(int c, int l)
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
		affichage(c,l);
	}
}
