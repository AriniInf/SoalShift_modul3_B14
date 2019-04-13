# SoalShift_modul3_B14

## SOAL 1

#### Membuat fungsi factorial untuk mencari nilai factorial dari nilai num, dan disimpan di variabel facto. Lalu hasil factorial dari semua input factorial dimasukkan ke array hasil.


```c
void* factorial(void* arg)
{
    int* nump = (int*) arg;
    int num = *nump;
    int i;
    unsigned long long facto = 1;
    for( i=num; i>0; i--){
        facto = facto*i;
    }
    hasil[num] = facto;
}
```

#### Membuat Fungsi swap dan selectionSort untuk Menyortir inputan user dari yang paling kecil dengan metode selection sort

```c
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int size)
{
    int i, j;
    for (i = 0 ;  i < size;i++)
    {
        for (j = i ; j < size; j++)
        {
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}`

```

#### Pada Fungsi Main, membuat thread sebanyak n, dengan n adalah banyaknya argumen dikurangi 1. Lalu memanggil fungsi selectionSort dan mengoutputkan nilai factorial pada setiap threadnya. 


```c
int main(int argc, char *argv[])
{ 
    int n;
    n = argc-1;
    pthread_t tid[n];
    int i;
    int ar[n];
    for(i=0;i<n;i++){
       ar[i] = atoi(argv[i+1]);
    }
    for(i=0;i<n;i++){
        pthread_create(&tid[i],NULL,&factorial,&ar[i]);
    }
    for(i=0;i<n;i++){
        pthread_join(tid[i],NULL);
    }
    selectionSort(ar,n);
    for(i=0;i<n;i++){
        printf("%d! = %llu\n",ar[i],hasil[ar[i]]);
    }
    
}
```


## SOAL 3

```c
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
```
###### variabel tunggu untuk menunggu hingga tidak disable.
###### variabel bosen untuk menghitung apakah fitur Iraj Ayo Tidur atau Agmal Ayo Bangun sudah dijalankan lebih dari 3x atau belum
###### variabel status untuk mengecek status wake_up_agmal dan spirit_iraj.

###### Membuat variabel agmal dan iraj dengan tipe data orang.

###### Membuat Fungsi agmalBangun untuk mengecek fitur Agmal Ayo Bangun sudah dijalankan lebih dari 3x atau belum, jika sudah maka fitur iraj tidak bisa dijalankan. 
###### Fungsi irajTidur untuk mengecek fitur iraj Ayo Tidur atau sudah dijalankan 3x lebih atau belum,jika sudah maka fitur agmal tidak bisa digunakan.
###### Fungsi menu untuk menampilkan semua menu/fitur.
###### Fungsi allStatus untuk menampilkan wakeUp agmal dan Spirit_Iraj.
###### Fungsi agmalBosen untuk mendisable fitur iraj ketika sudah dijalankan 3x lebih. dan menunggu hingga 10 s, dan setelah 10 s maka fitur itu bisa kembali normal.
###### Fungsi irajBosen untuk mendisable fitur agmal ketika sudah dijalankan 3x lebih. dan menunggu hingga 10 s, dan setelah 10 s maka fitur itu bisa kembali normal.

## Soal 4

Membuat program C untuk menyimpan list proses yang ada di (ps -aux) sebanyak 10 list dengan ketentuan ketentuan yang ada, dengan cara multithreading. pertama tama kita membuat fungsi void mkdir untuk membuat file FolderProses1 dan FolderProses2, lalu selanjutnya membuat void touch untuk membuat file ber ekstensi txt, dan disimpan di FolderProses1 dan FolderProses2.

Setelah itu kita membuat fungsi untuk menyimpan proses yang ada di ps aux dan disimpan di file ber ekstensi txt yang tadi kita telah buat (SimpanProses1.txt dan SimpanProses2.txt) setelah itu kita kompres file ber ekstensi txt tersebut dengan nama KompresProses1 dan KompresProses2. Setelah dikompres, file yang berekstensi txt tadi harus hilang dari file FolderProses1 dan FolderProses2 maka dari itu kita menghapus file berektensi txt tadi dengan cara (rm) tetapi file .txt tadi tidak sepenuhnya hilang, karena sebenarnya file .txt itu telah di zip ke KompresProses1 dan KompresProses2.

Setelah membuat semua void untuk hal hal diatas, maka setelahnya kita membuat main untuk membuat thread untuk menjalankan void void tersebut yang mana kodingannya seperti yang ada di file soal4.c . setelah kita membuat thread dan membuat join thread agar berjalan secara bersamaan, kita membuat fungsi "iter" yang mana gunanya untuk menghitung selama 15 detik kedepan, setelah 15 detik, file .txt yang telah di zip akan di unzip di FolderProses1 dan FolderProses2.

## Soal 5

```c
static struct termios old, new;
/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      new.c_lflag |= ECHO; /* set echo mode */
  } else {
      new.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

    Fungsi berguna agar dapat mendekteksi key press (getch)
```

