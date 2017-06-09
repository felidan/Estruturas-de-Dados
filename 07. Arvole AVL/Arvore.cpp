#include "Arvore.h"

Arvore::Arvore(){
	raiz = NULL;
	quantidade = 0;
	}
	
No* Arvore::getRaiz(){
	return raiz;
	}
	
void Arvore::insere(int valor){
	No * novo = new No();
	
	novo->valor = valor;
	novo->pai = NULL;
	novo->esquerda = NULL;
    novo->direita = NULL;
    
    No * atual = raiz;
    No * anterior = NULL;
    
    while(atual){
		anterior = atual;
		
		if(novo->valor < atual->valor)
		    atual = atual->esquerda;
		else
		    atual = atual->direita;
		    
  	}
  	if(anterior){
		novo->pai = anterior;
		
		if(valor < anterior->valor)
		    anterior->esquerda = novo;
		else
		    anterior->direita = novo;
	}
	else
	    raiz = novo;
	    
	quantidade++;
    
	}
	
No * Arvore::busca(int valor){

    No * atual = raiz;
    No * anterior;

    while(atual){
		anterior = atual;

		if(valor < atual->valor)
		    atual = atual->esquerda;
		else if(valor > atual->valor)
		    atual = atual->direita;
		else if(valor == atual->valor)
		    return atual;

  	}
  	return NULL;
  	
	}
	
int Arvore::contaFilhos(No* no){
	int cont = 0;
	if(no->esquerda) cont++;
	if(no->direita) cont++;
	
	return cont;
}

void Arvore::removeValor(int valor){
	No* remove = busca(valor);
	No* pai;
	int nFilhos;
	if(!remove){
		cout<<"Valor não encontrado"<<endl;
		return;
	}
	
	nFilhos = contaFilhos(remove);
	pai = remove->pai;
	
	if(nFilhos == 0){
		if(pai->esquerda == remove)
			pai->esquerda = NULL;
		else
			pai->direita = NULL;
			
		free(remove);
		
		if(!pai)
			raiz = NULL;
	}
	else if(nFilhos == 1){
		No* filho = remove->esquerda;
		if(!filho)
			filho = remove->direita;
			
		if(pai->esquerda == remove)
			pai->esquerda = filho;
			
		else
			pai->direita = filho;
		
		filho->pai = remove->pai;
		
		free(remove);
	}
	else{
		No* sucessor = remove->direita;
		
		while(sucessor->esquerda)
			sucessor = sucessor->esquerda;
		
		int vlSucessor = sucessor->valor;

		removeValor(sucessor->valor);
		remove->valor = vlSucessor;
	}
	quantidade--;
}

void Arvore::imprimeERD(No* atual){
	if(atual){
        imprimeERD(atual->esquerda);
		cout<<"["<<atual->valor<<"]"<<endl;
        imprimeERD(atual->direita);
		}
	}

int Arvore::nivel(int num){
	No* atual = busca(num);
	int cont=-1;
	
	while(atual){
		atual = atual->pai;
		cont++;
	}
	return cont;
}
	
int Arvore::altura(No* atual){
    int u, v;
    
    if(atual == NULL)
    	return -1;
    	
    u = altura(atual->esquerda);
    v = altura(atual->direita);
    
    if(u > v)
    	return u+1;
    else
    	return v+1;
}

void Arvore::destroiSubArvore(No* no){
	destroiSubArvore(no->esquerda);
	destroiSubArvore(no->direita);

	free(no);
} 
Arvore::~Arvore(){
	destroiSubArvore(raiz);
	raiz == NULL;
	quantidade = 0;
	
	cout<<"Arvore destroida!!!"<<endl;
}
