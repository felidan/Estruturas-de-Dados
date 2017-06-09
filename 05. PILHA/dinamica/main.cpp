#include <iostream>
#include <stdlib.h>
#include "PilhaDinamica.cpp"

using namespace std;

int main (){

    PilhaDinamica<int> p;
    bool erro = false;
    
    p.empilha(10);
    p.empilha(5);
    p.empilha(3);
    p.empilha(8);
    p.empilha(7);
    p.empilha(-1);
    
    cout<<"Desempilhando...\n\n";
	while(!erro){
		int ret = p.desempilha(&erro);
		if(!erro)
		    cout << "[" << ret << "] ";
	}
	cout << endl << endl;;


	system("pause");
	return 0;
}
