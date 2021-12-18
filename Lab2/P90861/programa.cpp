#ifndef _CUA_HPP
#define _CUA_HPP
#include <cstddef>
using namespace std;

template <typename T>
class cua {
private: 
  struct node {
    T info;
    node* seg;
  };
  node* _cua;

  node* copiar(node* n, node* fi, node* ini);

public:
  // Construeix una cua buida.
  cua();

  // Tres grans: constructora per còpia, operador d'assignació i destructora.
  cua(const cua<T> &c);
  cua<T>& operator=(const cua<T> &c);
  ~cua() throw();

  // Afegeix un element al final de la cua. 
  void encuar(const T &x);

  // Treu el primer element de la cua. Llança un error si la cua és buida.
  void desencuar();

  // Obté el primer element de la cua. Llança un error si la cua és buida.
  const T& primer() const;

  // Consulta si la cua és buida o no.
  bool es_buida() const throw();

  static const int CuaBuida = 310;
};


#endif
template <typename T>
cua<T>::cua() : _cua(NULL) {   
}

template <typename T>
cua<T>::cua(const cua<T> &c) : _cua(NULL) {
  if (c._cua != NULL) {
    _cua = new node;
    try {
      _cua->info = c._cua->info;
      _cua->seg = copiar(c._cua->seg, c._cua, _cua);
    }
    catch (...) {
      delete(_cua);
      throw;
    }
  }
}

template <typename T>
typename cua<T>::node* cua<T>::copiar(node* n, node* fi, node* ini) {
  node* aux;
  if (n != fi) {
    aux = new node;
    try {
      aux->info = n->info;
      aux->seg = copiar(n->seg, fi, ini); 
    }
    catch (...) {
      delete aux;
      throw;
    }
  }
  else {
    aux = ini;
  }
  return aux;
}

template <typename T>
cua<T>& cua<T>::operator=(const cua<T> &c) {
  if (this != &c) {
    cua<T> caux(c);
    node* naux = _cua;
    _cua = caux._cua;
    caux._cua = naux;
  }
  return *this;
}

template <typename T>
cua<T>::~cua() throw() {
  if (_cua != NULL) {
    node* fi = _cua;
    _cua = _cua->seg;
    while (_cua != fi) {
      node* aux = _cua;
      _cua = _cua->seg;
      delete aux;
    }
    delete(_cua);
  }
}

template <typename T>
void cua<T>::encuar(const T &x) {
  node* p = new(node); 
  try {
    p->info = x;
  }
  catch (...) {
    delete p;
    throw;
  }
  if (_cua == NULL) {
    p->seg = p;  // cua amb un únic element que s’apunta 
  }              // a sí mateix
  else {
    p->seg = _cua->seg;
    _cua->seg = p;
  }
  _cua = p;
}

template <typename T>
void cua<T>::desencuar() { 
  if (_cua==NULL) {
    throw CuaBuida;
  }
  node* p = _cua->seg;
  if (p == _cua) {
    _cua = NULL; // desencuem una cua que tenia un únic 
  }              // element
  else {  
    _cua->seg = p->seg;
  }
  delete(p);
}

template <typename T>
const T& cua<T>::primer() const { 
  if (_cua==NULL) { 
    throw CuaBuida;
  }
  return (_cua->seg->info);
}

template <typename T>
bool cua<T>::es_buida() const throw() {  
  return (_cua==NULL);
}
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


int main(){
	string s;
	
	getline (cin, s); //Lee la mida de cues
	istringstream ss(s);
	
	int num;
	ss>>num; //convertir string de numero de cues en int para saber cuantas colas tenemos
	
	vector < cua<string> > cues;   //creamos un vector con la mida de personas que caben
	for(int i = 0; i < num; i++){
		
		getline (cin, s);	//Leer lista de nombres de la cola
		istringstream ss(s);
		
		string nombre;
		cua <string> nom_cola;
		
		//Deshacer la lista de nombres de eprsonas y poner cada nombre en una posicion de la cola
		while(ss>>nombre){ //Cada vez que se lea una string se guarda en nombre
			nom_cola.encuar(nombre); //Se guarda en la cola de nombres nom_cola
		}
		cues.push_back(nom_cola); //guardar la cola como posicion del vector cues		
	}
	
	
	cout<<"SORTIDES"<<endl;
	cout<<"--------"<<endl;
	while(getline(cin, s)){
		istringstream ss(s);
		
		string estado;
		ss>>estado; //en estado se guarda SURT o ENTRA
		
		
		if(estado == "SURT"){ //Si hay que eliminar el primero de la cola
			int n;
			ss>>n;
			n--; //Para acceder a la posicion del vector correspondiente
			if(n >= 0 and n < num ){ //Si n es menor que el numero de cues introducides 
				if(not cues[n].es_buida()){ //Mirar si esa cola esta vacia
					cout << cues[n].primer() << endl; //Imprimir el front de la cola
					cues[n].desencuar(); //Borrar nombre de la cola
				}
			
			}
		}
		else if(estado == "ENTRA"){ //Si hay que añadir a alguien al final de la cola
			string nombre;
			ss>>nombre;
			
			int n;
			ss>>n;
			n--;
			if(n >= 0 and n < num ){ //Si n es menor que el numero de cues introducides
				cues[n].encuar(nombre); //Poner un nombre en la cola
			}
		}
	}
	
	cout << endl;
	cout << "CONTINGUTS FINALS" << endl;
	cout << "-----------------" << endl;
		
	for(int i = 0; i < num; i++){
		cout << "cua " << i+1 << ":";
		while(not cues[i].es_buida()){ 
			cout << " " << cues[i].primer();	//Imprimir los nombre de la cola
			cues[i].desencuar();	//eliminar nombre de la cola 
		}
		cout<<endl;
	}

}
