#include <iostream>
#include "llista.hpp"

//  Llista simplement encadenada, sense fantasma i no circular


//cercar nom_cercat a la llista i insereix l’alumne nom_nou a la posició immediatament posterior

//Si no es troba cap alumne amb nom nom_cercat, el nou alumne va al final de la llista.

void Llista::alumne_nou(string alumne_cercat, string alumne_nou){
// Pre: True
// Post: Es dona de alta l'alumne tal com es demana al exercici

	bool trobat = false;
	
	node *now = _prim;
	
	if(now == NULL){
		
		_prim = new node;
		_prim->info = alumne_nou;
		
		now = new node;
		now->seg = NULL;
		_long++;
	}
	
	while(now->seg != NULL and not trobat){

		if(now->info == alumne_cercat){
			node *aux = now->seg;  //Guardar el siguiente nombre en aux
			now->seg = new node;
			now->seg->info = alumne_nou;  //Guardar nou alumne en el nodo siguiente
			
			now->seg->seg = aux;  //
			now = now->seg;
			
			_long++;
			trobat = true;  //Encontrado
		}
		//ant = now;
		now = now->seg;
	}
	
	if(not trobat){ //SI no esta nom_cercat en la lista
		
		now->seg = new node;
		now->seg->info = alumne_nou;
		
		now = now->seg;
		
		now->seg = NULL;
	}
}
