#include "client.h"

/* Basado en https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/ */

int main(){
    int sockfd;
    struct sockaddr_in servaddr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed.\n");
        exit(1);
    }
    else
        printf("Socket successfully created.\n");

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection with the server failed.\n");
        exit(1);
    }
    else
        printf("Connected to the server.\n");

    chat(sockfd);

    close(sockfd);
}

void chat(int sockfd){
    char buff[MAX] = {0};
    int n;
    char c;
    printf("rta: ");
    while ((c = getchar()) != EOF) {
        n = 0;
        printf("rta: ");
        while (c != '\n' && c != EOF) {
            buff[n++] = c;
            c = getchar();
        }
        buff[n++] = '\n';
        buff[n] = 0;
        
        write(sockfd, buff, n);
        if (c == EOF)
            exit(0);
    }
    exit(0);
}
