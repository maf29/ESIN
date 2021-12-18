#include "llista.hpp"
#include <iostream>

//		LISTA ==>  SIMPLEMENTE encadenada, sin FANTASMA Y no circular

void Llista::separa(Llista &l2){
    // Pre: l2 és buida
    // Post: S'han separat els elements del p.i., quedant al p.i. els elements
    //       de les posicions senars i a l2 els de les posicions parells.
    //       Exemple: [2 5 3 8 1] => [2 3 1] i l2 = [5 8]
    	if(_long != 0){
		node *now = _prim;
		if(now->seg != NULL ){ 
		
			l2._prim = now->seg;	//Guardar el nodo impar en el primer nodo de l2
			now->seg = now->seg->seg; //El nodo siguiente el siguiente del siguiente que será de una posición impar
			l2._prim->seg = NULL; //Inicializar el siguiente nodo a NULL
					
			node *nowl2 = l2._prim; //auxiliar para iterar la lista l2
			
			//Iterar los size de las listas
			l2._long += 1; //Sumar la longitud de l2 porque hay un nuevo elemento
			_long -= 1;	//Al eliminar un elemento de p.i hay que restarle una posicion a la lista
			
			nat imp = 3; //auxiliar para mirar las posiciones (como hemos tractado la posicion 2, ahora estamos en la posicion 3)
			while(now->seg != NULL){
				
				if(imp % 2 == 0){ //posicion PAR
					//Guardar en l2
					nowl2->seg = now->seg; //guardar el nodo siguiente now en el nodo siguiente al primer elemento de l2
					
					now->seg = now->seg->seg; //Eliminar de p.i
					
					nowl2->seg->seg = NULL;	//apuntar al siguiente
					nowl2 = nowl2->seg;	//apuntar al nodo siguiente que sera el anterior al ultimo de l2
					
					//Iterar los size de las listas
					l2._long += 1;
					_long -= 1;
					
				}
				else now = now->seg;	//al ser impar solo iteramos los nodos de la lista p.i
				 
				imp++;
			}
		}
	}
}
