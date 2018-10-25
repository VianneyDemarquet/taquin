/*
Vianney
Demarquet
*/

#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "entete.h"

/*
cette fonction permet de déplacé les tuiles du takin à l'aide du clavier
grâce à la valeur de la touche entré
*/
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

/*
cette fonction permet de déplacé les tuiles du takin à l'aide de la souris
grâce à la position du curseur au moment du clic
*/
int souris(struct image *dec, struct position *pos)
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

/*
cette fonction permet de sélectionné le périphérique utilisé pour le mouvement de la tuile
grace au fonction "clavier" et "souris" pour utilisé respectivement le clavier et la souris
puis appelle la fonction "modif" pour effectué ce mouvement.
*/
int control(int c, int l,int image,struct image *dec, struct position *pos)
{
	int x=5;
	while(x==5)
	{
	if (ToucheEnAttente()==1)
	{
		x=clavier();
	} else if (SourisCliquee()==1)
	{
		x=souris(dec,pos);
	}
	if (x!=5)
	{
		x=modif(x,c,l,dec,pos);
		if (x==0)
		{
			x=5;
		}
	}
	}
	return 1;
}

/*
cette fonction permet de selectioné les si l'on veut passé à l'image suivante,
l'image précédente ou choisir cette image tout en utilisant le clavier
grâce à la valeur de la touche entré
*/
int iclavier(void)
{
	unsigned long x=Touche();
	if (x==XK_Left)
	{
		return 0;
	} else if (x==XK_Right)
	{
		return 1;
	} else if (x==XK_Return)
	{
		return 2;
	}
}

/*
cette fonction permet de selectioné les si l'on veut passé à l'image suivante,
l'image précédente ou choisir cette image tout en utilisant la souris
grâce à la position du curseur au moment du clic
*/
int isouris(void)
{
	if (_X>15 && _X<135)
	{
		return 0;
	} else if (_X>445 && _X<545)
	{
		return 1;
	}else if (_X>245 && _X<345)
	{
		return 2;
	}
}

/*
cette fonction renvoie le nombre de ligne ou de cologne désiré à l'aide de la souris
grâce à la position du curseur au moment du clic
*/
int nbsouris(void)
{
	if (_X>=100 && _X<=135)
	{
		return 3;
	}else if (_X>=170 && _X<=205)
	{
		return 4;
	}else if (_X>=240 && _X<=275)
	{
		return 5;
	}else if (_X>=310 && _X<=345)
	{
		return 6;
	}else if (_X>=380 && _X<=415)
	{
		return 7;
	}else if (_X>=450 && _X<=485)
	{
		return 8;
	}
	return 0;
}

/*
cette fonction renvoie le nombre de ligne ou de cologne désiré à l'aide du clavier
grâce à la valeur de la touche entré
*/
int nbclavier(void)
{
	int x=Touche();
	
		x=Touche();
		if (x==XK_3)
		{
			return 3;
		}else if (x==XK_4)
		{
			return 4;
		}else if (x==XK_5)
		{
			return 5;
		}else if (x==XK_6)
		{
			return 6;
		}else if (x==XK_7)
		{
			return 7;
		}else if (x==XK_8)
		{
			return 8;
		}else if (x==XK_KP_3)
		{
			return 3;
		}else if (x==XK_KP_4)
		{
			return 4;
		}else if (x==XK_KP_5)
		{
			return 5;
		}else if (x==XK_KP_6)
		{
			return 6;
		}else if (x==XK_KP_7)
		{
			return 7;
		}else if (x==XK_KP_8)
		{
			return 8;
		}
	
	return 0;
}

/*
cette fonction permet de choisir si l'on veut quité le jeux ou faire une nouvelle partie
grâce à la valeur de la touche entré
*/
int menuclavier(void)
{
	unsigned long x=Touche();
	if (x==XK_Left)
	{
		return 8;
	} else if (x==XK_Right)
	{
		return 9;
	}
	return 0;
}

/*
cette fonction permet de choisir si l'on veut quité le jeux ou faire une nouvelle partie
grâce à la position du curseur au moment du clic
*/
int menusouris(void)
{
	if (_X>145 && _X<290)
	{
		return 8;
	} else if (_X>445 && _X<570)
	{
		return 9;
	}
	return 0;
}