#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

//Usando mais memória
int separa(int *v, int l, int r) {

    int cpos;
    int tam = r - l + 1;
    int c = v[r];
    int *menores = malloc(sizeof(int)*tam);
    int *maiores = malloc(sizeof(int)*tam);
    
    int imenor = 0;
    int imaior = 0;
    for (int i = l; i < r; i++)
    {
       if (less(v[i], c)) {
           menores[imenor++] = v[i];
       } else {
           maiores[imaior++] = v[i];
       }
    }

    int i = l;

    for (int j = 0; j < imenor; j++)
    {
        v[i++] = menores[j];
    }

    v[i] = c;
    cpos = i;
    i++;

    for (int j = 0; i < imaior; j++)
    {
        v[i++] = maiores[j];
    }
    
    free(maiores);
    free(menores);
    return cpos;
    
}

//Usando menos memória e mais rápido
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

    clock_t begin = clock();
    int pos = separa_quick(v, 0, n-1);
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    for(int i = 0; i < n; i++)
    {
        printf("%d\n", v[i]);
    }

    printf("Posição pivô: %d\n", pos);

    printf("Tempo: %.20lf\n", time_spent);
    
}

