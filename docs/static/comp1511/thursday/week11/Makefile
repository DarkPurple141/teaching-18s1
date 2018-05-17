
CC=gcc
CFLAGS= -Wall -Werror -std=c99 -g

all: fruit_bot

fruit_bot: fruit_bot.o fruit_bot_input.o
fruit_bot.o: fruit_bot.c fruit_bot.h
fruit_bot_input.o: fruit_bot_input.c fruit_bot.h

clean:
	rm -f *.o fruit_bot
