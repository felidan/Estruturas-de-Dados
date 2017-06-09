#include <iostream>
#include <stdlib.h>

#define MAX 5

#ifndef Estatica_H
#define Estatica_H

using namespace std;

class ListaEstatica{
	private:
		int inicio;
		int fim;
		int v[MAX];
		
	public:

        ListaEstatica();
        void enfilera(int);
        int desenfilera(int*);
	};


#endif
