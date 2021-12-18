#include <iostream>
#include "llista.hpp"

//		llista simplement encadenada 
void Llista::separa(Llista &l2, int x){
// Pre: l2 és buida
// Post: S'han separat els elements del p.i., quedant al p.i. els elements
//       menors a x i a l2 els elements majors a x amb el mateix ordre.
	node *now = _prim, *now_l2 = NULL, *anterior = NULL;//, *ant_l2 = NULL
	while(now != NULL){
		if(now->info > x){	//si el elemento es mayor que x, eliminarlo de x y añadirlo a l2
			if(now_l2 == NULL){	//estemos al principio de la lista l2
				
				l2._prim = new node;
				l2._prim->info = now->info;
				
				l2._prim->seg = NULL;
				now_l2 = l2._prim;
			}
			else{	//no estemos al principio de la lista l2
				
				now_l2->seg = new node;
				now_l2->seg->info = now->info;
				
				now_l2->seg->seg = NULL;
				now_l2 = now_l2->seg;
			}
			l2._long++;
			
			if(anterior == NULL){	//estamos al principio de la lista p.i
				_prim = new node;
				_prim = now->seg;
				
				now = _prim;
			}
			else{	//no estamos al principio de la lista p.i
				
				anterior->seg = now->seg;
				now = anterior->seg;
			}
			_long--;
			
		}
		else if(now->info == x){
			if(anterior == NULL){	//estamos al principio de la lista p.i
				_prim = new node;
				_prim = now->seg;
				
				now = _prim;
			}
			else{	//no estamos al principio de la lista p.i
				
				anterior->seg = now->seg;
				
				now = anterior->seg;
			}
			_long--;
			
				
			//now = now->seg;
		}else{
			anterior = now;	
			now = now->seg;
		}
	}
}
