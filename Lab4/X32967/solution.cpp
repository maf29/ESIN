#include <iostream>
#include "llista.hpp"

//		LISTA ==>  DOBLEMENTE encadenada, CON FANTASMA y CIRCULAR

Llista::Llista(const vector<int> &v){
// Pre: True
// Post: El p.i. conté els elements de v amb el mateix ordre.
	_long = v.size();
	node *now;	//nodo actual
	
	_prim = new node;	//Crear nodo del fantasma
	//Crear nodo seg y ant que son el mismo _prim
	_prim->seg = _prim;
	_prim->ant = _prim;
	
	node *aux = _prim; //Cogemos un nodo auxiliar y lo inicializamos con nodo fantasma
	
	if(v.size() > 0){
		for(nat i = 0; i < v.size(); ++i){
			now = new node;
			now->ant = aux;	//El nodo anterior al actual es aux
			now->info = v[i]; //Guardar el elemento p.i del vector en el nodo actual
			
			aux->seg = now;	//El nodo anterior apuntara al siguiente para iterar
			aux = now;	//Ahora el aux pasa a ser el nodo actual
			 
			if(i == v.size() - 1){ //Si estamos al final del vector
				aux->seg = _prim; //Como es circular, el ultimo elemento de la lista apunta al primero de la lista
				_prim->ant = aux; //El elemento anterior al primero es el ultimo
			}
		
		}	
	}
}
