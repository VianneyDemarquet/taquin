#Vianney
#Demarquet


taquin: affichage.o control.o menu.o main.o
		gcc affichage.o control.o menu.o main.o -o taquin -lgraph

affichage.o: affichage.c entete.h
		gcc -c affichage.c -o affichage.o -lgraph

control.o: control.c entete.h
		gcc -c control.c -o control.o -lgraph

menu.o: menu.c entete.h
		gcc -c menu.c -o menu.o -lgraph

main.o: main.c entete.h
		gcc -c main.c -o main.o -lgraph