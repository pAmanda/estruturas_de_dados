#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
#define lesseq(A,B) ((A) <= (B))

void selectionsort(int *v, int left, int rigth) {

    for (int i = left; i < rigth; i++) {
        int min = i;
        for (int j = i + 1; j <= rigth; j++)
        {
            if(less(v[j], v[min])) {
                min = j;
            }
        }
        exch(v[i], v[min]);
    }
}

int main() {

    int *n = malloc(1000*sizeof(int));

    int i = 0;
    while (scanf("%d", &n[i]) != EOF) {
        ++i;
    }

    selectionsort(n, 0, i-1);

    for (int j = 0; j < i; j++)
    {
        if (j == i - 1) {
            printf("%d\n", n[j]);
        } else
        {
            printf("%d ", n[j]);
        }
        
    }
    


}