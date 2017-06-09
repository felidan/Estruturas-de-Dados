#include <iostream>
#include <stdlib.h>

#ifndef No_H
#define No_H

using namespace std;

class No{
	public:
		No * pai;
		No * esquerda;
		No * direita;
		int valor;

		~No(){
			//delete proximo;
			//delete anterior;
		}
};

#endif
