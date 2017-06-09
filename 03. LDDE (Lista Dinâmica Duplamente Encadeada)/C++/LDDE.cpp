#include "LDDE.h"

// Inicializa LDDE
LDDE::LDDE(){
	total = 0;
	primeiro = NULL;
	ultimo = NULL;
}

void LDDE::isereLDDE(int valor){
	// Ponteiro do valor a ser inserido
	No * novo = new No();
	
	// Ponteiro Anterior
	No * ptrAnterior = NULL;
	// Ponteiro que guarda o n�mero atual
	No * ptrAtual = primeiro;
	
	// Set do ponteiro com o valor a ser inserido
	novo->numero = valor;
	novo->proximo = NULL;
	novo->anterior = NULL;
	
	// Enquanto o poteiro atual existir 
	// e o n�mero do ponteiro atual for < que o valor a ser inserido...
	while(ptrAtual != NULL && ptrAtual->numero < valor){
		// Anda com o ponteiro Anterior...
		ptrAnterior = ptrAtual;
		// Anda com o ponteiro atual...
		ptrAtual = ptrAtual->proximo;
	}
	
	// Se o ponteiro anterior existir...
	if(ptrAnterior){
		// Ent�o o ponteiro anterior aponta para o novo..
		ptrAnterior->proximo = novo;
		// E o ponteiro novo aponta para o anterior de volta..
		novo->anterior = ptrAnterior;
	}
	
	// Sen�o n�o h� nenhum n�mero alocado! Ent�o..	
	else
		// O primeiro n�mero ser� o novo
		primeiro = novo;
		
	// Se o ponteiro atual existir..
	if(ptrAtual)
		/* Como o ponteiro atual existe 
		   e o ponteiro atual � o primeiro n�mero 
		   maior que o novo n�mero ent�o o ptrAnterior 
		   dele apontar� para o novo! */
	    ptrAtual->anterior = novo;
	else
		/* Sen�o quer dizer que o while acabou 
		   por n�o ter encontrado um n�mero menor 
		   que o novo.. ent�o o novo n�mero ser� o ultimo!*/
	    ultimo = novo;
	
	/* Novo aponta para o atual, pois se o ponteiro 
	   atual n�o for maior que que o novo ele ser� NULL, 
	   caracterizando que o novo � o ultimo */
	novo->proximo = ptrAtual;
	total++;
}

No * LDDE::buscaLDDE(int valor){
	No * atual = primeiro;
	
	// Enquanto o atual existir e o numero for <= ao valor procurado..
	while(atual != NULL && atual->numero <= valor){
		// Se for o n�mero procurado..
		if(atual->numero == valor)
			return atual;
			
		atual = atual->proximo;
	}
	// Sen�o retorna NULL
	return NULL;
}

void LDDE::removeLDDE(int valor){
	No * ptrAnterior = NULL;
	No * ptrAtual = primeiro;
	
	// Enquanto o poteiro atual existir 
	// e o n�mero do ponteiro atual for < que o valor a ser inserido...
	while(ptrAtual != NULL && ptrAtual->numero < valor){
		
		// Anda com o ponteiro anterior..
		ptrAnterior = ptrAtual;
		// Anda com o ponteiro atual..
		ptrAtual = ptrAtual->proximo;
	}
	
	// Se o ponteiro atual n�o existir OU o n�mero dele for diferente do procurado..
	if(ptrAtual == NULL || ptrAtual->numero != valor)
		return;
		
	// Se o ponteiro anterior existir..
	if(ptrAnterior){
		/* O ponteiro anterior aponta para o proximo 
		   do atual, pois o ponteiro atual � o n�mero 
		   a ser removido! */
		ptrAnterior->proximo = ptrAtual->proximo;
	}
	// Sen�o..
	else
		// O n�mero a ser removido � o primeiro..
		primeiro = ptrAtual->proximo;
	
	// Se o ponteiro atual n�o for o ultimo..
    if(ptrAtual->proximo){
    	// Ent�o o ponteiro atual - proximo apontar� na volta para o ponteiro anterior
		ptrAtual->proximo->anterior = ptrAnterior;
	}
	// Se o ponteiro atual for o ultimo..
	else
		ultimo = ptrAnterior;
		
	// Deleta o atual	
	delete ptrAtual;
	ptrAtual = 0;
	
	total--;
}

void LDDE::imprime(){
	No * atual = ultimo;
	
	while(atual){
		printf("[%d] ", atual->numero);
		atual = atual->anterior;
	}
	cout<<endl;
}

LDDE::~LDDE(){
	No * atual = primeiro;
	No * temp;
	
	while(atual){
		temp = atual->proximo;
		delete atual;
		atual =  temp;
	}
	primeiro = NULL;
	ultimo = NULL;
	total = 0;
}
