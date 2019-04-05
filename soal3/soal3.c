#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    int tunggu, bosen, status;
} Orang;


Orang *agmal, *iraj;
int isRunning;
char msg[100];

void* agmalBosen(void* x);
void* irajBosen(void* x);
void allStatus();
void menu();
void agmalBangun();
void irajTidur();

pthread_mutex_t mtx;

int main(){
    agmal = (Orang*) malloc(sizeof(Orang));
    iraj  = (Orang*) malloc(sizeof(Orang));

    agmal->status = 0;
    agmal->bosen = 0;
    agmal->tunggu = 0;

    iraj->status = 100;
    iraj->bosen = 0;
    iraj->tunggu = 0;
    
    isRunning = 1;

    pthread_t tid[2];

    pthread_create(&tid[0], NULL, agmalBosen, NULL);
    pthread_create(&tid[1], NULL, irajBosen, NULL);

    while(isRunning){
        system("clear");
        menu();
    }

    system("clear");
    printf("%s\n", msg);
    pthread_cancel(tid[0]);
    pthread_cancel(tid[1]);

    free(agmal);
    free(iraj);

    return 0;
}

void menu(){
    char key;

    printf("[msg] %s\n\n", msg);
    printf("FITUR\n");
    printf("1. All Status\n");
    printf("2. Agmal Ayo Bangun %d %d %d\n", agmal->status, agmal->bosen, agmal->tunggu);
    printf("3. Iraj Ayo Tidur %d %d %d\n", iraj->status, iraj->bosen, iraj->tunggu);
    printf("Pilih > ");
    scanf("%c", &key);
    getchar();
    memset(msg, 0, sizeof(msg));
    switch(key){
        case '1':
            allStatus();
            break;
        case '2':
            agmalBangun();
            break;
        case '3':
            irajTidur();
            break;
        default:
            break;
    }
}

void allStatus(){
    system("clear");
    printf("ALL STATUS\n");
    printf("Agmal WakeUp_Status = %d\n", agmal->status);
    printf("Iraj Spirit_Status = %d\n", iraj->status);
    printf("Enter untuk kembali");
    getchar();
}

void agmalBangun(){
    if(agmal->bosen < 3 && agmal->tunggu==0){
        agmal->bosen++;
        agmal->status+=15;
        strcpy(msg, "Agmal ayo bangun!");
    }
    else if(agmal->bosen>=3){
        char buffer[100];
        if(iraj->tunggu==0)
            iraj->tunggu = 10;
        sprintf(buffer, "Iraj Ayo Tidur disabled %d s", iraj->tunggu);
        strcpy(msg, buffer);
        return;
    }
    if(agmal->status>=100){
        isRunning = 0;
        strcpy(msg, "Agmal Terbangun,mereka bangun pagi dan berolahraga");
    }
}

void irajTidur(){
    if(iraj->bosen <3 && iraj->tunggu==0){
        iraj->bosen++;
        iraj->status-=20;
        strcpy(msg, "Iraj ayo tidur!");
    }
    else if(iraj->bosen>=3){
        char buffer[100];
        if(agmal->tunggu==0)
            agmal->tunggu = 10;
        sprintf(buffer, "Fitur Agmal Ayo Bangun disabled %d s", agmal->tunggu);
        strcpy(msg, buffer);
        return;
    }

    if(iraj->status<=0){
        isRunning=0;
        strcpy(msg, "Iraj ikut tidur, dan bangun kesiangan bersama Agmal");
    }
}

void* agmalBosen(void* x){
    while(1){
        if(agmal->tunggu>0){
            agmal->tunggu--;
            if(agmal->tunggu==0)
                iraj->bosen = 0;
            sleep(1);
        }
    }
    return NULL;
}

void* irajBosen(void* x){
    while(1){
        if(iraj->tunggu>0){
            iraj->tunggu--;
            if(iraj->tunggu==0)
                agmal->bosen = 0;
            sleep(1);
        }
    }
    return NULL;
}