#include "ListaEstatica.h"

ListaEstatica::ListaEstatica(){
	inicio = 0;
	fim = 0;
	}

void ListaEstatica::enfilera(int numero){
	if((fim + 1)%MAX == inicio)
		return;
		
	v[fim] = numero;
	fim = (fim + 1) % MAX;

	}
	
int ListaEstatica::desenfilera(int * num){
	if(inicio == fim){
		cout<<"\nSem Elementos!"<<endl<<endl;
		return 0;
		}
		
		*num = v[inicio];
		inicio = (inicio + 1) % MAX;
		return 1;
	}
