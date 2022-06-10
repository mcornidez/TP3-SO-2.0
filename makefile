CFLAGS = -Wall -std=gnu99 -pedantic -fsanitize=address -lm
CC = gcc

all: server client

server: src/server.c
	$(CC) src/server.c src/challenges.c -o server $(CFLAGS)

client: src/client.c
	$(CC) src/client.c -o client $(CFLAGS)

clean:
	rm -f server
	rm -f client

.PHONY: all server client clean