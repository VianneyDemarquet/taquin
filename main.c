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
  unsigned int c, l, yy;
  int x, compteur=0;
  couleur coul;
  char tab[4], nom[11];
	char * w=NULL;
    coul = CouleurParComposante(255, 255, 255);

    w=nom;

    /*seg fault*/
    //ChoisirCouleurDessin(coul);



   	printf("nombre de ligne\n");
   	scanf("%u",&l);
   	printf("nombre de colone\n");
   	scanf("%u",&c);

    dec=(struct image *) malloc(c*l*sizeof(struct image));
    pos=(struct position *) malloc(c*l*sizeof(struct position));
   	InitialiserGraphique();

    CreerFenetre(10,10,700,1000);

    EffacerEcran(coul);
    w=choisirimage();


   	yy=decoupage(c,l);
   	melange(c,l);
   	affichage(c,l);
    
    while(1)
    {
    x=control(c,l);
    if (x==1 && compteur<1000)
    {
      compteur++;
      EcrireTexte(20, yy+20, "nombre de coup : ", 1);
      sprintf(tab,"%d",compteur);
      DessinerRectangle(20, yy+21, 20, 20);
      EcrireTexte(20, yy+40, tab, 1);
    }
    }

    free(dec);
    FermerGraphique();
 
    return EXIT_SUCCESS;
}