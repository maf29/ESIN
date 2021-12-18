#include <iostream>
#include "llista.hpp"

//		simplemente encadenada y CON fantasma

// Pre: True
// Post: S'han duplicat els elements del p.i.
//       Exemple: [2 5 3] = > [2 2 5 5 3 3]
void Llista::duplica(){
	node *now = _prim->seg, *anterior = NULL;
	
	while(now != NULL){
		if(anterior == NULL){ //Al principio
			_prim->seg = new node;
			_prim->seg->info = now->info;
			
			_prim->seg->seg = now;
			
		}
		else{
			anterior->seg = new node;
			anterior->seg->info = now->info; //duplicar la información
			
			anterior->seg->seg = now; //Para lincar
		}
		
		_long++;
		
		anterior = now;
		now = now->seg;
	}  
}
