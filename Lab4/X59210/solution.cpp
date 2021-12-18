#include "llista.hpp"
#include <iostream>

//		LISTA ==>  SIMPLEMENTE encadenada, sin FANTASMA Y no circular

Llista::Llista(const vector<int> &v){ //constructora por copia
// Pre: True
// Post: El p.i. conté els elements de v amb el mateix ordre.	

	_long = v.size();
	node *aux;
	
	_prim = new node;	//Crear nodo del fantasma
	_prim->seg = NULL;	//Poner como siguiente NULL para tractarlo mas adelante
	
	node *anterior = NULL;
	
	if(v.size() > 0){
		for(nat i = 0; i < v.size(); ++i){
			aux = new node;
			
			aux->info = v[i]; //Guardar el elemento p.i del vector en el nodo auxiliar
			aux->seg = NULL; //Creamos su nodo siguiente
			 
			 
			if(_prim->seg == NULL){ //Si estamos en el nodo fantasma, el siguente es null y hay que tractarlo
				
				_prim->seg = aux;
			}
			else anterior->seg = aux; // el nodo actual es aux
			
			anterior = aux;	//El nodo anterior pasa a ser el nodo al que apuntamos == iteramos			 
		}
		anterior->seg = NULL; //Ultimo elemento de la lista siempre es ==> NULL
	}	
}
