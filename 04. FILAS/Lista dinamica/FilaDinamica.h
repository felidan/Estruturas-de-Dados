#include <iostream>
#include <stdlib.h>
#include "no.cpp"
#define MAX 5

#ifndef Dinamica_H
#define Dinamica_H

using namespace std;

class ListaDinamica{
	private:
		No* primeiro;
		No* ultimo;
		int tamanho;
		
	public:

        ListaDinamica();
        void enfilera(int);
        int desenfilera(int*);
	};


#endif
