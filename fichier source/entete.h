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


/*affichage*/
int decoupage(int c, int l, int image,struct image *dec, struct position *pos);

int affichage(int c, int l,int image,int compteur,struct image *dec, struct position *pos);

void melange(int c, int l,struct image *dec, struct position *pos);

int modif(int x, int c, int l,struct image *dec, struct position *pos);

/*control*/
int control(int c, int l,int image,struct image *dec, struct position *pos);

int iclavier(void);
int isouris(void);

int nbsouris(void);
int nbclavier(void);

int menuclavier(void);
int menusouris(void);

/*menu*/
int choisirimage(void);
int nbcolone(void);
int nbligne(void);
int fin(int yy,int comp);

/*compteur*/
int compteur(int x, int comp, unsigned int yy);

/*efface*/
void clear(void);
#endif /*  ENTETE_H */