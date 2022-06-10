CFLAGS = -Wall -std=gnu99 -pedantic -fsanitize=address -lm
CC = gcc

all: server client

server: src/server/server.c
	$(CC) src/server/server.c src/server/challenges.c -o server $(CFLAGS)

client: src/client/client.c
	$(CC) src/client/client.c -o client $(CFLAGS)

clean:
	rm -f server
	rm -f client

.PHONY: all server client clean