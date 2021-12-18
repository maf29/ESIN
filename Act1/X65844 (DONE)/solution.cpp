#include <iostream>
#include "llista.hpp"



// Pre: True
// Post: S'han duplicat els elements del p.i.
//       Exemple: [2 5 3] = > [2 2 5 5 3 3]
void Llista::duplica(){
	
	node *now = _prim, *anterior = NULL;
	while(now != NULL){
		if(anterior == NULL){ //al principio
			_prim = new node; //Crear new node
			_prim->info = now->info;//El primer elemento tiene el mimsmo numero que now
			
			_prim->seg = now; //Lincar _prim con now
			
		}
		else{
			
			//Utilizar el anterior para lincar con el now
			anterior->seg = new node;
			anterior->seg->info = now->info;
			
			anterior->seg->seg = now; //Para lincar el nuevo nodo con el resto de la lista			
		
		}
		_long++;
		
		anterior = now;
		now = now->seg;
	}
	
}
