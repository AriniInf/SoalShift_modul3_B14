#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

pthread_t tid[4]; //inisialisasi array untuk menampung thread dalam kasus ini ada 2 thread


void* bikinfolder()
{
	system("mkdir /home/gipen/Documents/FolderProses1 | mkdir /home/gipen/Documents/FolderProses2");
}

void* bikintxt()
{
	system("touch /home/gipen/Documents/FolderProses1/SimpanProses1.txt | touch /home/gipen/Documents/FolderProses2/SimpanProses2.txt");
}

void* listfolder()
{
	system("ps -aux | tail -10 >> /home/gipen/Documents/FolderProses1/SimpanProses1.txt");
	system("ps -aux | head -10 >> /home/gipen/Documents/FolderProses2/SimpanProses2.txt");
}

void* kompress()
{
	system("zip -j /home/gipen/Documents/FolderProses1/KompresProses1.zip /home/gipen/Documents/FolderProses1/SimpanProses1.txt");
	system("zip -j /home/gipen/Documents/FolderProses2/KompresProses2.zip /home/gipen/Documents/FolderProses2/SimpanProses2.txt");
}

void* hapusfolder()
{
	system("rm /home/gipen/Documents/FolderProses1/SimpanProses1.txt");
	system("rm /home/gipen/Documents/FolderProses2/SimpanProses2.txt");
}

void* ekstrak()
{
	system("unzip -o /home/gipen/Documents/FolderProses1/KompresProses1.zip -d /home/gipen/Documents/FolderProses1");
	system("unzip -o /home/gipen/Documents/FolderProses2/KompresProses2.zip -d /home/gipen/Documents/FolderProses2");
}


int main(void)
{
	int iter;
	int err1,err2,err3,err4,err5,err6;
	pthread_t tid1,tid2,tid3,tid4,tid5,tid6;
		err1=pthread_create(&tid1,NULL,&bikinfolder,NULL);
		pthread_join(tid1,NULL);
		err2=pthread_create(&tid2,NULL,&bikintxt,NULL);
		pthread_join(tid2,NULL);
		err3=pthread_create(&tid3,NULL,&listfolder,NULL);
		pthread_join(tid3,NULL);
		err4=pthread_create(&tid4,NULL,&kompress,NULL);
		pthread_join(tid4,NULL);
		err5=pthread_create(&tid5,NULL,&hapusfolder,NULL);
		pthread_join(tid5,NULL);

		printf("Menunggu 15 detik untuk mengekstrak kembali\n");
		for(iter=1;iter<=15;iter++)
		{
			printf("%d\n",iter);
			sleep(1);
		}

		err6=pthread_create(&tid6,NULL,&ekstrak,NULL);
		pthread_join(tid6,NULL);
	return 0;
}
