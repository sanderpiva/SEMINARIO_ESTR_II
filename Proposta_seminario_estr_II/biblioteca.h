#include <stdio.h>
#include <stdlib.h>

long long compBs=0, compSs=0;
long long compIs=0;

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

void mergesort(int *v, int n)
{
    int *c = malloc(sizeof(int) * n);
    sort(v, c, 0, n - 1);
    free(c);
}

void sort(int *v, int *c, int i, int f)
{
    //adp
    int compMs=0;
    if (i >= f)
    {
        compMs++;
        return;

    }
    //adp
    int m = (i + f) / 2;

    sort(v, c, i, m);
    sort(v, c, m + 1, f);

    if (v[m] <= v[m + 1]) return;

    merge(v, c, i, m, f);
}

void merge(int *v, int *c, int i, int m, int f)
{
    int z,
        iv = i, ic = m + 1;

    for (z = i; z <= f; z++) c[z] = v[z];

    z = i;

    while (iv <= m && ic <= f)
    {

        if (c[iv] <= c[ic]) v[z++] = c[iv++];
        else v[z++] = c[ic++];
    }

    while (iv <= m) v[z++] = c[iv++];

    while (ic <= f) v[z++] = c[ic++];
}




