/*
Vianney
Demarquet
*/

#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "entete.h"

int clavier(int c, int l)
{
	unsigned long x=0;
	int y, res;

	x= Touche();
	if (x==65361lu)
		res=0;
	if (x==65362lu)
		res=1;
	if (x==65363lu)
		res=2;
	if (x==65364lu)
		res=3;
	
	modif(res,c,l);
	affichage(c,l);
}	
