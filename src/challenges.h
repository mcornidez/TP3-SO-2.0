#ifndef TP3_SO_CHALLENGES_H
#define TP3_SO_CHALLENGES_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#define CHALLENGES 12
#define MAXLEN 25

typedef int (*challenge) (int);

void gdbme();
int validateQuine(int n);
void normalGenerator(double mean, double stdDev);
void printChallengeQuestion(char * question);
int checkAnswer(int fd, char * correct);
int challenge1(int fd);
int challenge2(int fd);
int challenge3(int fd);
int challenge4(int fd);
int challenge5(int fd);
int challenge6(int fd) __attribute__ ((section (".RUN_ME")));
int challenge7(int fd);
int challenge8(int fd);
int challenge9(int fd);
int challenge10(int fd);
int challenge11(int fd);
int challenge12(int fd);


#endif //TP3_SO_CHALLENGES_H
