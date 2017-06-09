#include <iostream>
#include <stdlib.h>
#include "No.cpp"
#include "Arvore.h"

using namespace std;

int main (){

	Arvore a;
	
	a.insere(1);
	a.insere(3);
	a.insere(7);
	a.insere(5);


	cout<<"Removendo o valor 1..."<<endl;
	a.removeValor(1);
	
	a.insere(2);
	a.insere(1);
	
	No* b = a.busca(3);
	cout<<"Buscando o 3: "<<endl;
	cout<<"Valor Encontrado: "<<b->valor<<endl;
	
	cout<< "raiz: " << a.getRaiz()->valor << endl;
	
	//a.RightRotate( a.getRaiz() );
	cout << endl << "ERD" << endl;
	a.imprimeERD( a.getRaiz() );
	
	cout << endl << "EDR" << endl;
	a.imprimeEDR( a.getRaiz() );


	
	system ("pause");
	return 0;
}

