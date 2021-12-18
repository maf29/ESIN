#include <iostream>
#include "arbreBin.hpp"
using namespace std;

arbreBin<int> arbre_suma(arbreBin<int> A){
	arbreBin<int> B;
	int sum;
	if(not A.es_buit()){
		if(not (A.fe().es_buit() and A.fd().es_buit())){		//hijos no vacíos
			//crear casos recursivos de fe y fd para recorrrer el arbol A
			arbreBin<int> izq = arbre_suma(A.fe());
			arbreBin<int> der = arbre_suma(A.fd());
			
			int raiz = A.arrel();
					
			if(not izq.es_buit() and not der.es_buit()){	//ningun hijo es vacío
				sum = raiz + izq.arrel() + der.arrel();
			}
			else if (not izq.es_buit() and der.es_buit()){	//hijo derecho vacío
				sum = raiz + izq.arrel();
			}
			else if(izq.es_buit() and not der.es_buit()){	//hijo izquierdo vacío
				sum = raiz + der.arrel();
			}
			
			B = arbreBin<int>(sum, izq, der);	//Crear nodo B con su arrel y sus hijos
		}
		else{	//hijos vacíos
			arbreBin<int> izq;
			arbreBin<int> der;
			int raiz = A.arrel();
			
			B = arbreBin<int>(raiz, izq, der);	//Crear nodo B con su arrel y sus hijos
		
		}
	
	}

	return B;
}

int main(){
	arbreBin<int> A;
	cin >> A;
	arbreBin<int> B = arbre_suma(A);
	cout << B << endl;
	
}
