#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class MaxHeap{
	private:
		vector<int> v;
	public:
		MaxHeap(vector<int> v) : v(v){
			constroiHeap();
			
		}
		int filhoEsquerdo(int i){
			return (2*i) + 1;
		}
		int filhoDireito(int i){
			return (2*i) + 2;
		}
		int pai(int i){
			return (i-1) / 2;
		}
		int ultimoPai(int n){
			return (n/2) - 1;
		}
		void peneira(int index){
			int mFilho = filhoEsquerdo(index);
	
			if(filhoDireito(index) < v.size() && v[filhoDireito(index)] > v[mFilho]){
				mFilho = filhoDireito(index);
			}
			
			if(v[mFilho] > v[index]){
				int temp = v[mFilho];
				v[mFilho] = v[index];
				v[index] = temp;
				peneira(index);
			}
			
			if(index > ultimoPai(v.size())){
				return;
			}
		}
		void constroiHeap(){
			for(int i = ultimoPai(v.size()); i >= 0; i--){
				peneira(i);
			}
			for(int i = ultimoPai(v.size()); i >= 0; i--){
				peneira(i);
			}
		}	
		void print(){
			for(int i=0; i<v.size(); i++){
				cout<< "[" << v[i] << "] ";
			}
			cout<<endl;
		}

	void insere(int n){
		v.push_back(n);
		constroiHeap();
	}
	
	int remove(){
		int saida = v[0];
		
		v[0] = v[ (v.size()-1) ];
		v.pop_back();
		
		peneira(0);
		
		return saida;
	}
};

int main (){

	vector<int> v;
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	MaxHeap h(v);

	h.print();
	
	cout<<endl<<"removendo...  ";
	h.remove();
	h.print();
	
	cout<<"removendo...  ";
	h.remove();
	h.print();
	
	cout<<"removendo...  ";
	h.remove();
	h.print();
	
	cout<<"removendo...  ";
	h.remove();
	h.print();
	
	cout<<endl<<"inserindo o 7...   ";
	h.insere(7);
	h.print();
	
	cout<<"inserindo o 0...   ";
	h.insere(0);
	h.print();
	
	cout<<"inserindo o 10...  ";
	h.insere(10);
	h.print();
	
	cout<<endl;
	
	system ("pause");
	return 0;
}

