#include <stdlib.h>
#include <iostream>

#define MAX 20

using namespace std;

class LES{
	private:
		int v[MAX];
		int total;

	public:
		LES();
		int getTotal();
		int buscaBinaria(int valor, int inicio, int fim);
		void insereLES(int valor);
		void removeLES(int valor);
		void print();
	};
