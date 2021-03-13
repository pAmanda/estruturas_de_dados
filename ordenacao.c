#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void bubllesort(Item *v, int left, int right) {

    int comp = 0;
    int operation = 0;

    for (int i = left; i < right; i++) {
        for (int j = left + 1; j <= right; j++)
        {
            cmpexch(v[j - 1], v[j]);
            ++comp;
            ++operation;
        }
        
    }

    printf("Quantidade de comparações: %d\n", comp);
    printf("Quantidade de trocas: %d\n", operation);

}

void selectionsort(Item *v, int left, int rigth) {

    int comp = 0;
    int operation = 0;

    for (int i = left; i < rigth; i++) {
        int min = i;
        for (int j = i + 1; j <= rigth; j++)
        {
            ++comp;
            if(less(v[j], v[min])) {
                min = j;
                ++operation;
            }
        }
        exch(v[i], v[min]);
        ++operation;
    }

    printf("Quantidade de comparações: %d\n", comp);
    printf("Quantidade de trocas: %d\n", operation);
}

void insertionsortsimples(Item *v, int left, int rigth) {

    int comp = 0;
    int operation = 0;

    for(int i = rigth; i > left; i--) {
        ++comp;
        ++operation;
        cmpexch(v[i - 1], v[i]); //coloca o menor elemento no início do vetor, no índice left;
    }

    for (int i = left + 2; i <= rigth; i++)
    {
        int j = i;
        Item tmp = v[j];
        ++comp;
        while (less(tmp, v[j - 1]))
        {
            v[j] = v[j-1];
            j--;
            ++operation;
        }
        ++operation;
        v[j] = tmp;
        
    }


    printf("Quantidade de comparações: %d\n", comp);
    printf("Quantidade de trocas: %d\n", operation);
    

}

void insertionsort(Item *v, int left, int rigth) {

    int comp = 0;
    int operation = 0;

    for(int i = left + 1; i<= rigth; i++) {
        for (int j = i; j > left; j--) {
            cmpexch(v[j - 1], v[j]);
            ++comp;
            ++operation;
        }
        
    }

    printf("Quantidade de comparações: %d\n", comp);
    printf("Quantidade de trocas: %d\n", operation);

}

void printresult(Item *v, int tamanho, double time) {
    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++)

    {
        printf("%d", v[i]);
        if (i != tamanho -1) {
            printf(", ");
        } else {
            printf("\n");   
        }
    }
    printf("Tempo: %.2lf\n", time);
}

int main() {

    int tamanho;
    int opcao;
    int is_rand;
    srand(time(NULL)); 

    printf("Qual o tamanho do vetor você deseja ordenar?\n");
    scanf("%d", &tamanho);

    Item *v=malloc(tamanho*sizeof(Item));

    printf("Deseja gerar números randômicos? Digite 1 para SIM e 0 para NÃO. \n");
    scanf("%d", &is_rand);

    if (is_rand) {
        for (int i = 0; i < tamanho; i++)
        {
            v[i] = rand();
        }
    } else {
        printf("Digite as entradas do vetor: \n");
        for (int i = 0; i < tamanho; i++)
        {
            printf("%d) ", i+1);
            scanf("%d",&v[i]);
            printf("\n");
        }
    }

    system("clear");
    
    printf("Qual algorítimo de ordenação você deseja usar? \n\n");
    printf("1 - Bubblesort \n"); 
    printf("2 - Selectionsort \n"); 
    printf("3 - Insertionsortsimples \n"); 
    printf("4 - Insertionsort \n"); 
    printf("5 - Todos \n"); 

    scanf("%d", &opcao);

    system("clear");

    clock_t begin;
    clock_t end;
    double time_spent;

    switch (opcao)
    {
    case 1:
        printf("Bubblesort: \n");
        begin = clock();
        bubllesort(v, 0, tamanho-1);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printresult(v, tamanho, time_spent);
        break;
    case 2:
        printf("Selectionsort: \n");
        begin = clock();
        selectionsort(v, 0, tamanho-1);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printresult(v, tamanho, time_spent);
        break;
    case 3:
        printf("Insertionsortssimples: \n");
        begin = clock();
        insertionsortsimples(v, 0, tamanho-1);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printresult(v, tamanho, time_spent);
        break;
    case 4:
        printf("Insertionsort: \n");
        begin = clock();
        insertionsort(v, 0, tamanho-1);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printresult(v, tamanho, time_spent);
        break;
    case 5:
        printf("Todos: \n\n");
        clock_t begin_bubble = clock();
        bubllesort(v, 0, tamanho-1);
        clock_t end_bubble = clock();
        double time_spent_bubble = (double)(end_bubble - begin_bubble) / CLOCKS_PER_SEC;
        printf("Tempo Bubble: %.20lf\n\n", time_spent_bubble);

        clock_t begin_selectionsort = clock();
        selectionsort(v, 0, tamanho-1);
        clock_t end_selectionsort = clock();
        double time_spent_selectionsort = (double)(end_selectionsort - begin_selectionsort) / CLOCKS_PER_SEC;
        printf("Tempo Sellection: %.20lf\n\n", time_spent_selectionsort);

        clock_t begin_insertionsortslow = clock();
        insertionsortsimples(v, 0, tamanho-1);
        clock_t end_insertionsortslow = clock();
        double time_spent_insertionsortslow = (double)(end_insertionsortslow - begin_insertionsortslow) / CLOCKS_PER_SEC;
        printf("Tempo Insertion Simples: %.20lf\n\n", time_spent_insertionsortslow);

        clock_t begin_insertionsort = clock();
        insertionsort(v, 0, tamanho-1);
        clock_t end_insertionsort = clock();
        double time_spent_insertionsort = (double)(end_insertionsort - begin_insertionsort) / CLOCKS_PER_SEC;
        printf("Tempo Insertion: %.20lf\n\n", time_spent_insertionsort);

        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
    
}
