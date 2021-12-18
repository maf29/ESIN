#include "arbreBin.hpp"
#include <iostream>

using namespace std;


bool suma_fills(arbreBin<int> B){
	
	if(not B.es_buit() and (not B.fe().es_buit() or not B.fd().es_buit())){
		int izq = 0, der = 0;
		//caso base f_esq
		if(not B.fe().es_buit()) izq = B.fe().arrel();
		//caso base f_dret
		if(not B.fd().es_buit()) der = B.fd().arrel();
		
		int suma = izq + der;
		
		if(not (suma == B.arrel() and suma_fills(B.fe()) and suma_fills(B.fd()) ) ) return false;
		
	}
	
	return true;
}

int main(){
	arbreBin <int> A;
	cin >> A;
	cout << A << endl;
	
	if(suma_fills(A)) cout << "L'arbre compleix la propietat 'Suma dels fills'." << endl;
	else cout << "L'arbre no compleix la propietat 'Suma dels fills'." << endl;
	
}
