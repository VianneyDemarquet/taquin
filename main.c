/*
Vianney
Demarquet
*/


#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "entete.h"

void clear(void)
{
  couleur coul;
  coul = CouleurParComposante(255, 255, 255);
  EffacerEcran(coul);
}

int compteur(int x, int comp, unsigned int yy)
{
  char tab[4];
   if (x==1 && comp>=0 && comp<1000)
    {
      comp++;
      
      ChargerImage("./compteur.png",15, yy+21,0,0,30,20);
    }
    sprintf(tab,"%d",comp);
    EcrireTexte(20, yy+20, "nombre de coup : ", 1);
    DessinerRectangle(15, yy+21, 30, 20);
    EcrireTexte(20, yy+40, tab, 1);
    return comp;
}
int main(void)
{
  unsigned int c, l, yy;
  int x, image, comp=0;
  char nom[11];

    InitialiserGraphique();
    CreerFenetre(10,10,700,700);

    clear();
    image=choisirimage();

    clear();
    c=nbcolone();
    clear();
    l=nbligne();
    clear();

    dec=(struct image *) malloc(c*l*sizeof(struct image));
    pos=(struct position *) malloc(c*l*sizeof(struct position));

   	yy=decoupage(c,l,image);
   	melange(c,l);
    
    while(comp>=0)
    {
      affichage(c,l,image,comp);
      x=control(c,l,image);
      comp=compteur(x,comp,yy);   
    }

    free(dec);
    FermerGraphique();
 
    return EXIT_SUCCESS;
}