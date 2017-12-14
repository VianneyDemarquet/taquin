#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
struct image
{
	unsigned int x;
	unsigned int y;
	unsigned int xx;
	unsigned int yy;
};

struct position
{
	unsigned int x;
	unsigned int y;
};

struct image *dec;
struct position *pos;

void decoupage(int c, int l)
{
	int a=0;
	unsigned int xx=570, yy=270, x=0, y=0;

	dec=(struct image *) malloc(c*l*sizeof(struct image));

	
	for (int i = 0; i < l; ++i)
	{
		for (int d = 0; d < c; ++d)
		{
			dec[a].x=x;
			dec[a].y=y;
			dec[a].xx=xx;
			dec[a].yy=yy;
			pos[a].x=x;
			pos[a].y=y;
			a++;
			x=1+x+(xx/c);

		}
		x=0;
		y=1+y+(yy/l);
	}

}

void affichage(int c, int l)
{
	for (int i = 0; i < c*l; ++i)
	{
		ChargerImage("./slide-1.jpg",((pos[i].x)+1), ((pos[i].y)+1), (dec[i].x), (dec[i].y), (dec[i].xx), (dec[i].yy));
	}
}

int main(void)
{
	unsigned int c, l;
	InitialiserGraphique();
    CreerFenetre(10,10,1000,1000);

   	printf("nombre de ligne\n");
   	scanf("%u",&l);
   	printf("nombre de colone\n");
   	scanf("%u",&c);
   	decoupage(c,l);
   	affichage(c,l);

      while (1)
	 	{}
    FermerGraphique();
    	 free(dec);
 
    return EXIT_SUCCESS;
}