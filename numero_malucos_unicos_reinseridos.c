#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void merge(int *V, int l, int m, int r)
{
    int *R = malloc(sizeof(int)*(r-l+1));
    int i=l,j=m+1,k=0;  
    while(i<=m && j<=r)
    {
      if(lesseq(V[i],V[j]))
        R[k++]=V[i++];
      else
        R[k++]=V[j++];
    }   
    while(i<=m)
        R[k++]=V[i++];
    while(j<=r)
        R[k++]=V[j++];  
    k=0;
    for(i=l;i<=r;i++)
      V[i]=R[k++];
    free(R);
}

void merge_sort(int *V, int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  merge_sort(V,l,meio);
  merge_sort(V,meio+1,r);
  merge(V,l,meio,r);
}

//Premissa: A e B já estão ordenados
int *intercala(int *a, int la, int ra, 
            int *b, int lb, int rb) {

    int ta = (ra - la + 1);
    int tb = (rb - lb + 1);

    int *c = malloc(sizeof(int)*(ta + tb));
    int lc = 0;

    int ia = la;
    int ib = lb;
    int ic = 0;

    while (ia <= ra && ib <= rb)
    {
        if(lesseq(a[ia], b[ib])){
            c[ic++] = a[ia++];
        } else
        {
            c[ic++] = b[ib++];
        }
        
    }

    while (ia <= ra) {
        c[ic++] = a[ia++];

    }

    while (ib <= rb)
    {
        c[ic++] = b[ib++];
    }
    
    return c;
}

// Busca recursiva
int buscabinaria(int num, int *v, int l, int r)
{
    if(l>r) return -1;
    int meio=(l+r)/2;
    if(less(v[meio],num))
            return buscabinaria(num,v,meio+1,r);
    else if(lesseq(v[meio],num))
            return meio;
    else
            return buscabinaria(num,v,l,meio-1);
}

int main() {
    
    int v[200000];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    merge_sort(v, 0, n-1);

    int novoi = 0;

    //Tira os elementos repetidos
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[novoi]) {
            v[++novoi] = v[i];
        }
        
    }

    int novor = novoi;

    if ((novor+1) % 2 != 0) {
        v[++novor] = 1000000000;
    }

    int nmu[66000];
    int nmui = -1;
    for (int i = 0; i < novor; i+=2)
    {
        nmu[++nmui] = v[i] + v[i+1];
        if (buscabinaria(nmu[nmui], v, 0, novor) != -1) {
            nmui--;
        }
    }

    int *c = intercala(v, 0, novor, nmu, 0, nmui);

    for (int i = 0; i <= (novor + nmui + 1); i+=4) {
        printf("%d\n", c[i]);
    }

    printf("Elementos: %d\n", (novor + nmui + 2));

}