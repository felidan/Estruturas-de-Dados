#include <iostream>
#include <stdlib.h>
#include <stdio.h>


#ifndef NO_H
#define NO_H

#include "PilhaDinamica.cpp"
using namespace std;

template<typename T>
class PilhaDinamica;

template<typename T>
class No{
	private:
		No <T> * anterior;
		T valor;
	public:
		No(T valor){
			this->valor = valor;
			this-> anterior = NULL;
			}
		T getValor() const{
			return valor;
		}
		friend class PilhaDinamica<T>;
};
#endif
