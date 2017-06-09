#include <iostream>
#include <stdlib.h>
#include "No.cpp"
#include "LDE.h"

using namespace std;

int main (){
	LDE lista;
	
	lista.isereLDE(10);
	lista.imprime();
	lista.isereLDE(20);
	lista.imprime();
	lista.isereLDE(5);
	lista.imprime();
	lista.isereLDE(-5);
	lista.imprime();
	
	cout<<"\nRemovendo o 20..."<<endl;
	lista.removeLDE(20);
	lista.imprime();
	
	cout<<"\nRemovendo o -5..."<<endl;
	lista.removeLDE(-5);
	lista.imprime();
	
	cout<<"Buscando o numero 5: "<< (lista.buscaLDE(5))->numero <<endl;
	
	system ("pause");
	return 0;
}

