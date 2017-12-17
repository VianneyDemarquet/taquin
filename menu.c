/*
Vianney
Demarquet
*/

#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "entete.h"


void image1(void)
{
	ChargerImage("./image1.jpg",10, 10,0,0,570,240);
}

void image2(void)
{
	ChargerImage("./image2.jpg",10, 10,0,0,570,240);
}

void image3(void)
{
	ChargerImage("./image3.jpg",10, 10,0,0,570,240);
}


/* renvoi toujour 1*/


int iclavier(void)
{
	unsigned long x=0;
	if (x==65361lu)
		return 0;
	else if (x==65363lu)
		return 1;
	else if (x==65293)
		return 3;
}

int isouris(void)
{

}
char* choisirimage(void)
{
	int x=1,y=0,z;

	while (y==0)
	{

		if (x==1)
		{
			image1();
		}else if(x==2);
		{
			image2();
		} if(x==3)
		{
			image3();
		}
		
		
		
		if (x!=1)
		{
			DessinerRectangle(15,425,120,30);
			EcrireTexte(20,450,"precedent",2);
		} 
		 if(x!=3)
		{
			DessinerRectangle(445,425,100,30);
			EcrireTexte(450,450,"suivant",2);
		}
		DessinerRectangle(245,425,100,30);
		EcrireTexte(250,450,"choisir",2);
		
		if (ToucheEnAttente()==1)
		{
			x=iclavier();
			printf("%d\n", x);
		} else if (SourisCliquee()==1)
		{
			x=isouris();
		}
	}
}
