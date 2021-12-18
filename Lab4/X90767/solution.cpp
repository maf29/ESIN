#include "llista.hpp"
#include <iostream>

//		LISTA ==> SIMPLEMENTE ENCADENASA, SIN FANTASMA Y NO CIRCULAR

Llista::Llista(const vector<int> &v){ //constructora por copia
// Pre: True
// Post: El p.i. conté els elements de v amb el mateix ordre.	

	_long = v.size();
	node *aux;
	_prim = NULL;
	node *anterior = NULL;

	if(v.size() > 0){
		for(nat i = 0; i < v.size(); ++i){
			aux = new node;
			
			aux->info = v[i]; //Guardar el elemento p.i del vector en el nodo auxiliar
			aux->seg = NULL; //Creamos su nodo siguiente
			 
			 
			if(anterior == NULL) _prim = aux;	//Si estamos al primer nodo, modificamos _prim
			else anterior->seg = aux; // el nodo actual es aux
			
			anterior = aux;	//El nodo anterior pasa a ser el nodo al que apuntamos == iteramos			 
		}
		anterior->seg = NULL; //Ultimo elemento de la lista siempre es ==> NULL
	}	
}
