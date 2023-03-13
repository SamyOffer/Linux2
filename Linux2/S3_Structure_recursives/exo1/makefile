# Gestion de bibliothèque

CFLAGS=-std=c11 -pedantic -Wvla -Wall -Werror -D_DEFAULT_SOURCE -g

pile.o : pile.c pile.h
	gcc $(CFLAGS) -c pile.c	

testPile.o : pile.h testPile.c 
	gcc $(CFLAGS) -c testPile.c	

utils_v1.o: utils_v1.c utils_v1.h
	gcc $(CFLAGS) -c utils_v1.c

testPile : testPile.o pile.o utils_v1.o
	gcc $(CFLAGS) -o testPile testPile.o pile.o utils_v1.o
