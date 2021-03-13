#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef char String[20];

void ordena_string(String *v, int l, int r) {

    for(int i = l + 1; i <= r; i++) {
        for (int j = i; j > l; j--) {
            if (strcmp(v[j - 1], v[j]) > 0) {
                String tmp;
                strcpy(tmp, v[j - 1]);
                strcpy(v[j -1], v[j]);
                strcpy(v[j], tmp);
            }
        }   
    }

}

int main() {

    String *vetor;
    int qtd;

    printf("Quantos elementos deseja ordenar?\n");
    scanf("%d", &qtd);

    vetor = malloc(qtd*sizeof(String));

    printf("Digite os elementos abaixo: \n");
    for (int i = 0; i < qtd; i++)
    {
        printf("%d)", i + 1);
        scanf("%s", vetor[i]);
    }

    system("clear");

    ordena_string(vetor, 0, qtd-1);

    printf("Elementos ordenados: \n");

    for (int i = 0; i < qtd; i++)
    {
        printf("%s\n", vetor[i]);
    } 
    
}