#include "Hash.h"

int Hash::f_hash(int num){
	return num % MAX;
	}
Hash::Hash(){
	}

void Hash::isere(int num){
	tab[f_hash(num)].isereLDE(num);
	}
	
No* Hash::busca(int num){
	return tab[f_hash(num)].buscaLDE(num);
	}

void Hash::remove(int num){
	tab[f_hash(num)].removeLDE(num);
	}
	
void Hash::imprimeHash(){
	for(int i=0; i<MAX; i++){
		tab[i].imprime();
		}
	}
