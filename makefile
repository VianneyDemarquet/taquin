#Vianney
#Demarquet


taquin: affichage.o clavier.o main.o
		gcc affichage.o clavier.o main.o -o taquin -lgraph

affichage.o: affichage.c entete.h
		gcc -c affichage.c -o affichage.o -lgraph

clavier.o: clavier.c entete.h
		gcc -c clavier.c -o clavier.o -lgraph

main.o: main.c entete.h
		gcc -c main.c -o main.o -lgraph