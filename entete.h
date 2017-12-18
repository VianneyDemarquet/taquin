/*
Vianney
Demarquet
*/


#ifndef ENTETE_H
#define ENTETE_H

struct image
{
	unsigned int x;
	unsigned int y;
	unsigned int xx;
	unsigned int yy;
	unsigned int pose;
};

struct position
{
	unsigned int x;
	unsigned int y;
};

struct image *dec;
struct position *pos;

/*affichage*/
int decoupage(int c, int l, int image);

void affichage(int c, int l,int image,int compteur);

void melange(int c, int l);

int modif(int x, int c, int l);

/*control*/
int control(int x, int c,int image);
int iclavier(void);
int isouris(void);
int nbsouris(void);
int nbclavier(void);

/*menu*/
int choisirimage(void);
int nbcolone(void);
int nbligne(void);

/*compteur*/
int compteur(int x, int comp, unsigned int yy);

/*efface*/
void clear(void);
#endif /*  ENTETE_H */