#include <iostream>
#include "mcj_enters.hpp"
using namespace std;


/*		public:		*/

  // Constructora per defecte. Crea un multiconjunt buit.
  mcj_enters::mcj_enters(){
  	size = 0;
  }

  // Les tres grans: Constructora per còpia, destructora, operador d'assignació
  mcj_enters::mcj_enters(const mcj_enters &cj){
  	
 
  	for(int i = 0; i < cj.size; ++i){
  		mcj[i] = cj.mcj[i];
  	}
  	
  	size = cj.size;
  }
  
  mcj_enters::~mcj_enters(){
  	size = 0;
  	mcj[0] = 0;
  }
  
  mcj_enters& mcj_enters::operator=(const mcj_enters &cj){
  	for(int i = 0; i < cj.size; ++i){
  		mcj[i] = cj.mcj[i];
  	}
  	size = cj.size;
  	return *this;
  }

  // Insereix l’enter e en el multiconjunt.
  void mcj_enters::insereix(int e){                 //DONE
  
  /*
  	Se puede hacer de la siguiente forma.
  		recorrer desde el final, y ir desplazando una posicion todos los elementos una posicion a la dercha y asi es mas rapido y eficiente porque es un coste lineal 
  */
  	bool encontrado = false;
  	
  	if(size == 0){ //Este no hace falta, tendria que entrar dentro del while
  		mcj[0] = e;
  		++size;
  	}
  	else{
  		int i = 0;

	  	while(i < size and not encontrado){
	  		 if(e == mcj[i]){ //si e es igual que el elemento al que estamos tractando
	  		 	int aux = mcj[i+1];
	  		 	int aux2;
	  		 	mcj[i+1] = e;
	  		 	
	  			size++;
	  			i++;
	  			for(int j = i+1; j < size; j++){
	  				aux2 = mcj[j];
	  				mcj[j] = aux; 
	  				aux = aux2;; 
	  			}
	  			encontrado = true;
	  			
	  			
	  		 }
	  		 //Los casos == y > van en un mismo caso 
	  		else if(e > mcj[i] and size == i+1){ //si e es mayor que el elemento del array que estamos tractando
	  			mcj[i+1] = e;
	  			size++;
	  			i++;
	  			encontrado = true;
				
	  		}
	  		else if(e <= mcj[i]){ //si e es menor que el primer elemento del array
	  			int aux = mcj[i];
	  			int aux2;
	  			mcj[i] = e;
	  			size++;

	  			for(int j = i + 1; j < size; j++){
	  				aux2 = mcj[j];
	  				mcj[j] = aux;
	  				aux = aux2;	
	  			}
	  			encontrado = true;
				
	  		}
	  		else if(e > mcj[i] and (i+1 != size and mcj[i+1] > e)){ //si e es un numero entre dos numeros del array
	  			int aux = mcj[i+1], aux2;
	  			mcj[i+1] = e;
	  			size++;
	  			i++;
	  			for(int j = i+1; j < size; j++){
	  				aux2 = mcj[j];
	  				mcj[j] = aux;
	  				aux = aux2;
	  			}
	  			encontrado = true;

	  		}
	  		i++;

	  	}
  	}
  }

  // Unió, intersecció i diferència de multiconjunts. Operen modificant el multiconjunt sobre el que s’aplica
  // el mètode, usant el segon multiconjunt com argument. P.e.: a.restar(b) fa que el nou valor d’a sigui
  // A - B, on A i B són els valors originals dels objectes a i b.
  void mcj_enters::unir(const mcj_enters& B){			 //DONE
	if(size == 0){
		*this = B;
	}else if (size != 0 and B.size != 0){
		mcj_enters result;
		int i = 0, j = 0;
		while (i < size and j < B.size ){
			if (mcj[i] == B.mcj[j]) {
				result.mcj[result.size] = mcj[i];
				++result.size;
				++i;
				++j;
			}else if (mcj[i] < B.mcj[j]){
				result.mcj[result.size] = mcj[i];
				++result.size;
				++i;
			}else{
				result.mcj[result.size] = B.mcj[j];
				++result.size;
				++j;
			}
		}
		while (i < size){
			result.mcj[result.size] = mcj[i];
			++result.size;
			++i;
		}
		while (j < B.size){
			result.mcj[result.size] = B.mcj[j];
			++result.size;
			++j;
		}

		*this = result;
	}
  }
  void mcj_enters::intersectar(const mcj_enters& B){
  
  	if(mcj == B.mcj) *this = B;
  	else{
  		mcj_enters result;
		int i = 0, j = 0;
		while (i < size and j < B.size ){
			if (mcj[i] == B.mcj[j]) {
				result.mcj[result.size] = mcj[i];
				++result.size;
				++i;
				++j;
			}
			else if(mcj[i] < B.mcj[j])++i;
			else ++j;
		}
		*this = result;
  	}
  	
  	
  }
  void mcj_enters::restar(const mcj_enters& B){
  	mcj_enters x;
  	if(mcj == B.mcj or size == 0) *this = x;
  	else if (size > 0 and B.size > 0){
  		mcj_enters result;
		int i = 0, j = 0;
		while (i < size and j < B.size ){
			if (mcj[i] < B.mcj[j]){
				result.mcj[result.size] = mcj[i];
				++result.size;
				++i;
				
			}else if(mcj[i] > B.mcj[j])   ++j;
			else{
				++i; 
				++j;
			}
		}
		
		//si quedan elementos por tractar y no se comparan, añadirlos al final
		while(i < size){
			result.mcj[result.size] = mcj[i];
			++result.size;
			++i;
		}
		
		*this = result;
  	}
  }

  // Unió, intersecció i diferència de multiconjunts. Operen creant un nou multiconjunt sense modificar el con-
  // junt sobre el que s’aplica el mètode. La suma de multiconjunts correspon a la unió, la resta a la
  // diferència i el producte a la intersecció.
  mcj_enters mcj_enters::operator+(const mcj_enters& B) const{		//DONE
  	mcj_enters aux = *this;
    	aux.unir(B);
    	return aux;
  }
  mcj_enters mcj_enters::operator*(const mcj_enters& B) const{		//DONE
  	mcj_enters aux = *this;
    	aux.intersectar(B);
    	return aux;
  }
  mcj_enters mcj_enters::operator-(const mcj_enters& B) const{		//DONE
  	mcj_enters aux = *this;
    	aux.restar(B);
    	return aux;
  }

  // Retorna cert si i només si e pertany al multiconjunt.
  bool mcj_enters::conte(int e) const{			//DONE
  	bool trobat = false;
	int i = 0;
	while ( i < size and not trobat) {
		if (mcj[i] == e) trobat = true;
		++i;
	}
	return trobat;
  }

  // Retornen els elements màxim i mínim del multiconjunt, respectivament.
  // El seu comportament no està definit si el multiconjunt és buit.
  int mcj_enters::max() const{		//DONE
  	if (size > 0){
        	return mcj[size-1];
    	}
    	return 0;
  }
  int mcj_enters::min() const{        //DONE
  	return mcj[0];
  }

  // Retorna el nombre d’elements (la cardinalitat) del multiconjunt.
  int mcj_enters::card() const{ 		//DONE
  	return size;
  }

  // Operadors relacionals. == retorna cert si i només si els
  // dos multiconjunts (el paràmetre implícit i B) contenen els
  // mateixos elements; != retorna cert si i només si els
  // multiconjunts són diferents.
  bool mcj_enters::operator==(const mcj_enters& B) const{      //DONE
  	bool stop = true;
	if (size != B.size){
		stop = false; 
	}
	else{
		int i=0;
		while ( i < B.size and stop){
			if (mcj[i] != B.mcj[i]){
				stop = false;
			}
			
			i++;
		}
	}
    	return stop;
  }
  bool mcj_enters::operator!=(const mcj_enters& B) const{		//DONE
  	return not (*this==B);
  }

  // Imprimeix el multiconjunt d’enters, ordenats en ordre ascendent, sobre
  // el canal de sortida os; el format és [e1 e2 ... en], és a dir, amb
  // espais entre els elements i tancant la seqüència amb corxets.
  void mcj_enters::print(ostream& os) const{ 
  	 os << "[";
	    for (int i = 0; i <= size-1; ++i) {
		os << mcj[i];
		if (i < size - 1) os << " ";
	    }
	    os << "]";
  }

