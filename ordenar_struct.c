#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct registro
{
    int aa;
    char *bb;
} Registro;

void ordena_int(Registro *v, int l, int r) {
    for (int i = l + 1; i <= r; i++)
    {
        for (int j = i; j > l; j--)
        {
            if(v[j - 1].aa > v[j].aa) {
                Registro tmp;
                tmp.bb = malloc(20*sizeof(char));
                strcpy(tmp.bb, v[j - 1].bb);
                tmp.aa = v[j - 1].aa;

                strcpy(v[j - 1].bb, v[j].bb);
                v[j - 1].aa = v[j].aa;

                strcpy(v[j].bb, tmp.bb);
                v[j].aa = tmp.aa;

            }
        }
        
    }
    
}

void ordena_string(Registro *v, int l, int r) {

    for(int i = l + 1; i <= r; i++) {
        for (int j = i; j > l; j--) {
            if (strcmp(v[j - 1].bb, v[j].bb) > 0) {
                Registro tmp;
                tmp.bb = malloc(20*sizeof(char));
                strcpy(tmp.bb, v[j - 1].bb);
                tmp.aa = v[j - 1].aa;

                strcpy(v[j - 1].bb, v[j].bb);
                v[j - 1].aa = v[j].aa;

                strcpy(v[j].bb, tmp.bb);
                v[j].aa = tmp.aa;

            }
        }   
    }

}

int main() {

    Registro *v;
    int qtd;

    printf("Quantos elementos deseja ordenar?\n");
    scanf("%d", &qtd);

    v = malloc(qtd*sizeof(Registro));

    printf("Digite os elementos abaixo: \n");
    for (int i = 0; i < qtd; i++)
    {
        printf("%d - aa)", i + 1);
        scanf("%d", &v[i].aa);

        printf("%d - bb)", i + 1);
        v[i].bb = malloc(20*sizeof(char));
        scanf("%s", v[i].bb);
    }

    system("clear");

    printf("Elementos ordenados por aa:\n");
    ordena_int(v, 0, qtd-1);
    for (int i = 0; i < qtd; i++)
    {
        printf("%d\n", v[i].aa);
        printf("%s\n", v[i].bb);
    }

    printf("\n\nElementos ordenados por bb:\n");
    ordena_string(v, 0, qtd-1);
    for (int i = 0; i < qtd; i++)
    {
        printf("%d\n", v[i].aa);
        printf("%s\n", v[i].bb);
    }

}