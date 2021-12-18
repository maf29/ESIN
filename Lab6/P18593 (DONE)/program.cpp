#include <iostream>
#include <cstddef>
using namespace std;

template <typename T>
class Arbre {
private:
  Arbre(): _arrel(NULL) {};
  struct node {
    T info;
    node* primf;
    node* seggerm;
  };
  node* _arrel;
  static node* copia_arbre(node* p);
  static void destrueix_arbre(node* p) throw(); 
//*********** AÑADIDOS ************
  static node* suma(node *A, node *B);	//AFEGIT
  static void preordre(node *A);
//*********************************

public:
//*********** AÑADIDOS ************
  void suma(const Arbre<T> &B);	//AFEGIT
  void preordre();
//*********************************

  // Construeix un Arbre format per un únic node que conté a x.
  Arbre(const T &x);

  // Tres grans.
  Arbre(const Arbre<T> &a);
  Arbre& operator=(const Arbre<T> &a);
  ~Arbre() throw();

  // Col·loca l'Arbre donat com a primer fill de l'arrel de l'arbre sobre el que s'aplica el mètode i l'arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
  void afegir_fill(Arbre<T> &a);

  // Iterador sobre arbre general.
  friend class iterador;
  class iterador {
  public:
    friend class Arbre;

    // Construeix un iterador no vàlid.
    iterador() throw();

    // Retorna el subarbre al que apunta l'iterador; llança un error si l'iterador no és vàlid.
    Arbre<T> arbre() const;

    // Retorna l'element del node al que apunta l'iterador o llança un error si l'iterador no és vàlid.
    T operator*() const;

    // Retorna un iterador al primogenit del node al que apunta; llança un error si l'iterador no és vàlid.
    iterador primogenit() const;

    // Retorna un iterador al següent germà del node al que apunta; llança un error si l'iterador no és vàlid.
    iterador seg_germa() const;

    // Operadors de comparació.
    bool operator==(const iterador &it) const {
      return _p == it._p;
    };
    bool operator!=(const iterador &it) const {
      return _p != it._p;
    };
    static const int IteradorInvalid = 410;

  private:
    Arbre<T>::node* _p;
  };
    
  // Retorna un iterador al node arrel de l'Arbre (un iterador no vàlid si l'arbre no és vàlid).
  iterador arrel() const throw();

  // Retorna un iterador no vàlid.
  iterador final() const throw();

  static const int ArbreInvalid = 400;
};

// La còpia es fa seguint un recorregut en preordre.
template <typename T>				
typename Arbre<T>::node* Arbre<T>::copia_arbre(node* p) { 
  node* aux = NULL;
  if (p != NULL) {
    aux = new node;
    try {
      aux -> info = p -> info;
      aux -> primf = aux -> seggerm = NULL;
      aux -> primf = copia_arbre(p -> primf);
      aux -> seggerm = copia_arbre(p -> seggerm);
    }
    catch (...) {
      destrueix_arbre(aux);
    }
  }
  return aux;
}

// La destrucció es fa seguint un recorregut en postordre.
template <typename T>	
void Arbre<T>::destrueix_arbre(node* p) throw() { 
  if (p != NULL) {
    destrueix_arbre(p -> primf);
    destrueix_arbre(p -> seggerm);
    delete p;
  }
}

// Construcció d'un arbre que conté un sol element x a l'arrel.
template <typename T>	
Arbre<T>::Arbre(const T &x) {
  _arrel = new node; 
  try {
    _arrel -> info = x;
    _arrel -> seggerm = NULL;
    _arrel -> primf = NULL;
  } 
  catch (...) {
    delete _arrel;
    throw;
  }
}

template <typename T>	
Arbre<T>::Arbre(const Arbre<T> &a) { 
  _arrel = copia_arbre(a._arrel);
}

template <typename T>	
Arbre<T>&  Arbre<T>::operator=(const Arbre<T> &a) { 
  Arbre<T> tmp(a);
  node* aux = _arrel;
  _arrel = tmp._arrel;
  tmp._arrel = aux;
  return *this;
}

template <typename T>	
Arbre<T>::~Arbre() throw() { 
  destrueix_arbre(_arrel);
}

template <typename T>	
void Arbre<T>::afegir_fill(Arbre<T> &a) { 
  if (_arrel == NULL or a._arrel == NULL or 
    a._arrel -> seggerm != NULL) {
    throw ArbreInvalid;
  }
  a._arrel -> seggerm = _arrel -> primf;
  _arrel -> primf = a._arrel;
  a._arrel = NULL;
}

template <typename T>
typename Arbre<T>::iterador Arbre<T>::arrel() const throw() { 
  iterador it;
  it._p = _arrel;
  return it;
}

template <typename T>	
typename Arbre<T>::iterador Arbre<T>::final() const throw() { 
  return iterador();
}

template <typename T>				
Arbre<T>::iterador::iterador() throw(): _p(NULL) { 
}

template <typename T>	
T Arbre<T>::iterador::operator*() const { 
  if (_p == NULL) {
    throw IteradorInvalid;
  }
  return _p -> info;
}

template <typename T>	
typename Arbre<T>::iterador Arbre<T>::iterador::primogenit() const { 
  if (_p == NULL) {
    throw IteradorInvalid;
  }
  iterador it;
  it._p = _p -> primf;
  return it;
}

template <typename T>	
typename Arbre<T>::iterador Arbre<T>::iterador::seg_germa() const { 
  if (_p == NULL) {
    throw IteradorInvalid;
  }
  iterador it;
  it._p = _p -> seggerm;
  return it;
}

template <typename T>	
Arbre<T> Arbre<T>::iterador::arbre() const { 
  if (_p == NULL) {
    throw IteradorInvalid;
  }
  Arbre<T> a;
  a._arrel = _p;
  Arbre<T> aux(a);
  a._arrel = NULL;
  return aux;
}

//******************************************************
#include <stack>
using namespace std;
Arbre<int> crear_arbre(){
	int info, num_fill;
	cin >> info >> num_fill;
	stack < Arbre<int> > pila;
	
	Arbre <int> aux(info);
	
	if(num_fill > 0){
		for(int i = 0; i < num_fill; i++){
			Arbre<int> fill = crear_arbre();
			pila.push(fill);
		}
		
		while(not pila.empty()){
			aux.afegir_fill(pila.top());
			pila.pop();	//desempilar
		}
		//cout << endl;
	}
	return aux;
}
// ################## PUBLICAS ##################
template <typename T>
void Arbre<T>::suma(const Arbre<T> &B){
	_arrel = suma(_arrel, B._arrel);
}

template <typename T>
void Arbre<T>::preordre(){
	preordre(_arrel);
}

// ################## PRIVADAS ##################
template <typename T>
typename Arbre<T>::node* Arbre<T>::suma(node *A, node *B){
	
	node *S = NULL;	//nodo auxiliar para luego enganchar con el arbol
	
	if(A != NULL and B != NULL){
		
		S = new node;
		S->info = A->info + B->info;
		S->primf = NULL; S->seggerm = NULL; //inicializar a NULL sus sucesores
		S->primf = suma(A->primf, B->primf);
		S->seggerm = suma(A->seggerm, B->seggerm);
	}
	else if (A != NULL and B == NULL){ //si el elemento B es NULL
		
		S = new node;
		S->info = A->info;
		S->primf = NULL; S->seggerm = NULL; //inicializar a NULL sus sucesores
		S->primf = suma(A->primf, S->primf);	//como no hay A, pasamos los parametros de B y el del nodo auxiliar S
		S->seggerm = suma(A->seggerm, S->seggerm);
	}
	else if(A == NULL and B != NULL){
		
		S = new node;
		S->info = B->info;
		
		S->primf = NULL; S->seggerm = NULL; //inicializar a NULL sus sucesores
		S->primf = suma(B->primf, S->primf);	//como no hay A, pasamos los parametros de B y el del nodo auxiliar S
		S->seggerm = suma(B->seggerm, S->seggerm);
		
	}
	
	return S;
}
template <typename T>
void Arbre<T>::preordre(node *A){
	if(A != NULL){
		cout <<" "<< A->info;
		preordre(A->primf);
		preordre(A->seggerm);
	}
}

// ############################################

int main(){
	int size;
	
	//leer A
	cin >> size;
	Arbre<int> A = crear_arbre();
	
	//leer B
	cin >> size;
	Arbre<int> B = crear_arbre();
	
	//hacer la suma del arbol A y B, y modificar el implicito (A)
	A.suma(B);
	
	//imprimir recorregut en preordre
	A.preordre();
	cout << endl;
}

