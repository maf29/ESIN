#include <iostream>
#include "llista.hpp"

//	doblement encadenada, circular i amb fantasma 

// Pre: True
// Post: S'han duplicat els elements del p.i.
//       Exemple: [2 5 3] = > [2 2 5 5 3 3]

void Llista::duplica(){
	node *now = _prim->seg;
	
	while(now != _prim){ 
	
		if(now->ant == _prim){ //al principio
			
			_prim->seg = new node;
			_prim->seg->info = now->info;
			
			//Lincar
			_prim->seg->ant = _prim;
			_prim->seg->seg = now;
			now->ant = _prim->seg;
			
		}
		else{	
			now->ant->seg = new node;
			now->ant->seg->info = now->info;
			
			now->ant->seg->ant = now->ant; 	//lincar new node con su ant
			now->ant->seg->seg = now;	//Lincar new node con su seg
			now->ant = now->ant->seg;	//Lincar now con su ant q es new node
			
		}
		_long++;
		
		//Iterar
		if(now->seg == NULL){
			now->seg = _prim; //Como es circular, apunat al primero
			_prim->ant = now;
		}
		now = now->seg;
		
	}

}
