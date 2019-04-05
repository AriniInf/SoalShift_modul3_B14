# SoalShift_modul3_B14

## SOAL 1

#### Membuat fungsi factorial untuk mencari nilai factorial dari nilai num, dan disimpan di variabel facto. Lalu hasil factorial dari semua input factorial dimasukkan ke array hasil.


```
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
