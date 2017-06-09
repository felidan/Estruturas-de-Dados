#include "LDE.h"

LDE::LDE(){
	total = 0;
	primeiro = NULL;
}

void LDE::isereLDE(int valor){
	No * novo = new No();
	
	novo->numero = valor;
	novo->proximo = NULL;
	
	No * ptrAnterior = NULL;
	No * ptrAtual = primeiro;
	
	while(ptrAtual != NULL && ptrAtual->numero < valor){
		ptrAnterior = ptrAtual;
		ptrAtual = ptrAtual->proximo;
	}
	
	if(ptrAnterior != NULL)
		ptrAnterior->proximo = novo;
		
	else{
		primeiro = novo;
	}
	
		novo->proximo = ptrAtual;
		total++;
}

No * LDE::buscaLDE(int valor){
	No * atual = primeiro;
	
	while(atual != NULL && atual->numero <= valor){
		if(atual->numero == valor)
			return atual;
			
		atual = atual->proximo;
	}
	return NULL;
}

void LDE::removeLDE(int valor){
	No * ptrAnterior = NULL;
	No * ptrAtual = primeiro;
	
	while(ptrAtual != NULL && ptrAtual->numero < valor){
		ptrAnterior = ptrAtual;
		ptrAtual = ptrAtual->proximo;
	}
	
	if(ptrAtual == NULL || ptrAtual->numero != valor)
		return;
		
	if(ptrAnterior != NULL)
		ptrAnterior->proximo = ptrAtual->proximo;
		
	else
		primeiro = ptrAtual->proximo;
		
	delete ptrAtual;
	ptrAtual = 0;
	
	total--;
}


void LDE::imprime(){
	No * atual = primeiro;
	
	while(atual != NULL){
		printf("[%d] ", atual->numero);
		atual = atual->proximo;
	}
	cout<<endl;
}

LDE::~LDE(){
	
}
