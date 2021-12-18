#include <iostream>
#include "llista.hpp"

//Eliminació dels elements de les posicions parells d'una llista simplement encadenada 


// Pre: True
// Post: S'han eliminat els elements del p.i. de les posicions parells
//       Exemple: [2 5 3 8 1] => [2 3 1]
void Llista::eliminaposicionsparells(){
	node *now = _prim, *ant = NULL;
	int cont = 1;
	if(_long > 0){
		while(now != NULL){
			if(cont % 2 == 0){ //PAR
				ant->seg = now->seg;	
				
				now = ant->seg; //Asignar el nuevo now
				
				_long--;
			}
			else{
				ant = now;
				now = now->seg;
			}
			
			cont++;
		}
	}
}
