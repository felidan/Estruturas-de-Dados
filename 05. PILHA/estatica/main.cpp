#include <iostream>
#include <stdlib.h>
#include "PilhaEstatica.cpp"

using namespace std;

void operator<<(ostream& out, const PilhaEstatica<int>& p){
	for(int i=0; i<=p.topo; i++){
		cout << "[" << p.v[i] << "] ";
		}
		cout<<endl;
	}

int main (){

    PilhaEstatica<int> p;
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
			cout << p;
	}
	cout << endl << endl;;


	system("pause");
	return 0;
}
