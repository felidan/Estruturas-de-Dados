#include <iostream>
#include <stdlib.h>
#include "ListaEstatica.h"

using namespace std;

void operator <<(ListaEstatica& a, int x){
	a.enfilera(x);
}

bool operator >>(ListaEstatica& a, int& x){
	return a.desenfilera(&x);
}

int main (){

    ListaEstatica lista;
    int numero;
    lista << 7;
	lista << 6;
	lista << 5;
	lista << 4;
	lista << 3;
	lista << 2;
	lista << 1;
	
	while(lista >> numero){
		cout << "Desenfileirando: " << numero << endl;
	}

	system ("pause");
	return 0;
}

