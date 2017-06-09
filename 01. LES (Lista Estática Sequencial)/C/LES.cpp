#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// author @felidan

// LES - Lista Estática Sequencial

#define N 100

typedef struct{
	int v[N];
	int total;
}LES;

void inicializaLES(LES * lista){
	lista->total = 0;
}

void insereLES(LES * lista, int valor){
	int i = 0, j;
	
	// Valida de há espaço
	if(lista->total == N){
		printf("Espaço insuficiente!\n");
		return;
	}
		
	// Varre o vetor e procura a posição em que o valor deverá ser inserido
	for(i = 0; i < lista->total && lista->v[i] < valor; i++);
	
	// Desloca valores maiores que o número para frente
	for(j = lista->total-1; j >= i; j--)
		lista->v[j+1] = lista->v[j];
		
	// Insere o valor no vetor
	lista->v[i] = valor;
	lista->total++;
}

int buscaBinaria(LES * lista, int valor, int inicio, int fim){
	
	// Condição de número não encontrado
	if(inicio > fim)
		return -1;
	
	// Calcula o pivô
	int p = (inicio + fim) / 2;
	
	// Número encontrado
	if(lista->v[p] == valor)
		return p;
		
	else if(lista->v[p] < valor)
		return buscaBinaria(lista, valor, p+1, fim);
		
	else 
		return buscaBinaria(lista, valor, inicio, p-1);
		
}

void removeLES(LES * lista, int valor){
	
	// Encontra a posição
	int p = buscaBinaria(lista, valor, 0, lista->total);
	int i;
	
	if(p == -1){
		printf("Numero nao encontrado!\n");
		return;
	}
	
	else {
		
		// -1 para não estourar o vetor na hora da atribuição 'lista->v[i] = lista->v[i+1]'
		for(i = p; i < lista->total-1; i++)	
			lista->v[i] = lista->v[i+1];
			
		lista->total--;
	}
	
}

void printLES(LES lista){
	int i;
	
	for(i = 0; i < lista.total; i++){
		printf("[%d] ", lista.v[i]);
	}	
	printf("\n");	
}

int main (){
	LES lista;
	
	inicializaLES(&lista);
	
	insereLES(&lista, 10);
	printLES(lista);
	insereLES(&lista, 20);
	printLES(lista);
	insereLES(&lista, 5);
	printLES(lista);
	insereLES(&lista, -5);
	printLES(lista);
	
	printf("\nRemovendo o 20...\n");
	removeLES(&lista, 20);
	printLES(lista);
	
	printf("\nRemovendo o -5...\n");
	removeLES(&lista, -5);
	printLES(lista);
	
	printf("\nBuscando o num 20: %d\n", buscaBinaria(&lista, 20, 0, lista.total-1) );
	
	printf("Buscando o num -5: %d\n", buscaBinaria(&lista, -5, 0, lista.total-1) );
	
	printf("Buscando o num 5: %d\n", buscaBinaria(&lista, 5, 0, lista.total-1) );
	
	
	system ("pause");
	return 0;
}

