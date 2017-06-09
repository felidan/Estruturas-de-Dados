#include <iostream>
#include <stdlib.h>
#include "No.cpp"
#include "Hash.h"

using namespace std;

int main (){
	Hash tabela;
	
	tabela.isere(5);
	tabela.isere(2);
	tabela.isere(10);
	tabela.isere(1);
	
	tabela.imprimeHash();
	
	tabela.remove(10);
	
	tabela.imprimeHash();
	
	system ("pause");
	return 0;
}

