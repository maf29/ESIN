
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	string serie;
	while(getline(cin, serie)){
		
		istringstream s(serie);
		cua <int> c;
		
		int num;
		while(s >> num) c.encuar(num);
		
		int suma = 0;
		cua <int> c2;
		while(not c.es_buida()){
			int num = c.primer(); //coger el primer elemento de la cola
			if(suma >= num) c2.encuar(num); //Si la suma es mallor al numero que estamos tractando, se encua en la cola nueva
			
			suma += num;
			
			c.desencuar(); //ir desencuando para tractar el siguiente elemento de la cola
		}
		
		//IMPRIMIR
		while(not c2.es_buida()){
			cout << c2.primer();
			
			c2.desencuar();
			
			if(not c2.es_buida()) cout << " ";
		}
		
		cout << endl;
	}	
}
