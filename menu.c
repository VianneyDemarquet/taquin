/*
Vianney
Demarquet
*/

#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "entete.h"


void affichagei(int x)
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
	int x=1,y=0,z=5;
	couleur coul;
	coul = CouleurParComposante(255, 255, 255);
	while (y==0)
	{
		
		
		if (x==1)
		{
			ChargerImage("./image1.jpg",10, 10,0,0,570,270);
		}else if(x==2)
		{
			ChargerImage("./image2.png",10, 10,0,0,332,300);
		} else if(x==3)
		{
			ChargerImage("./image3.jpg",10, 10,0,0,640,426);
		}
		affichagei(x);

		if (ToucheEnAttente()==1)
		{
			z=iclavier();
		} else if (SourisCliquee()==1)
		{
			z=isouris();
		}
			
		if (z==0 && x>1)
		{
			x--;
			clear();
		} else if(z==1 && x<3)
		{
			x++;
			clear();
		} 
		if(z==2)
		{
			return x;
		}
		z=5;
	}
}

void affichagenb(void)
{
	char tab[2];
	int x=100;

	for (int i = 3; i <= 8; ++i, x+=70)
	{
		sprintf(tab,"%d",i);
		EcrireTexte(x,200,tab,2);
		DessinerRectangle(x-10,175,35,30);
	}
	
}

int nbcolone(void)
{
	int x=0;
	affichagenb();
	EcrireTexte(200,50,"nombre de colonnes",2);
	
	while (x<3)
	{
		if (ToucheEnAttente()==1)
		{
			x=nbclavier();
		} else if (SourisCliquee()==1)
		{
			x=nbsouris();
		}
	}
	return x;
}

int nbligne(void)
{
	int x=0;
	affichagenb();
	EcrireTexte(200,50,"nombre de lignes",2);
	
	while (x<3)
	{
		if (ToucheEnAttente()==1)
		{
			x=nbclavier();
		} else if (SourisCliquee()==1)
		{
			x=nbsouris();
		}
	}
	return x;
}


int fin(int yy)
{
	int x=0;
	DessinerRectangle(290, yy+28, 80, 25);
	EcrireTexte(300, yy+50, "gagne", 2);
	EcrireTexte(150, yy+120, "recommencer", 2);
    DessinerRectangle(145, yy+98, 145, 25);
    EcrireTexte(450, yy+120, "quitter", 2);
    DessinerRectangle(445, yy+98, 95, 25);
	while (x==0)
	{
    	if (ToucheEnAttente()==1)
		{
			x=menuclavier();
		} else if (SourisCliquee()==1)
		{
			x=menusouris();
		}
    }
    return x;
}