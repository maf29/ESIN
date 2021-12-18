#include <iostream>
#include "llista.hpp"

//		llista doblement encadenada, circular i amb fantasma 
void Llista::separa(Llista &l2, int x){
// Pre: l2 és buida
// Post: S'han separat els elements del p.i., quedant al p.i. els elements
//       menors a x i a l2 els elements majors a x amb el mateix ordre.
	node *now = _prim->seg;
	l2._prim = new node;
	node *now_l2 = l2._prim;
	//bool trobat = false;
	while(now != _prim){
		//cout << now->info << " :  "<<endl;
		if(now->info > x){	//guardar en l2 y quitar de p.i
			
				
			now_l2->seg = new node;
			
			now_l2->seg->info = now->info;
			
			now_l2->seg->ant = now_l2;
			
			now_l2->seg->seg = NULL;
			
			now_l2 = now_l2->seg;
			
			
			l2._long++;
		
		}
		if(now->info == x or now->info > x){	//eliminar de p.i
			
			now->ant->seg = now->seg;
			now->seg->ant = now->ant;
			now = now->seg;
			
			_long--;
		}
		else{	//apuntar al siguiente porque now->info < x
			now = now->seg;
		}
		
	}
	
	//Crear circularidad de la lista l2
	now_l2->seg = l2._prim;	
	l2._prim->ant = now_l2;
	
}
