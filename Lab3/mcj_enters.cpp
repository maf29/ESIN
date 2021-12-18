#include <iostream>
#include "mcj_enters.hpp"
using namespace std;


/*		public:		*/

  // Constructora per defecte. Crea un multiconjunt buit.
  mcj_enters::mcj_enters(){
  	fantasma = new nodo{0, NULL};
  	prim = NULL;
  	ult = NULL;
  }

  // Les tres grans: Constructora per còpia, destructora, operador d'assignació
  mcj_enters::mcj_enters(const mcj_enters &cj){
  	
  	//Inicializar los elementos de una lista;
 	fantasma = new nodo{0, NULL};
  	prim = NULL;
  	ult = NULL;
  	
  	mcj_enters *mcj = new mcj_enters();
  	nodo *M = cj.prim;	//Guardar en el nodo M el primer elemento de la lista cj
  	
  	while(M != NULL){ //Mientras no llegar al ultimo elemento de la lista
  		mcj->insereix(M->info);	//insertar el elemento que apunta B;
  		if(M != NULL){
  			if(M != M->sig) M = M->sig; //Apuntar al siguiente elemento
  			else M = NULL;
  		}
  	}
  	
  	nodo *aux = fantasma;
  	fantasma = mcj->fantasma;
  	mcj->fantasma = aux;
  	
  	mcj->prim = prim;
  	prim = fantasma->sig;	//Apuntar al primer elemento que esta despues del fantasma de la lista p.i
  	
  	aux = ult;
  	ult = mcj->ult;  //Ultimo = ultimo de mcj
  	mcj->ult = aux;	//Guardar en la lista mcj el ultimo elemento de la lista p.i
  }
  
  mcj_enters::~mcj_enters(){
  	nodo *anterior = fantasma;
  	while(anterior != NULL){
  		prim = anterior->sig; //Guardar en prim el primer elemento de la lista
  		delete anterior; //Eliminar el elemento anterior para vaciar la lista
  		anterior = prim;
  	}
  	//Poner a null el primer y ultimo elemento para que sea una lista 
  	prim = NULL;
  	ult = NULL; 
  }
  
  mcj_enters& mcj_enters::operator=(const mcj_enters &cj){
  	if(this != &cj){ //Mientras no sean iguales, hacer la copa de cj en this
  		mcj_enters *mcj = new mcj_enters(cj); //Llamar a la constructora por copia
  		
  		//
  		nodo *aux = fantasma;
	  	fantasma = mcj->fantasma;
	  	mcj->fantasma = aux;
	  	
	  	mcj->prim = prim;
	  	prim = fantasma->sig;	//Apuntar al primer elemento que esta despues del fantasma de la lista p.i
	  	
	  	aux = ult;
	  	ult = mcj->ult;  //Ultimo = ultimo de mcj
	  	mcj->ult = aux;	//Guardar en la lista mcj el ultimo elemento de la lista p.i		
  	}
  	return *this;
  }

  // Insereix l’enter e en el multiconjunt.
  void mcj_enters::insereix(int e){                 //DONE
  
  /*
  	Se puede hacer de la siguiente forma.
  		recorrer desde el final, y ir desplazando una posicion todos los elementos una posicion a la dercha y asi es mas rapido y eficiente porque es un coste lineal 
  */
  
  	if(card() == 0){ //Este no hace falta, tendria que entrar dentro del while
  		fantasma->sig = new nodo{e, NULL};
  		prim = fantasma->sig;
  		ult = fantasma->sig;
  	}
  	else{
  		
	  	
  		 if(e <= prim->info){ //si e es igual que el elemento al que estamos tractando
  		 	fantasma->sig = new nodo{e, NULL};
  		 	prim = fantasma->sig;
  		 }
  		 //Los casos == y > van en un mismo caso 
  		else if(e > ult->info){ //si e es mayor que el elemento del elemento de la lista que estamos tractando
  			ult->sig = new nodo{e, NULL};
  			if(ult != NULL){ //Insertar e al final de la lista
  				if(ult != ult->sig) ult = ult->sig;
  				else ult = NULL;
  			}
  		}
  		
  		else{ //si e es un numero entre dos numeros de la lista
  			nodo *anterior = prim;
  			nodo *aux = prim->sig;
  			
  			bool insertado = false;
  			while(aux != NULL and not insertado){
  				if(aux != NULL){
  					if(aux->info >= e){
  						anterior->sig = new nodo{e, NULL};
  						insertado = true;
  					}
  					else{
  						if(anterior != NULL){ 
			  				if(anterior != anterior->sig) anterior = anterior->sig;
			  				else anterior = NULL;
			  			}
			  			if(aux != NULL){ //Insertar e al final de la lista
			  				if(aux != aux->sig) aux = aux->sig;
			  				else aux = NULL;
			  			}	
  					}
  				}
  			}
  		}
	  		  	
  	}
  	
  	++fantasma->info;
  }

  // Unió, intersecció i diferència de multiconjunts. Operen modificant el multiconjunt sobre el que s’aplica
  // el mètode, usant el segon multiconjunt com argument. P.e.: a.restar(b) fa que el nou valor d’a sigui
  // A - B, on A i B són els valors originals dels objectes a i b.
  void mcj_enters::unir(const mcj_enters& B){			 //DONE
	mcj_enters A; 
	
	/*Antes lo tenía como : *A = new mcj_enters(); esta mal hecho porque una vez que acaba la funcion queda guardada la memoria grosa porque es un puntero, y 			todo a lo que apunta el puntero queda guardado en la memoria, por lo tanto se ha de cambiar a una variable de la clase mcj_enters para que se 			destruya la memoria luego
	
				TODOS LOS QUE SON A-> SON A.  
	*/
	
	if(card() == 0){
		
	}
	else if (card() > 0 and B.card() > 0){
		nodo *aux1 = prim, *aux2 = B.prim;
		
		while (aux1 != NULL and aux2 != NULL){
			if (aux1->info > aux2->info) {
				A->insereix(aux2->info);
				if(aux2 != NULL){ 
	  				if(aux2 != aux2->sig) aux2 = aux2->sig;
	  				else aux2 = NULL;
	  			}
			}else if (aux1->info < aux2->info){
				A->insereix(aux1->info);
				if(aux1 != NULL){ 
	  				if(aux1 != aux1->sig) aux1 = aux1->sig;
	  				else aux1 = NULL;
	  			}
			}else{
				A->insereix(aux1->info);
				if(aux1 != NULL){ 
	  				if(aux1 != aux1->sig) aux1 = aux1->sig;
	  				else aux1 = NULL;
	  			}
	  			if(aux2 != NULL){ 
	  				if(aux2 != aux2->sig) aux2 = aux2->sig;
	  				else aux2 = NULL;
	  			}
			}
		}
		while (aux1 != NULL){ //si aux2 ya esta vacio
			//No se ouede hacer unsereix porque luego se crea un coste cuadratico, es decir esta funcion recorre el vector e insereix tambien recorre el vector de nuevo, por lo tanto se recorre 2 veces
			A->insereix(aux1->info);
			if(aux1 != NULL){ 
  				if(aux1 != aux1->sig) aux1 = aux1->sig;
  				else aux1 = NULL;
  			}
		}
		while (aux2 != NULL){ //si aux1 ya esta vacio
			A->insereix(aux2->info);
			if(aux2 != NULL){ 
  				if(aux2 != aux2->sig) aux2 = aux2->sig;
  				else aux2 = NULL;
  			}
		}
		
		// no hacia falta, solo con poner el A ya se guardaria en el parametro implicito
		mcj_enters *mcj = new mcj_enters();
	  	nodo *M = A->prim;	//Guardar en el nodo M el primer elemento de la lista cj
	  	
	  	while(M != NULL){ //Mientras no llegar al ultimo elemento de la lista
	  		mcj->insereix(M->info);	//insertar el elemento que apunta B;
	  		if(M != NULL){
	  			if(M != M->sig) M = M->sig; //Apuntar al siguiente elemento
	  			else M = NULL;
	  		}
	  	}
	  	//
	  	
	  	//profe : *this = A;  yo: este trozo de codigo de abajo equivale a asigranle el parametro implicito a A
	  	nodo *aux = fantasma;
	  	fantasma = mcj->fantasma;
	  	mcj->fantasma = aux;
	  	
	  	mcj->prim = prim;
	  	prim = fantasma->sig;	//Apuntar al primer elemento que esta despues del fantasma de la lista p.i
	  	
	  	aux = ult;
	  	ult = mcj->ult;  //Ultimo = ultimo de mcj
	  	mcj->ult = aux;	//Guardar en la lista mcj el ultimo elemento de la lista p.i
	}
	
  }
  
  void mcj_enters::intersectar(const mcj_enters& B){
  	nodo *aux1 = prim, *aux2 = B.prim, *anterior = fantasma;
  	
	while (aux1 != NULL and aux2 != NULL ){ //mientras no llegar al final de ambas listas
		
		if (aux1->info == aux2->info){ //Si son el mismo numero 
			//tratar nodo anterior 
			if(anterior != NULL){
	  			if(anterior != anterior->sig) anterior = anterior->sig; //Apuntar al siguiente elemento
	  			else anterior = NULL; //Si el sigueinte al anterior es igual al p.i, lo ponemos a null
	  		}
			//tratar aux1
			if(aux1 != NULL){
	  			if(aux1 != aux1->sig) aux1 = aux1->sig; //Apuntar al siguiente elemento
	  			else aux1 = NULL; //Si el sigueinte al aux1 es igual al p.i de aux1, lo ponemos a null
	  		}
			//tratar aux2
			if(aux2 != NULL){
	  			if(aux2 != aux2->sig) aux2 = aux2->sig; //Apuntar al siguiente elemento
	  			else aux2 = NULL; //Si el sigueinte al aux2 es igual al p.i de aux2, lo ponemos a null
	  		}
		}
		else if(aux1->info < aux2->info){
			//eliminar el elemento p.i de aux1
			if(aux1 == prim){
				prim = aux1->sig;
				anterior->sig = prim; //Ponerle como primer elemento de la lista el elemento prim
				
				if(aux1 == ult) ult = NULL; //Si el primer elemento y el ultimo elemento son iguales 
			}
			else if (aux1 == ult){
				ult = anterior;
				ult->sig = NULL;
			}
			else anterior->sig = aux1->sig;
			
			delete aux1;
			aux1 = anterior;
			if(fantasma != NULL and fantasma->info > 0) --fantasma->info;
			
			//tratar aux1
			if(aux1 != NULL){
	  			if(aux1 != aux1->sig) aux1 = aux1->sig; //Apuntar al siguiente elemento
	  			else aux1 = NULL; //Si el sigueinte al aux1 es igual al p.i de aux1, lo ponemos a null
	  		}

		}
		else{ //aux1->info > aux2->info
		
			//tratar aux2
			if(aux2 != NULL){
	  			if(aux2 != aux2->sig) aux2 = aux2->sig; //Apuntar al siguiente elemento
	  			else aux2 = NULL; //Si el sigueinte al aux2 es igual al p.i de aux2, lo ponemos a null
	  		}
		}
	} 
	while(aux1 != NULL){ //Si todavia quedan elementos por tractar en la lista p.i
		//eliminar el elemento p.i de aux1
		if(aux1 == prim){
			prim = aux1->sig;
			anterior->sig = prim; //Ponerle como primer elemento de la lista el elemento prim
			
			if(aux1 == ult) ult = NULL; //Si el primer elemento y el ultimo elemento son iguales 
		}
		else if (aux1 == ult){
			ult = anterior;
			ult->sig = NULL;
		}
		else anterior->sig = aux1->sig;
		
		delete aux1;
		aux1 = anterior; 
		if(fantasma != NULL and fantasma->info > 0) --fantasma->info;
		
		//tratar aux1
		if(aux1 != NULL){
  			if(aux1 != aux1->sig) aux1 = aux1->sig; //Apuntar al siguiente elemento
  			else aux1 = NULL; //Si el sigueinte al aux1 es igual al p.i de aux1, lo ponemos a null
  		}
		
	} 	
  	
  }
  void mcj_enters::restar(const mcj_enters& B){
  	nodo *aux1 = prim, *aux2 = B.prim, *anterior = fantasma;
  	
	while (aux1 != NULL and aux2 != NULL ){ //mientras no llegar al final de ambas listas
		
		if (aux1->info == aux2->info){ //Si son el mismo numero 
			//eliminar el elemento p.i de aux1
			
			if(aux1 == prim){
				prim = aux1->sig;
				anterior->sig = prim; //Ponerle como primer elemento de la lista el elemento prim
				
				if(aux1 == ult) ult = NULL; //Si el primer elemento y el ultimo elemento son iguales 
			}
			else if (aux1 == ult){
				ult = anterior;
				ult->sig = NULL;
			}
			else anterior->sig = aux1->sig;
			
			delete aux1;
			aux1 = anterior;
			if(fantasma != NULL and fantasma->info > 0) --fantasma->info;
			
			
			//tratar aux1
			if(aux1 != NULL){
	  			if(aux1 != aux1->sig) aux1 = aux1->sig; //Apuntar al siguiente elemento
	  			else aux1 = NULL; //Si el sigueinte al aux1 es igual al p.i de aux1, lo ponemos a null
	  		}
			//tratar aux2
			if(aux2 != NULL){
	  			if(aux2 != aux2->sig) aux2 = aux2->sig; //Apuntar al siguiente elemento
	  			else aux2 = NULL; //Si el sigueinte al aux2 es igual al p.i de aux2, lo ponemos a null
	  		}
		}
		else if(aux1->info < aux2->info){
			//tratar nodo anterior 
			if(anterior != NULL){
	  			if(anterior != anterior->sig) anterior = anterior->sig; //Apuntar al siguiente elemento
	  			else anterior = NULL; //Si el sigueinte al anterior es igual al p.i, lo ponemos a null
	  		}
			
			//tratar aux1
			if(aux1 != NULL){
	  			if(aux1 != aux1->sig) aux1 = aux1->sig; //Apuntar al siguiente elemento
	  			else aux1 = NULL; //Si el sigueinte al aux1 es igual al p.i de aux1, lo ponemos a null
	  		}

		}
		else{ //aux1->info > aux2->info
		
			//tratar aux2
			if(aux2 != NULL){
	  			if(aux2 != aux2->sig) aux2 = aux2->sig; //Apuntar al siguiente elemento
	  			else aux2 = NULL; //Si el sigueinte al aux2 es igual al p.i de aux2, lo ponemos a null
	  		}
		}
	}
  }

  // Unió, intersecció i diferència de multiconjunts. Operen creant un nou multiconjunt sense modificar el con-
  // junt sobre el que s’aplica el mètode. La suma de multiconjunts correspon a la unió, la resta a la
  // diferència i el producte a la intersecció.
  mcj_enters mcj_enters::operator+(const mcj_enters &B) const{		//DONE
  	mcj_enters *aux = new mcj_enters(*this); //Hacer uan copia de la lista p.i en la lista aux
    	aux->unir(B);
    	return *aux;
  }
  mcj_enters mcj_enters::operator*(const mcj_enters& B) const{		//DONE
  	mcj_enters *aux = new mcj_enters(*this); //Hacer uan copia de la lista p.i en la lista aux
    	aux->intersectar(B);
    	return *aux;
  }
  mcj_enters mcj_enters::operator-(const mcj_enters& B) const{		//DONE
  	mcj_enters *aux = new mcj_enters(*this); //Hacer uan copia de la lista p.i en la lista aux
    	aux->restar(B);
    	return *aux;
  }

  // Retorna cert si i només si e pertany al multiconjunt.
  bool mcj_enters::conte(int e) const{			//DONE
  	bool trobat = false;
	if((prim != NULL) and (e >= min() and e <= max()) ){ //Si el elemnto se encuentra entre el min y el max
		nodo *aux = prim;
		while ( aux != NULL and not trobat) {
			if (aux->info == e) trobat = true;
			
			if(aux != NULL) aux = aux->sig;
		}
	}
	return trobat;
  }

  // Retornen els elements màxim i mínim del multiconjunt, respectivament.
  // El seu comportament no està definit si el multiconjunt és buit.
  int mcj_enters::max() const{		//DONE
  	if (ult != NULL) return ult->info;
    
    	return 0;
  }
  int mcj_enters::min() const{        //DONE
  	if (prim != NULL) return prim->info;
  	
    	return 0;
  }

  // Retorna el nombre d’elements (la cardinalitat) del multiconjunt.
  int mcj_enters::card() const{ 		//DONE
  	if (fantasma != NULL) return fantasma->info;
  	
    	return 0;
  }

  // Operadors relacionals. == retorna cert si i només si els
  // dos multiconjunts (el paràmetre implícit i B) contenen els
  // mateixos elements; != retorna cert si i només si els
  // multiconjunts són diferents.
  bool mcj_enters::operator==(const mcj_enters& B) const{      //DONE
  	bool stop = true;
	if (card() != B.card()){ //Si la mida no es igyal, por lo tanto las listas no son iguales
		stop = false; 
	}
	else{
		nodo *ini = prim, *fin = B.prim;
		
		while ( ( ini != NULL and fin != NULL ) and stop){
			if (ini->info != fin->info) stop = false;
			
			if(ini != NULL) ini = ini->sig;  //Seguir tractando los elementos de la lista p.i
			if(fin != NULL) fin = fin->sig;  //Seguir tractando los elementos de la lista B
		}
	}
    	return stop;
  }
  bool mcj_enters::operator!=(const mcj_enters& B) const{		//DONE
  	return not (*this == B);
  }

  // Imprimeix el multiconjunt d’enters, ordenats en ordre ascendent, sobre
  // el canal de sortida os; el format és [e1 e2 ... en], és a dir, amb
  // espais entre els elements i tancant la seqüència amb corxets.
  void mcj_enters::print(ostream& os) const{ 
  	 os << "[";
  	 nodo *aux = prim;
  	 
  	 while(aux != NULL){
  	 	os << aux->info;
  	 	aux = aux->sig;
		if (aux != NULL) os << " ";
  	 }
	os << "]";
  }

