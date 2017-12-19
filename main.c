/*
Vianney
Demarquet
*/


#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "entete.h"

/*
cette fonction éfface l'affichage
*/
void clear(void)
{
  couleur coul;
  coul = CouleurParComposante(255, 255, 255);
  EffacerEcran(coul);
}

/*
cette fonction affiche le nombre de coup réalisé en incrémentant puis affichant
la varible compteur
qui est convertit pour pouvoir être afficher 
*/
int compteur(int x, int comp, unsigned int yy)
{
  char tab[4];
   if (x==1 && comp<1000)
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

/*
cette fonction permet la continuation du jeux, la création d'une nouvelle partie
ou le fonctionnement de la partie en coure celon les cas 
*/
int main(void)
{
  unsigned int c, l, yy;
  int x, image, comp, k=0;
  char nom[11];
  InitialiserGraphique();
  CreerFenetre(10,10,700,700);
  while (k<9)
  {
    k=0;
    comp=0;
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
    affichage(c,l,image,comp);
    while(k<8)
    {
      x=control(c,l,image);
      comp=compteur(x,comp,yy); 
      k=affichage(c,l,image,comp);
    }

    free(dec);
  }
    FermerGraphique();
 
    return EXIT_SUCCESS;
}