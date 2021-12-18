#include <iostream>
#include "llista.hpp"

//llista doblement encadenada 

void Llista::separa(Llista &l2, int x){
// Pre: l2 és buida
// Post: S'han separat els elements del p.i., quedant al p.i. els elements
//       menors a x i a l2 els elements majors a x amb el mateix ordre.

	node *now = _prim, *now_l2 = NULL;
	
	while(now != NULL){
		if(now->info > x){	//guardar en l2 y quitar de p.i
			if(now_l2 == NULL){	//guardar en l2 si l2 es vacia
				l2._prim = new node;
				l2._prim->info = now->info;
				l2._prim->ant = NULL;
				l2._prim->seg = NULL;
				
				l2._ult = l2._prim;
				
				now_l2 = l2._prim;
				
			}
			else{	//guardar en l2 si l2 NO es vacia
				
				now_l2->seg = new node;
				
				now_l2->seg->info = now->info;
				now_l2->seg->seg = NULL;
				
				now_l2->seg->ant = now_l2;
				l2._ult = now_l2->seg;
				
				now_l2 = now_l2->seg;
			}
			l2._long++;
		
		}
		if(now->info == x or now->info > x){	//eliminar de p.i
			if(now->ant == NULL and now->seg == NULL){
				_prim = new node;
				_prim = NULL;
				_ult = _prim;
				now = _prim;
			}
			else if(now->ant == NULL){ 
				_prim = new node;
				
				_prim = now->seg;
				
				now = _prim;
				
				now->ant = NULL;
			}
			else if (now->seg == NULL){
				_ult = now->ant;
				now->ant->seg = NULL;
				now = now->ant->seg;
			}
			else{	//si no esta al principio de la lista
				
				node *aux = now->ant;
				now->ant->seg = now->seg;
				
				now = now->seg;
				now->ant = aux;
				
			}
			_long--;
		}
		else{	//apuntar al siguiente porque now->info < x
			now = now->seg;
		}
	}
}
