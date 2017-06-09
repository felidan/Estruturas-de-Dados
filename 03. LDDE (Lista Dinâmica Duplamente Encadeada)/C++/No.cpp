#include <iostream>
#include <stdlib.h>
//#include <string>

#ifndef No_H
#define No_H

using namespace std;

class No{
	public:
		int numero;
		No * proximo;
		No * anterior;

		~No(){
			//delete proximo;
			//delete anterior;
		}
};

#endif
