#ifndef TP3_SO_SERVER_H
#define TP3_SO_SERVER_H

#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <math.h> //Compile with -lm
#include "challenges.h"
#define MAX 80
#define PORT 8080
#define WAIT_TIME 5
#define SA struct sockaddr


void beginGame(int sockfd);

#endif //TP3_SO_SERVER_H
