#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <termios.h>
#include <unistd.h>

pthread_t tid[7];

int health=300;
int hunger = 200;
int hygiene =100;
int food = 100;
int stok = 100;
int bath = 0;
int choice = 0;
char monster[] = "";

int mygetch(void)
{
struct termios oldt,
newt;
int ch;
tcgetattr( STDIN_FILENO, &oldt );
newt = oldt;
newt.c_lflag &= ~( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &newt );
ch = getchar();
tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
return ch;
}

	printf("Masukkan Nama Monster = ");
	scanf("%s",monster);
	while(stat){
    	if(choice != 51 && choice !=52){
			
	system("clear");	
	printf("Health : %d \nHunger : %d \nHygiene : %d \nFood left : %d\nBath will be ready in %d s\n",health,hunger,hygiene,food,bath);
	printf("Choices \n 1.Eat \n 2.Bath \n 3.Battle \n 4.Shop \n 5.Exit\n");
	//choice = getch();
	printf("Pilihan = ");
        }
    }

