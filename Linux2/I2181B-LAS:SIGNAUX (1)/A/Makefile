CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

ALL= exo1

all: $(ALL)

exo1: exo1.o utils_v2.o
	gcc $(CFLAGS) -o exo1 exo1.o utils_v2.o

exo1.o: exo1.c utils_v2.h
	gcc $(CFLAGS) -c exo1.c

utils_v2.o: utils_v2.c utils_v2.h
	gcc $(CFLAGS) -c utils_v2.c

clean:
	rm -f *.o
	rm -f $(ALL)