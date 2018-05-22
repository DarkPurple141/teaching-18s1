
CC=gcc
CFLAGS= -Wall -Werror -std=c99 -g

all: list

list: list.o lib.o
list.o: list.c list.h
lib.o: lib.c list.h

clean:
	rm -f *.o list
