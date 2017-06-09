#include "FilaDinamica.h"

ListaDinamica::ListaDinamica(){
	tamanho = 0;
	primeiro = NULL;
	ultimo = NULL;
	}

void ListaDinamica::enfilera(int num){
    No * novo = new No();

	novo->numero = num;
    novo->proximo = NULL;
    

	if(ultimo == NULL)
	    primeiro = novo;
	else
	    ultimo->proximo = novo;
	    
	ultimo = novo;
	tamanho ++;
	}
	
int ListaDinamica::desenfilera(int * num){
	if(primeiro == NULL){
		cout<<"\nSem Elementos!"<<endl<<endl;
		return 0;
		}
		
		No* temp = primeiro;
		* num = primeiro->numero;
		
		primeiro = primeiro->proximo;
		
		free(temp);
		return 1;
		
	}
