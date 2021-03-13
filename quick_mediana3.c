#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

// Essa quicksort mediana de 3 é melhor que a "mediana3_diferente"
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

    if (r <= l) return;

    //Elementos da mediana 
    //v[r], v[l], v[(l+r)/2]

    cmpexch(v[(l+r)/2], v[r]);
    cmpexch(v[l], v[(l+r)/2]);
    cmpexch(v[r], v[(l+r)/2]);

    j = separa_quick(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

int main() {

    int n;

    scanf("%d", &n);

    int v[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    quicksort(v, 0, n-1);

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