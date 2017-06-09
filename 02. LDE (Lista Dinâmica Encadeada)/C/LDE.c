#include <stdlib.h>
#include <stdio.h>

/* author @felidan */

struct No{
	int numero;
	struct No * proximo;
};

struct LDE{
	struct No * primeiro;
	int total;
};

void inicializaLDE(struct LDE * lista){
	lista->total = 0;
	lista->primeiro = NULL;
}

void insereLDE(struct LDE * lista, int valor){
	/* N� a ser inserido */
	struct No * novo = malloc(sizeof(struct No));
	
	/* Set N� */
	novo->numero = valor;
	novo->proximo = NULL;
	
	/* N� para caso haja um ponteiro anterior */
	struct No * ptrAnterior = NULL;
	/* N� do ponteiro atual */
	struct No * ptrAtual = lista->primeiro;
	
	/* Se o ponteiro atual existir && o numero do ponteiro atual < valor a ser inserido... */
	while(ptrAtual != NULL && ptrAtual->numero < valor){
		
		/* Desloca o ponteiro atual para tr�s, pois o n�mero � menor */
		ptrAnterior = ptrAtual;
		
		/* Ponteiro atual = proximo ponteiro (avan�a um valor) */
		ptrAtual = ptrAtual->proximo;
	}
	
	/* Se o ponteiro anterior for ! NULL ent�o o valor deve ser alocado nele 
	   pois o deslocamento dos n�meros menores do que o novo j� foram realizados */
	if(ptrAnterior != NULL)
		ptrAnterior->proximo = novo;
	
	/* sen�o n�o h� nunhum valor alocado.. ent�o a lista->primeiro ser� o novo */
	else {
		lista->primeiro = novo;
	}
		
		/* novo->proximo = ptrAtual pois o ponteiro atual � NULL, que foi o que fez para o while acima */
		novo->proximo = ptrAtual;
		lista->total++;
}

struct No* buscaLDE(struct LDE * lista, int valor){
	
	/* Inicialmento o ponteiro atual ser� sempre o primeiro */
	struct No * atual = lista->primeiro;
	
	/* enquanto o ponteiro atual existir && e o n�mero do ponteiro atual for menor ou igual ao valor desejado.. */
	while(atual != NULL && atual->numero <= valor){
		if(atual->numero == valor)
			return atual;
		
		/* pulo para o proximo n�mero alocado */
		atual = atual->proximo;
	}
	
	/* sen�o retorna NULL */
	return NULL;
	
}

void removeLDE(struct LDE * lista, int valor){
	/* 1. Busca n�mero
	   2. Set o Ponteiro
	   3. Free no Ponteiro
	   4. total -- */
	
	/* N� para caso haja um ponteiro anterior */
	struct No * ptrAnterior = NULL;
	/* Inicialmento o ponteiro atual ser� sempre o primeiro */
	struct No * ptrAtual = lista->primeiro;
	
	/* Mesmo mecanismo de deslocamento do procedimento insereLDE */
	while(ptrAtual != NULL && ptrAtual->numero < valor){
		ptrAnterior = ptrAtual;
		ptrAtual = ptrAtual->proximo;
	}
	
	/* caso o ponteiro atual seja NULL (fim do vetor) OU o n�mero do ponteiro atual seja != do n�mero desejado */
	if(ptrAtual == NULL || ptrAtual->numero != valor)
		return;
		
	
	if(ptrAnterior != NULL)
		ptrAnterior->proximo = ptrAtual->proximo;
		
	else 
		lista->primeiro = ptrAtual->proximo;
		
	free(ptrAtual);
	
	lista->total --;
	
}

void imprime(struct LDE lista){
	struct No * atual = lista.primeiro;
	
	while(atual != NULL){
		printf("[%d] ", atual->numero);
		atual = atual->proximo;
	}	
	printf("\n");
}

int main ( int argc, const char* argv[] ){
	struct LDE lista;
	struct No * aux;
	
	inicializaLDE(&lista);
	
	insereLDE(&lista, 10);
	imprime(lista);
	insereLDE(&lista, 20);
	imprime(lista);
	insereLDE(&lista, 5);
	imprime(lista);
	insereLDE(&lista, -5);
	imprime(lista);
	
	printf("\nRemovendo o 20...\n");
	removeLDE(&lista, 20);
	imprime(lista);
	
	printf("\nRemovendo o -5...\n");
	removeLDE(&lista, -5);
	imprime(lista);
	
	aux = buscaLDE(&lista, 5);
	printf("Buscando o num 5: %d\n", aux->numero );
	
	system ("pause");
	return 0;
}

