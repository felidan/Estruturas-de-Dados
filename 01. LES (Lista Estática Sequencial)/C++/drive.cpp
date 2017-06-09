#include <stdlib.h>
#include <iostream>
#include "les.h"

using namespace std;

void menuOpcoes(){
    cout<<"1 - Insere"<<endl;
	cout<<"2 - Remove"<<endl;
	cout<<"3 - Listar"<<endl;
	cout<<"4 - Busca"<<endl<<endl;
	cout<<"5 - Fim"<<endl;
	}
	
int main (){
	LES lista;
	
	int menu, valor;
	
	menuOpcoes();
	
	while( cin>>menu ){
		if(menu == 1){
			cout<<"Valor: "; cin>>valor;
			lista.insereLES(valor);
			}
		else if(menu == 2){
            cout<<"Valor: "; cin>>valor;
            lista.removeLES(valor);
			}
		else if(menu == 3){
            lista.print();
			}
		else if(menu == 4){
            cout<<"Valor: "; cin>>valor;
            if(lista.buscaBinaria(valor, 0, lista.getTotal()) == -1) cout<<"Numero nao encontrato"<<endl;
            else cout<<"Numero encontrato"<<endl;
		}
		else if(menu == 5){

            return 0;
		}
		else{
            cout<<"Invalido"<<endl;
		}
}

	system("pause");
	return 0;
	}
