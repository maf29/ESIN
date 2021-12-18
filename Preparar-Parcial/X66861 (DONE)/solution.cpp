#include <iostream>
#include "llista.hpp"

//	llista doblement encadenada, circular i amb fantasma

void Llista::duplica_majors_elimina_menors(){
// Pre: True
// Post: S'han duplicat els elements majors que l'anterior i
//       s'han eliminat els elements menors que l'anterior del p.i.
//       El primer element i els iguals a l'anterior no es dupliquen ni s'eliminen.
//       Exemple: [2 5 3 4 1 1] = > [2 5 5 4 4 1]
	node *anterior = _prim->seg, *now = _prim->seg->seg;
	
	while(now != _prim){
		
		if(now->info >  anterior->info){	//duplicar now
			
			node *aux = new node;
			aux->info = now->info;
			
			now->ant->seg = aux;
			aux->ant = now->ant;
			aux->seg = now;
			now->ant = aux;
			
			_long++;
		}	
		else if (anterior->info > now->info){	//eliminar now
			
			now->ant->seg = now->seg;
			now->seg->ant = now->ant;
			
			_long--;
		}
		
			anterior = now;
			now = now->seg;
		
		
	}
	
	
}
