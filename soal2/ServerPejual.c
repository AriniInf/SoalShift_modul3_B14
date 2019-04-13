#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/shm.h>
#define PORT 8080

int *stock;
int shmid;

int server_fd, new_socket, valread;
struct sockaddr_in address;
int opt = 1;
int addrlen = sizeof(address);

void *outputFunction(void *argv){
    while(1){
        printf("%d\n", *stock);
        sleep(5);
    }
}
void *processFunction(void *argv){
    char buffer[1024] = {0};
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        shmdt(stock);
        shmctl(shmid, IPC_RMID, NULL);
        exit(EXIT_FAILURE);
    }
    while(1){
        memset(buffer, '\0', sizeof(buffer));
        valread = recv(new_socket, buffer, 1024, 0);
        
        if(strcmp(buffer, "tambah") == 0){
            printf("nambah he\n");
            *stock += 1;
        }
    }
}


int main() {
    key_t key = 4242;
    shmid = shmget(key, sizeof(int), IPC_CREAT | 0777);
    stock = shmat(shmid, NULL, 0);
    
    *stock = 0;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    pthread_t processthread, outputthread;

    if(pthread_create(&outputthread,NULL,outputFunction,NULL)){
        printf("failed\n");
    }

    if(pthread_create(&processthread,NULL, processFunction,NULL)){
        printf("failed\n");
    }

    pthread_join(outputthread, NULL);
    pthread_join(processthread, NULL);
    return 0;
}
