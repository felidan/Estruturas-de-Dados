#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "No.cpp"

//#include <string>

#ifndef LDDE_H
#define LDDE_H

using namespace std;

class LDDE{
	private:
		No * primeiro;
		No * ultimo;
		int total;	
	
	public:
		LDDE();
		
		//LDDE& operator<<(int num);
		
		void isereLDDE(int);
		No * buscaLDDE(int);
		void removeLDDE(int);
		void imprime();
		~LDDE();
		//friend ostream& operator << (ostream& saida, const LDDE& l);
};

#endif
