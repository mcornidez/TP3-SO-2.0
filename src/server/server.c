#include "server.h"

challenge challenges[CHALLENGES] = {&challenge1, &challenge2, &challenge3, &challenge4, &challenge5,
                                          &challenge6, &challenge7, &challenge8, &challenge9, &challenge10,
                                          &challenge11, &challenge12};


int main(){
    /*
     * Inspirado en la implementación que se encuentra en 
     * 'https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/'
     */
    int sockfd;
    struct sockaddr_in servaddr;
    printf("Creating socket...\n");
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Error creating socket. Now closing execution.\n");
        exit(1);
    }
    else
        printf("Socket created successfully.\n");

    // https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    printf("Attempting to bind...\n");
    if((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) == -1){
        printf("Error binding socket. Now closing execution.\n");
        exit(1);
    }
    else
        printf("Bind done successfully.\n");

    printf("Attempting to listen...\n");
    if((listen(sockfd, 5)) != 0){
        printf("Listen failed. Now closing execution.\n");
        exit(1);
    }
    else
        printf("Server now listening.\n");

    struct sockaddr_in cli;
    socklen_t len = sizeof(cli);

    int connectionFd = accept(sockfd, (SA*)&cli, &len);

    if(connectionFd < 0){
        printf("Could not accept client. Now closing execution.\n");
        exit(1);
    }
    else
        printf("Server accepted client's connection. Communication is now available.\n");

    beginGame(connectionFd);

    close(sockfd);

    return 0;
}

void beginGame(int sockfd){
    int nChallenge = 0;

    while(nChallenge < CHALLENGES){
        system("clear");
        printf("------------- DESAFIO -------------\n");

        if(challenges[nChallenge](sockfd) == 0)
            nChallenge++;
        else{
            printf("Respuesta incorrecta\n");
            sleep(WAIT_TIME);
        }

        printf("\n\n");
    }
    printf("¡Felicitaciones! Finalizaste los desafíos. Ahora tenes que seguir el legajo, e implementar el server por tu cuenta.\n");
}
