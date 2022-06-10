#include "challenges.h"

int challenge1(int fd){
    printf("Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo. \nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel. Además tendrán que investigar otras preguntas para responder durante la defensa. El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta. Además, deberán implementar otro programa para comunicarse conmigo. Deberán estar atentos a los easter eggs.\nPara verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido' \n");
    printChallengeQuestion("¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n");
    return checkAnswer(fd, "entendido\n");
}

int challenge2(int fd){
    printf("The Wire S1E5\n'5295 888 6288'\n");
    printChallengeQuestion("¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n");
    return checkAnswer(fd, "itba\n");
}

int challenge3(int fd){
    printf("https://ibb.co/tc0Hb6w\n");
    printChallengeQuestion("¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n");
    return checkAnswer(fd, "M4GFKZ289aku\n");
}

int challenge4(int fd){
    printf("EBADF...\n");
    char * message = ".........................................La respuesta es fk3wfLCm3QvS\n\0\0\0";
    write(13, message, strlen(message));
    printChallengeQuestion("¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n");
    return checkAnswer(fd, "fk3wfLCm3QvS\n");
}

int challenge5(int fd){
    printf("respuesta = strings:131\n");
    printChallengeQuestion("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n");
    return checkAnswer(fd, "too_easy\n");
}

int challenge6(int fd){
    printf(".init .plt.got .plt.sec .text ? .fini .rodata\n");
    printChallengeQuestion("Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?\n");
    return checkAnswer(fd, ".RUN_ME\n");
}

int challenge7(int fd){
    printf("Filter error:\n\n");
    char * answer = "La respuesta es K5n2UFfpFMUN";
    int len = strlen(answer);
    int dirtyBytes = 0;
    for(int i = 0; i < len; i++){
        // Imprimo entre 0 y 15 valores basura entre valores "reales"
        dirtyBytes = (rand() % 16);
        for(int j = 0; j < dirtyBytes; j++){
            char garbage[2] = {0};
            garbage[0] = ((rand() % (126-32+1)) + 32);
            write(2, garbage, 1); 
        }
        write(1, answer + i, 1);
    }
    printf("\n");
    printChallengeQuestion("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n");
    return checkAnswer(fd, "K5n2UFfpFMUN\n");
}

int challenge8(int fd){
    printf("La respuesta es \x1B[30;40m BUmyYq5XxXGt \x1B[0m\n");
    printChallengeQuestion("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?\n");
    return checkAnswer(fd, "BUmyYq5XxXGt\n");
}

int challenge9(int fd){
    printf("Latexme\nSi\n \\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\n entonces\n y =\n");
    printChallengeQuestion("Sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n");
    return checkAnswer(fd, "u^v\n");
}

int challenge10(int fd){
    printf("quine\n\n");
    printChallengeQuestion("¿Cuáles son las características del protocolo SCTP?\n");
    int n = checkAnswer(fd, "chin_chu_lan_cha\n");
    return validateQuine(n);
}

int challenge11(int fd){
    printf("b gdbme y encontrá el valor mágico\nENTER para reintentar.");
    gdbme();
    printChallengeQuestion("¿Qué es un RFC?\n");
    return checkAnswer(fd, "gdb_rules\n");
}

void gdbme(){
    if((getpid())== 0x12345678){
        printf("\nLa respuesta es gdb_rules\n\n");
    }
    else{
        printf("Intente nuevamente.\n\n");
    }
}

int challenge12(int fd){
    printf("Me conoces\n");
    for(int i = 0; i < 100; i++) {
        normalGenerator(0, 1);
        if ((i % 5 == 0) && (i != 0))
            printf("\n");
    }
    printChallengeQuestion("¿Fue divertido?\n");
    return checkAnswer(fd, "normal\n");
}


/* code borrowed from ftp://ftp.taygeta.com/pub/c/boxmuller.c */
/* boxmuller.c           Implements the Polar form of the Box-Muller
                         Transformation
                      (c) Copyright 1994, Everett F. Carter Jr.
                          Permission is granted by the author to use
			  this software for any application provided this
			  copyright notice is preserved.
*/
int validateQuine(int n){
    if(n == 0){
        return n;
    }
    else{
        int auxVar = system("gcc quine.c -o quine");
        if(auxVar !=  0){
            // 0 --> "No shell is available" (man system)
            printf("\n\nIntentelo nuevamente.\n");
        }
        if(auxVar == 0){
            printf("\n\nHan creado de manera correcta un programa quine.c . Veamos si realiza lo esperado.\n\n");
            int diffInFiles = system("./quine | diff - quine.c"); // " If a FILE is '-', read standard input." (man diff)
            printf("\n\n");
            if(diffInFiles != 0){
                printf("\n\ndiff encontro diferencias.\n\nIntentelo nuevamente\n");
            }
            if(diffInFiles == 0){
                printf("\nLa respuesta es chin_chu_lan_cha\n");
            }
            system("rm quine");
        }
        sleep(5);
        return n;
    }
}

void normalGenerator(double mean, double stdDev){
    double x1, x2, w, _y1;
    static double y2;
    static int use_last = 0;

    if (use_last)		        /* use value from previous call */{
        _y1 = y2;
        use_last = 0;
    }
    else{
        do {
            x1 = 2.0 * drand48() - 1.0;
            x2 = 2.0 * drand48() - 1.0;
            w = x1 * x1 + x2 * x2;
        } while ( w >= 1.0 );

        w = sqrt( (-2.0 * log( w ) ) / w );
        _y1 = x1 * w;
        y2 = x2 * w;
        use_last = 1;
    }

    double result = ( mean + _y1 * stdDev );
    printf("%.6f  ", result);
}

void printChallengeQuestion(char * question){
    printf("-----------------------------------\n\n");
    printf("----- PARA INVESTIGAR ----- \n");
    printf("%s", question);
}

int checkAnswer(int fd, char * correct){
    char buffer[MAXLEN] = {0};
    int n = read(fd, buffer, sizeof(buffer));
    if (n <= 0) {
        printf("Error while reading. Now closing execution.\n");
        exit(1);
    }
    return strcmp(buffer, correct);

}
