#include <iostream>
#include <stdlib.h>
#include "No.cpp"
#include "Arvore.h"

using namespace std;

int main (){

	Arvore a;
	
	a.insere(2);
	a.insere(15);
	a.insere(5);
	a.insere(10);
	a.insere(25);
	a.insere(0);
	
	No* b = a.busca(10);
	cout<<"Buscando o 10: "<<endl;
	cout<<"Valor Encontrado: "<<b->valor<<endl;
	

	cout<<"Nivel: "<< a.nivel(25) <<endl;
	
	int altura = a.altura( a.getRaiz() );
	if(altura != -1){
		cout<<"Altura: "<< altura <<endl;	
	}
	
	
	a.imprimeERD( a.getRaiz() );

	cout<<"Removendo o valor 10..."<<endl;
	
	a.removeValor(10);

	a.imprimeERD( a.getRaiz() );

	
	system ("pause");
	return 0;
}

