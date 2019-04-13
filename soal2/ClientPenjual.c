#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/shm.h>
#define PORT 8080

char buffer[1024] = {0};
int sock = 0, valread;

void *processFunction(void *argv){
    char car[100];
    while(1){
        scanf("%s", car);
        send(sock , car , strlen(car) , 0 );
    }
}


int main() {
    struct sockaddr_in address;
    struct sockaddr_in serv_addr;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    pthread_t processthread, outputthread;

    if(pthread_create(&processthread,NULL, processFunction,NULL)){
        printf("failed\n");
    }
    pthread_join(processthread, NULL);
    return 0;
}

