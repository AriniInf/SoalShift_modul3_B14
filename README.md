# SoalShift_modul3_B14

## SOAL 1

#### Membuat fungsi factorial untuk mencari nilai factorial dari nilai num, dan disimpan di variabel facto. Lalu hasil factorial dari semua input factorial dimasukkan ke array hasil.


```void* factorial(void* arg)
{
    int* nump = (int*) arg;
    int num = *nump;
    int i;
    unsigned long long facto = 1;
    for( i=num; i>0; i--){
        facto = facto*i;
    }
    hasil[num] = facto;
}```

#### Membuat Fungsi swap dan selectionSort untuk Menyortir inputan user dari yang paling kecil dengan metode selection sort

```void swap(int *a, int *b)
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


```int main(int argc, char *argv[])
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
    
}```


