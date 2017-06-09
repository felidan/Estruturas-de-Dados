#include <iostream>
#include <stdlib.h>
#include <stdio.h>


#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H
#include "No.cpp"
template<typename T>
class No;
#define MAX 100
using namespace std;

template<typename T>
class PilhaDinamica{
	private:
		No<T>* ultimo;

	public:
    PilhaDinamica(){
		ultimo = NULL;
	}
		
	bool empilha(T valor){

		No<T>* novo = new No<T>(valor);

		if(novo == NULL)
		    return false;

		novo->anterior = ultimo;
		ultimo = novo;
		return true;
	}
	
	T desempilha(bool *erro=NULL){

		T ret = ultimo->getValor();
		No<T>* temp = ultimo;
		ultimo = ultimo->anterior;
		delete temp;
		
		if(ultimo == NULL){
			if(erro){
				*erro = true;
				return T();
			}
		}
		return ret;
	}
	
	~PilhaDinamica(){
		while(ultimo){
			No<T> * ant = ultimo->anterior;
			delete ultimo;
			ultimo = ant;
		}
	}
	
};

#endif
