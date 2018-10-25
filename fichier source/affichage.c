/*
Vianney
Demarquet
*/

#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "entete.h"


/*
cette fonction permet de fractioné l'image choisie (image) dans en utilisant 
le nombre de colone (c) et le nomobre de ligne (l) voulue
*/
int decoupage(int c, int l, int image,struct image *dec, struct position *pos)
{
	unsigned int a=0;
	unsigned int xx, yy, x=0, y=0;
	if (image==1)
	{
		xx=570;
		yy=270;
	}else if (image==2)
	{
		xx=332;
		yy=300;
	}else if (image==3)
	{
		xx=640;
		yy=426;
	}


	for (int i = 0; i < l; ++i)
	{
		for (int d = 0; d < c; ++d)
		{

			dec[a].x=x;
			dec[a].y=y;
			dec[a].xx=xx/c;
			dec[a].yy=yy/l;
			dec[a].pose=a;
			pos[a].x=x;
			pos[a].y=y;
			a++;
			x=1+x+(xx/c);
			
		}
		x=0;
		y=1+y+(yy/l);
	}
		dec[0].x=x;
		dec[0].y=y;
		return (int)yy;
}


/*
cette fonction créé une valeur qui coréspond à un déplacement horizontal ou vertical
que doit effectué la fonction "modif" qui est ensuite appelé.
*/
void melange(int c, int l,struct image *dec, struct position *pos)
{
	int i,t;
	srand((unsigned int) time(NULL));
	
	for (i = 0; i < 500; ++i)
	{
		t=rand();
		t=t%4;
		modif(t,c,l,dec,pos);
	}
}

/*
cette fonction modifie la position de la tuile qui à été retiré en fonction 
de la valeur du mouvement désiré
*/
int modif(int t, int c, int l,struct image *dec, struct position *pos)
{
	int a;
	if (t==0 && dec[0].pose>0 && (dec[0].pose)%c!=0)
		{
			for (a = 1; a < c*l; ++a)
			{
				if (dec[0].pose-1 == dec[a].pose)
				{
					dec[a].pose = dec[0].pose;
					a=c*l;
					
				}
			}
			dec[0].pose--;
			return 1;

		}else if (t==1 && (dec[0].pose)>=c)
		{
			for (a = 1; a < c*l; ++a)
			{
				if (dec[0].pose-c == dec[a].pose)
				{				
					dec[a].pose = dec[0].pose;
					a=c*l;
					
				}
			}
			dec[0].pose = dec[0].pose-c;
			return 1;

		}else if (t==2 && dec[0].pose<(c*l) && (dec[0].pose+1)%c!=0)
		{
			for (a = 1; a < c*l; ++a)
			{
				if (dec[0].pose+1 == dec[a].pose)
				{					
					dec[a].pose = dec[0].pose;
					a=c*l;
					
				}
			}
			dec[0].pose++;
			return 1;

		}else if (t==3 && (dec[0].pose)<((c*l))-c)
		{
			for (a = 1; a < c*l; ++a)
			{
				if (dec[0].pose+c == dec[a].pose)
				{
					dec[a].pose = dec[0].pose;
					a=c*l;
					
				}
			}
			dec[0].pose = dec[0].pose+c;
			return 1;

		} else
		return 0;
}

/*
cette fonction affiche les positions des différente tuile de la partie en cour
ou affiche l'image et appelle la fonction "fin" si la partie est finie
*/
int affichage(int c, int l,int image,int comp,struct image *dec, struct position *pos)
{
	int a=(c*l)-1;
	int i,x=0;
	if (image==1)
	{
			for (i = 0; i < c*l; ++i)
		{
			ChargerImage("./image1.jpg",((pos[dec[i].pose].x)+1), ((pos[dec[i].pose].y)+1), (dec[i].x), (dec[i].y), (dec[i].xx), (dec[i].yy));

			if (dec[i].x==pos[dec[i].pose].x && dec[i].y==pos[dec[i].pose].y)
			{
				x++;
			}
		}

		if (x==i-1)
		{
			clear();
			ChargerImage("./image1.jpg",10, 10,0,0,570,270);
			x=fin(280,comp);
			return x;
		}


	}else if (image==2)
	{
			for (i = 0; i < c*l; ++i)
		{
			ChargerImage("./image2.png",((pos[dec[i].pose].x)+1), ((pos[dec[i].pose].y)+1), (dec[i].x), (dec[i].y), (dec[i].xx), (dec[i].yy));
			if (dec[i].x==pos[dec[i].pose].x && dec[i].y==pos[dec[i].pose].y)
			{
				x++;
			}
		}

		if (x==i-1)
		{
			clear();
			ChargerImage("./image2.png",10, 10,0,0,332,300);
			x=fin(310, comp);
			return x;
		}


	}if (image==3)
	{
			for (i = 0; i < c*l; ++i)
		{
			ChargerImage("./image3.jpg",((pos[dec[i].pose].x)+1), ((pos[dec[i].pose].y)+1), (dec[i].x), (dec[i].y), (dec[i].xx), (dec[i].yy));
			if (dec[i].x==pos[dec[i].pose].x && dec[i].y==pos[dec[i].pose].y)
			{
				x++;
			}
		}

		if (x==i-1)
		{
			clear();
			ChargerImage("./image3.jpg",10, 10,0,0,640,426);
			x=fin(436,comp);
			return x;
		}
	}
	return 0;

}

