#include <stdio.h>

void merge(int vetor[], int comeco, int meio, int fim)
{
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));
    //enquanto inicio do lado 1 for <= ao meio e inicio do lado 2 for <= ao fim do vetor original
    while(com1 <= meio && com2 <= fim)
    {
        if(vetor[com1] < vetor[com2])  //
        {
            vetAux[comAux] = vetor[com1];
            com1++;//incremento do indice que se refere ao inicio do lado 1
        }
        else
        {
            vetAux[comAux] = vetor[com2];
            com2++;//incremento do indice que se refere ao inicio do lado 2
        }
        comAux++;//incrementa o indice do vetor auxiliar
    }

    while(com1 <= meio)   //Caso ainda haja elementos na primeira metade (lado 1)
    {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim)     //Caso ainda haja elementos na segunda metade (lado 2)
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

    if (comeco < fim)    //inicia processo
    {
        int meio = (fim+comeco)/2; //divide o vetor no meio

        mergeSort(vetor, comeco, meio); //aplica recursividade lado 1(esquerdo)
        mergeSort(vetor, meio+1, fim); //aplica recursividade lado 2(direito)
        merge(vetor, comeco, meio, fim);//final: mesclagem das duas metades
    }

}

int main (void)
{
    int i, ini, fim, *vetMs;
    int v[8] = { -1, 7, -3, 11, 4, -2, 4, 8 };
    printf("\nAntes da ordenacao: ");
    for(i = 0; i<8;i++){

        printf("%d ", v[i]);
    }

    printf("\nDepois da ordenacao Merge sort: ");
    mergeSort(v, 0, 7);

    for (i = 0; i < 8; i++) printf("%d ", v[i]);

    putchar('\n');

    return 0;
}

