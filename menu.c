/*
Vianney
Demarquet
*/

#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "entete.h"




int iclavier(void)
{
	unsigned long x=0;
	x=Touche();
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

int isouris(void)
{

}

void affichagemi(int x)
{
		
	if (x!=1)
	{
		DessinerRectangle(15,475,120,30);
		EcrireTexte(20,500,"precedent",2);
	} 
	 if(x!=3)
	{
		DessinerRectangle(445,475,100,30);
		EcrireTexte(450,500,"suivant",2);
	}
	DessinerRectangle(245,475,100,30);
	EcrireTexte(250,500,"choisir",2);
	
}


int choisirimage(void)
{
	int x=2,y=0,z=5;
	couleur coul;
	coul = CouleurParComposante(255, 255, 255);
	while (y==0)
	{
		
		
		if (x==1)
		{
			ChargerImage("./image1.jpg",10, 10,0,0,570,240);
		}else if(x==2)
		{
			ChargerImage("./image2.png",10, 10,0,0,332,300);
		} else if(x==3)
		{
			ChargerImage("./image3.jpg",10, 10,0,0,640,426);
		}
		affichagemi(x);

		if (ToucheEnAttente()==1)
		{
			z=iclavier();
		} /*else if (SourisCliquee()==1)
		{
			z=isouris();
			printf("sljoqoq\n");
		}*/
			
		if (z==0 && x>1)
		{
			x--;
			EffacerEcran(coul);
		} else if(z==1 && x<3)
		{
			x++;
			EffacerEcran(coul);
		} 
		if(z==2)
		{
			return x;
		}
		z=5;
	}
}
