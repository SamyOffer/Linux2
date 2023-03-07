
CFLAGS = -std=c11 -pedantic -Wvla -Wall -Werror -g -D_DEFAULT_SOURCE 
all : encrypt decrypt encryptPolybe

encryptPolybe : encryptPolybe.o cryptPolybe.o utils_v1.o
	cc $(CFLAGS) -o encryptPolybe encryptPolybe.o cryptPolybe.o utils_v1.o

# decryptPolybe : ...

cryptPolybe.o : cryptPolybe.h cryptPolybe.c
	cc $(CFLAGS) -c cryptPolybe.c

encryptPolybe.o : cryptPolybe.h utils_v1.h encryptPolybe.c
	cc $(CFLAGS) -c encryptPolybe.c

# decryptPolybe.o : 



encrypt : crypt.o encrypt.o utils_v1.o
	cc $(CFLAGS) -o encrypt crypt.o encrypt.o utils_v1.o

decrypt : crypt.o decrypt.o utils_v1.o
	cc $(CFLAGS) -o decrypt crypt.o decrypt.o utils_v1.o


crypt.o : crypt.h crypt.c
	cc $(CFLAGS) -c crypt.c

encrypt.o : crypt.h utils_v1.h encrypt.c
	cc $(CFLAGS) -c encrypt.c

decrypt.o : crypt.h utils_v1.h decrypt.c 
	cc $(CFLAGS) -c decrypt.c

utils_v1.o : utils_v1.h utils_v1.c
	cc $(CFLAGS) -c utils_v1.c




clean :
	rm *.o
	rm encrypt
	rm decrypt
	rm encryptPolybe
	rm decryptPolybe