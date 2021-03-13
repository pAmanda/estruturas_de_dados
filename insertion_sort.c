#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
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

int main() {

    int *n = malloc(50000*sizeof(int));

    int i = 0;
    while (scanf("%d", &n[i]) != EOF) {
        ++i;
    }

    insertionsort(n, 0, i-1);

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