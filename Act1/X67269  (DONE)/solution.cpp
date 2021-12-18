#include <iostream>
#include "llista.hpp"


// Pre: n > 0
// Post: Al p.i. s'han fusionat els elements del p.i. i de l2 agafant n elements del p.i.
//       i n elements de l2 alternativament (o els que quedin si n'hi ha menys de n).
//       Al principi del p.i. s'afegeix un nou element que conté la suma de tots els elements del p.i i l2
//       La llista l2 queda buida.
// Exemple amb n=2:
// p.i. [2 5 3 8 4] => [38 2 5 1 6 3 8 9 4]
// l2   [1 6 9]     => []
void Llista::fusiona_suma(Llista &l2, nat n){
	node *now = _prim, *now_l2 = l2._prim, *anterior = NULL, *ant_l2 = NULL; // , 
	
	//crear nodo para ir sumando
	_prim = new node;
	if(now != NULL){
		_prim->info = 0;
		_prim->seg = now;
		
		//now = now->seg;
	}
	else{
		_prim->info = 0;
		
		_prim->seg = new node;
		_prim->seg = NULL;
		
		anterior = _prim;
		now = _prim->seg;
		
	}
	_long++;
	
	nat cont_pi = _long-1, cont_l2 = l2._long-1; //
	while(now != NULL and now_l2 != NULL){ 
		//tractar l2

		if(cont_pi >= n){

			for(int i = 0; i < n; i++){
				_prim->info += now->info;
				anterior = now;
				now = now->seg;
			} 
			cont_pi -= n;
		}
		else{
		 	while(now != NULL){
				_prim->info += now->info;
				anterior = now;
				now = now->seg;
			}
			
		}
		
		//Tractar l2
		
		if(cont_l2 >= n){
			for(int i = 0; i < n; i++){
				_prim->info += now_l2->info;
				anterior->seg = new node;
				anterior->seg->info = now_l2->info;
				anterior = anterior->seg;
				anterior->seg = now;
				
				_long++;
				
				if(ant_l2 != NULL){
					ant_l2->seg = now_l2->seg;
					now_l2 = ant_l2->seg;
					l2._long--;
				}
				else{
					ant_l2 = now_l2;
					now_l2 = now_l2->seg;		
				}
			}
			cont_l2 -= n;
		}
		else{
		 	while(now_l2 != NULL){ 
				_prim->info += now_l2->info;
				
				anterior->seg = new node;
				anterior->seg->info = now_l2->info;
				
				anterior->seg->seg = now;
				anterior = anterior->seg;
				
				_long++;
				
				if(ant_l2 != NULL){
					ant_l2->seg = now_l2->seg;
					now_l2 = ant_l2->seg;
					l2._long--;
				}
				else{
					ant_l2 = now_l2;
					now_l2 = now_l2->seg;		
				}	
			}
		}
		
	}
	
	while(now != NULL){ //DONE
		
		_prim->info += now->info;
		now = now->seg;
	}
	
	
	while(now_l2 != NULL){ //Falta borrar los elementos de l2
		_prim->info += now_l2->info;
		
		anterior->seg = new node;
		anterior->seg->info = now_l2->info;
		anterior->seg->seg = new node;
		anterior->seg->seg = NULL;
		
		anterior = anterior->seg;
		now = anterior->seg->seg;
		
		_long++;
		
		if(ant_l2 != NULL){
			ant_l2->seg = now_l2->seg;
			now_l2 = ant_l2->seg;
			l2._long--;
		}
		else{
			ant_l2 = now_l2;
			now_l2 = now_l2->seg;		
		}	
	}
	
	if(l2._prim != NULL){
		l2._prim = new node;
		l2._prim = NULL;
		l2._long--;
	}
	
	
}
