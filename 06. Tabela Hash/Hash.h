#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "LDE.h"
#include "No.cpp"

#define MAX 10

#ifndef HASH_H
#define HASH_H

using namespace std;

class Hash{
	private:
		LDE tab[MAX];
		int f_hash(int);

	public:
		Hash();
		void isere(int);
		No* busca(int);
		void remove(int);
		void imprimeHash();
		
};

#endif
