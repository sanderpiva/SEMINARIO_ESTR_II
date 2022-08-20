#include <stdio.h>
#include <stdlib.h>

long long compBs=0, compSs=0;
long long compIs=0, compMs=0;

void troca(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b=temp;
}// fim troca
//----------------------
void geraVet(int v[], int n)
{
    int i;
    srand(time(NULL));
    for(i=0; i<n; i++)
        v[i]=rand()%50;
}// fim geraV
//-----------------------------
void printVetor(int v[],int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d |",v[i]);
    printf("\n");
}// fim printVetor
//--------- Bubble Sort -----------------
void bsort(int v[], int n)
{
    int i,j;

    for(i=1; i<n; i++) // fases
    {

        for(j=0; j<n-i; j++) // comparações
        {
            compBs++;
            if(v[j]>v[j+1])
            {
                troca(&v[j],&v[j+1]);
            }// fim if
        }// fim for j
    }// fim for i
}
//------------- Selection Sort ---------------
int minIndex(int v[], int i, int n)
{
    int j, imenor = i;

    for(j=i+1; j<n; j++)
    {
        compSs++;
        if(v[j]<v[imenor])
            imenor=j;
    }
    return imenor;
}

void ssort(int v[], int n)
{
    int i, indiceMenor;
    for(i=0; i<n-1; i++)
    {
        indiceMenor = minIndex(v,i,n);
        troca(&v[i], &v[indiceMenor]);
    }// fim for
}
//----------------------------------------

//----Is
void insert(int v[], int i)
{

    int eleito = v[i];
    int c = i-1;

    while(c>=0 && eleito < v[c])
    {
        compIs++;
        v[c+1]=v[c]; //deslocar// eh 1 instrucao enqto a troca sao 3
        c--;
        //deslocar e voltar
    }//fim while
    compIs++;
    v[c+1] = eleito;

}


void isort (int v[], int n)
{

    int i;
    //considera que a pos 0 esta ordenada
    for(i=1; i<n; i++)
    {

        insert(v, i);

    }//fim for

}

//----Ms----

void merge(int vetor[], int comeco, int meio, int fim)
{
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim)
    {
        if(vetor[com1] < vetor[com2])
        {
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else
        {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio)   //Caso ainda haja elementos na primeira metade
    {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim)     //Caso ainda haja elementos na segunda metade
    {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++)     //Move os elementos de volta para o vetor original
    {
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim)
{
    if (comeco < fim)
    {
        compMs++;
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);

    }

}
