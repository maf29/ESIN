#include <iostream>
#include "llista.hpp"

//llista doblement encadenada, sense fantasma i no circular

void Llista::duplica_parells_elimina_senars(){
// Pre: True
// Post: S'han duplicat els elements parells i
//       s'han eliminat els elements senars del p.i.
//       Exemple: [2 3 0 5 -2] => [2 2 0 0 -2 -2]
	node *now = _prim;
	while(now != NULL){
		
		if(now->info % 2 == 0){	//parells
			node *aux = now->seg;
			
			now->seg = new node;
			now->seg->info = now->info;
			now->seg->ant = now;
			
			if(aux != NULL){	//si NO estamos al final de la lista
				
				now->seg->seg = aux;
				aux->ant = now->seg;	
			}
			else{	//si ESTAMOS al final de la lista
				
				_ult = now->seg;	//el valor ultimo ahora pasara a ser el nodo duplicado
				
				now->seg->seg = NULL;	//el seguent al nodo duplicado es NULL
			}
			
			now = now->seg->seg;	//iterar el nodo
			_long++;	//aumentar la mida de la lisra
			
		}
		else{	//senars
			if(now->ant == NULL and now->seg == NULL){
				_prim = new node;
				
				_prim = NULL;	//El primero es null
				_ult = _prim;	//El ultimo tambien sera null igual que el primero
				
				now = _prim;
			}
			else if(now->ant == NULL){	
				_prim = new node;
				_prim = now->seg;
				_prim->ant = NULL;
				
				now = _prim;
			}
			else if(now->seg == NULL){
				now->ant->seg = NULL;
				_ult = now->ant;
				now = now->ant->seg;
			}
			
			else{ 
				now->ant->seg = now->seg;
				now->seg->ant = now->ant;
				
				now = now->seg;
			}
			
			_long--;
		}
		
	}
	
}
