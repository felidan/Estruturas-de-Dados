#include <iostream>
#include <stdlib.h>
#include "No.cpp"
#include "LDDE.h"

using namespace std;

int main (){
	LDDE lista;
	
	lista.isereLDDE(10);
	lista.imprime();
	lista.isereLDDE(20);
	lista.imprime();
	lista.isereLDDE(5);
	lista.imprime();
	lista.isereLDDE(-5);
	lista.imprime();
	
	cout<<"\nRemovendo o 20..."<<endl;
	lista.removeLDDE(20);
	lista.imprime();
	
	cout<<"\nRemovendo o -5..."<<endl;
	lista.removeLDDE(-5);
	lista.imprime();

	cout<<"Buscando o numero 5: "<< (lista.buscaLDDE(5))->numero <<endl;
	
	system ("pause");
	return 0;
}

