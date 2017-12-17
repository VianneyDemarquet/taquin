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
void decoupage(int c, int l);

void affichage(int c, int l);

void melange(int c, int l);

void modif(int x, int c, int l);

/*control*/
void changement(int x, int c);

#endif /*  ENTETE_H */