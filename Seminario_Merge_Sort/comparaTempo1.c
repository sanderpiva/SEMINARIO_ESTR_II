#include <stdio.h>
#include <stdlib.h>
#include "biblioteca1.h"

int main(){
	int *vetBs, *vetSs, n,i;
	int *vetIs, *vetMs;
	float ini,fim, tempo;
	printf("Tamanho do vetor:");
	scanf("%d",&n);
	vetBs = malloc(sizeof(int)*n);// alocando o vetor dinamicamente
	vetSs = malloc(sizeof(int)*n);
	vetIs = malloc(sizeof(int)*n);
	vetMs = malloc(sizeof(int)*n);
	geraVet(vetBs,n);
	for(i=0; i<n;i++){

		vetSs[i]=vetBs[i];
		vetIs[i]=vetBs[i];
		vetMs[i]=vetBs[i];
	}

    //----Bs---
	ini = clock();
	bsort(vetBs,n);
	fim = clock();
	tempo = (fim - ini)/1000;
	printf("Bubble: Tempo(s):%.4f\n",tempo);
	printf("Comparacoes Bs: %d\n", compBs);

	//----SS----
	ini = clock();
	ssort(vetSs,n);
	fim = clock();
	tempo = (fim - ini)/1000;
	printf("Selection sort: Tempo(s):%.4f\n",tempo);
    printf("Comparacoes Ss: %d\n", compSs);
	//--
	//-----Is----
	ini = clock();
	isort(vetIs,n);
	fim = clock();
	tempo = (fim - ini)/1000;
	printf("Insert sort: Tempo(s):%.4f\n",tempo);
	printf("Comparacoes Is: %d\n", compIs);

	//----Ms----
	ini = clock();
	mergeSort(vetMs,0, n-1);
	fim = clock();
	tempo = (fim - ini)/1000;
	printf("Merge sort: Tempo(s):%.10f\n",tempo);
    printf("Comparacoes Ms: %d\n", compMs);
	//--

	return 0;
}

