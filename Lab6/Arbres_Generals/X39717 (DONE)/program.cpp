#include "abin.hpp"
#include <iostream>
//sense utilitzar recursivitat ni estructures de dades addicionals

template <typename T>
// Retorna una llista amb els elements de l'arbre en preordre
list<T> Abin<T>::preordre() const{
	//cout <<"preordre()   "<< endl;
	node *x = _arrel, *anterior = NULL, ;//x->f_esq == _arrel->info
	
	list<T> l;
	typename list<T>::iterator it = l.begin();
	int contador = 0;
	bool trobat = false;
	bool subarbre_dret = false;
	
	while(x != NULL){
		//cout <<"x : "<< x->info << endl;
		it = l.insert(it, x->info);
		it++;
		
		
		if(x->info == _arrel->info and contador == 0){ cout <<"IF 1" << endl;
				contador++;
				//cout << x->f_esq->info;
				//if(x->f_esq == NULL and x->f_dret == NULL) cout <<"hijos vacíos"<<endl;
				anterior = x;
				x = x->f_esq;
				
				trobat = true;
				
		}
		else if (x->f_esq != NULL and x->f_dret != NULL){ cout <<"ELSE IF AMBOS NO VACIOS"<<endl;
			cout <<x->info <<"   der ->  "<<  x->f_dret->info<<"   izq ->" << x->f_esq->info <<endl;
			
			if(anterior_anterior != NULL and x->f_dret == anterior_anterior and x->f_esq == anterior){
				cout << "anterior_anterior : " << anterior_anterior->info << "     anterior : "<<anterior->info<<endl;
				anterior->info = anterior_anterior->info;
				anterior_anterior->info = _arrel->info;
				x = anterior->f_dret;
			}
			else { cout << "else"<<endl;
				anterior_anterior = anterior;
				anterior = x;
			}
			
		}	
		else if(x->f_esq != NULL){	//Si el fill esquerra seguent si existe
			cout <<"ELSE IF 1" << endl;
			anterior_anterior = anterior;
			anterior = x;
			cout <<x->info <<"   der ->  "<<  x->f_dret->info<<"   izq ->  "<<  x->f_esq->info<<endl;
			cout << "anterior_anterior : " << anterior_anterior->info << "     anterior : "<<anterior->info<<endl;
			x = x->f_esq;
			
			
		}
		else if(x->f_dret != NULL){	cout <<"ELSE IF 2" << endl;
			//anterior = x;
			anterior = x;
			x = x->f_dret;
			
			
		}
		cout << "x  : "<< x->info << endl;
		if(not trobat and x->info == _arrel->info and contador != 0 ){ cout <<"IF 2" << endl;
				if(subarbre_dret){
					//anterior = x;
					x = NULL;
				}
				else{
					subarbre_dret = true;
					//anterior = x;
					x = x->f_dret;	
				}
		}
		else { cout <<"ELSE 1" << endl;
			trobat = false;
		}
		//cout << x->info << endl;
	}
	//cout << "acabado bucle" << endl;
	
	return l;
}
