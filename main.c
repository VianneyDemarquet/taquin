/*
Vianney
Demarquet
*/


#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "entete.h"

int main(void)
{
	unsigned int c, l;
	

   	printf("nombre de ligne\n");
   	scanf("%u",&l);
   	printf("nombre de colone\n");
   	scanf("%u",&c);

    dec=(struct image *) malloc(c*l*sizeof(struct image));
   pos=(struct position *) malloc(c*l*sizeof(struct position));
   	InitialiserGraphique();

    CreerFenetre(10,10,700,1000);

   	decoupage(c,l);
   	melange(c,l);
   	affichage(c,l);
    
    while(1)
    {
    clavier(c,l);
  }

    free(dec);
    FermerGraphique();
 
    return EXIT_SUCCESS;
}