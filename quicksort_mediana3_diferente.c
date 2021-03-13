#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertionsort(int *v, int left, int rigth) {

    for(int i = rigth; i > left; i--) {
        cmpexch(v[i - 1], v[i]); 
    }

    for (int i = left + 2; i <= rigth; i++)
    {
        int j = i;
        int tmp = v[j];
        while (less(tmp, v[j - 1]))
        {
            v[j] = v[j-1];
            j--;
        }

        v[j] = tmp;
        
    }
    
}

int separa_quick(int *v, int l, int r) {

    int c = v[r];
    int j = l;
    for (int k = l; k < r; k++)
    {
        if (less(v[k], c)) {
            exch(v[k], v[j]);
            j++;
        }
    }

    exch(v[j], v[r]);
    
    return j;
}

void quicksort(int *v, int l, int r) {
    int j;

    if (l-r<=32) { //O uso do 32 foi arbitrário. Fazer o teste para saber o melhor
        return;
    }

    //Elementos da mediana 
    //v[r], v[l], v[(l+r)/2]

    exch(v[(l+r)/2], v[r-1])

    cmpexch(v[l], v[r-1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r-1], v[r]);

    j = separa_quick(v, l-1, r-1);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

void sort(int *v, int l, int r) {
    quicksort(v, l, r); 
    insertionsort(v, l, r); //melhor algoritimo para coisas pequenas

}

int main() {

    int n;

    scanf("%d", &n);

    int v[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    sort(v, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        printf("%d", v[i]);

        if (i < n-1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    
}