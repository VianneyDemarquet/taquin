/*
Vianney
Demarquet
*/

#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "entete.h"



void decoupage(int c, int l)
{
	unsigned int a=0;
	unsigned int xx=570, yy=270, x=0, y=0;
	
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

}



void melange(int c, int l)
{
	int i,t;
	srand((unsigned int) time(NULL));
	
	for (i = 0; i < 500; ++i)
	{
		t=rand();
		t=t%4;
		modif(t,c,l);
	}
}

void modif(int t, int c, int l)
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
		}
}


void affichage(int c, int l)
{
	int a=(c*l)-1;
	int i,x=0;

	for (i = 0; i < c*l; ++i)
	{
		ChargerImage("./slide-1.jpg",((pos[dec[i].pose].x)+1), ((pos[dec[i].pose].y)+1), (dec[i].x), (dec[i].y), (dec[i].xx), (dec[i].yy));

	}
}

