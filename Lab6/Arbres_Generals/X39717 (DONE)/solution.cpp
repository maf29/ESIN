#include "abin.hpp"
#include <iostream>
//sense utilitzar recursivitat ni estructures de dades addicionals

template <typename T>
// Retorna una llista amb els elements de l'arbre en preordre
list<T> Abin<T>::preordre() const{
	//cout <<"preordre()   "<< endl;
	node *x = _arrel ;//,*anterior = NULL,x->f_esq == _arrel->info
	
	list<T> l;
	
	while(x != NULL){
		
		l.push_back(x->info);
		
		if(x->f_esq != NULL and not x->thread_esq){ //si tiene fill esq
			x = x->f_esq;
		}
		else if(x->f_dret != NULL and not x->thread_dret){ //si tiene fill esq
			x = x->f_dret;
		}
		else if(x->thread_dret){
	
			while( x->f_dret != NULL and x->thread_dret ){
				x = x->f_dret;
			}
			x = x->f_dret;
		}
	}
	
	return l;
}
