#ifndef TP3_SO_CLIENT_H
#define TP3_SO_CLIENT_H

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void chat(int sockfd);

#endif //TP3_SO_CLIENT_H
