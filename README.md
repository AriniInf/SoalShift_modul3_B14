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
variabel tunggu untuk menunggu hingga tidak disable.
variabel bosen untuk menghitung apakah fitur Iraj Ayo Tidur atau Agmal Ayo Bangun sudah dijalankan lebih dari 3x atau belum
variabel status untuk mengecek status wake_up_agmal dan spirit_iraj.

Membuat variabel agmal dan iraj dengan tipe data orang.

Membuat Fungsi agmalBangun untuk mengecek fitur Agmal Ayo Bangun sudah dijalankan lebih dari 3x atau belum, jika sudah maka fitur iraj tidak bisa dijalankan. 
Fungsi irajTidur untuk mengecek fitur iraj Ayo Tidur atau sudah dijalankan 3x lebih atau belum,jika sudah maka fitur agmal tidak bisa digunakan.
Fungsi menu untuk menampilkan semua menu/fitur.
Fungsi allStatus untuk menampilkan wakeUp agmal dan Spirit_Iraj.
Fungsi agmalBosen untuk mendisable fitur iraj ketika sudah dijalankan 3x lebih. dan menunggu hingga 10 s, dan setelah 10 s maka fitur itu bisa kembali normal.
Fungsi irajBosen untuk mendisable fitur agmal ketika sudah dijalankan 3x lebih. dan menunggu hingga 10 s, dan setelah 10 s maka fitur itu bisa kembali normal.




