#include "les.h"

LES::LES(){
	total = 0;
	}
int LES::getTotal(){
	return total;
	}
int LES::buscaBinaria(int valor, int inicio, int fim){
	int p = (inicio + fim) / 2;

	if(inicio > fim) return -1;

	if(v[p] == valor) return p;
	else if(v[p] < valor){
		return buscaBinaria(valor, p+1, fim);
		}
	else{
        return buscaBinaria(valor, inicio, p-1);
		}
	}
void LES::insereLES(int valor){
	int i, j;
	
	if(total == MAX) cout<<"Sem Espaco!"<<endl;
	
	for(i=0; i<total && v[i]<valor; i++);
	
	for(j=total-1; j >= i; j--){
		v[j + 1] = v[j];
		}

	v[i] = valor;
	total++;
	}
	
void LES::removeLES(int valor){
	int i;
	int posicao = buscaBinaria(valor, 0, total);

	if(posicao == -1) return;
	else{
		for(i=posicao; i<total-1; i++){
			v[i] = v[i + 1];
			}
		}
	total--;
	}
	

void LES::print(){

	for(int i=0; i<total; i++){
		cout<<v[i]<<" ";
		}
	cout<<endl;
	}
