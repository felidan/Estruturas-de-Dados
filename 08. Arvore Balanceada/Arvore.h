#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "No.cpp"

#ifndef ARVORE_H
#define ARVORE_H

using namespace std;

class Arvore{
	private:
		No * raiz;
		int quantidade;
	
	public:
		Arvore();
		No* getRaiz();
		void insere(int);
		No * busca(int);
		int contaFilhos(No*);
		void removeValor(int);
		void imprimeERD(No*);
		void imprimeEDR(No*);
		int nivel(int);
		int altura(No*);
		int FB(No*);
		void RightRotate(No*);
		void LeftRotate(No*);
		void balanceamento(No*);
		void destroiSubArvore(No*);
		~Arvore();
};

#endif
