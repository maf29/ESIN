#include <iostream>
#include "pila.hpp"
#include <sstream>
using namespace std;

int main(){
	
	string serie;
	while(getline(cin, serie)){
		int num;
		istringstream s(serie);
		pila par, impar;
		
		while(s>>num){
			if(num%2 == 0) par.apilar(num);
			else impar.apilar(num);
		}
		
		//Imprimiremos los elementos de la pila par de froma inversa
		
		bool vacia = true;
		if(par.es_buida()) vacia = false; //si par es false
		while(not par.es_buida()){
			cout << par.cim();//Imprimer el numero que esta en la cima que es el numero mayor de la pila par
			par.desapilar();
			
			if(not par.es_buida()) cout << " ";
		}
		
		//Imprimiremos los elementos de la pila par de froma inversa
		
		if(not impar.es_buida() and vacia) cout << " "; //Si la lista impar no es vacia y la par tampoco lo es, hacer un espacio entre el ultimo elemento par y el primero impar que se va al imprimir
		while(not impar.es_buida()){
			cout << impar.cim();//Imprimer el numero que esta en la cima que es el numero mayor de la pila par
			impar.desapilar();
			
			if(not impar.es_buida()) cout << " ";
		}
		
		cout << endl;
	}

}
