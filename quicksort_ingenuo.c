#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

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
        printf("%d\n", v[i]);
    }
    
}