#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "No.cpp"

//#include <string>

#ifndef LDE_H
#define LDE_H

using namespace std;

class LDE{
	private:
		No * primeiro;
		int total;	
	
	public:
		LDE();
		void isereLDE(int);
		No * buscaLDE(int);
		void removeLDE(int);
		void imprime();
		~LDE();
};

#endif
