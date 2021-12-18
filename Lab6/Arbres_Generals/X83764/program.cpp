#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Arbre
{

public:
  // Construeix un Arbre format per un únic node que conté a x.
  Arbre(const T &x);

  // Tres grans.
  Arbre(const Arbre<T> &a);
  Arbre &operator=(const Arbre<T> &a);
  ~Arbre() throw();

  // Col·loca l’Arbre donat com a primer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
  void afegir_fill(Arbre<T> &a);

  // Imprimeix la informació dels nodes en preodre, cada element en una nova línia i
  // precedit per espais segons el nivell on està situat.
  void preordre() const;

  static const int ArbreInvalid = 400;

  // Elimina tots els nodes de grau 0 de l’arbre.
  void elimina_grau0();

private:
  Arbre() : _arrel(NULL){};
  struct node
  {
    T info;
    node *primf;
    node *seggerm;
  };
  node *_arrel;
  static node *copia_arbre(node *p);
  static void destrueix_arbre(node *p) throw();
  static void preordre(node *p, string pre);
  static node *eliminar(node *n);


  // Aquí va l’especificació dels mètodes privats addicionals
};

template <typename T>
void Arbre<T>::elimina_grau0(){
 node *n;
  if(_arrel != NULL){
    if(_arrel->primf == NULL){
      delete _arrel;
      _arrel = NULL;
    }else{
      n = eliminar(_arrel);
    }
  }

}

template <typename T>
typename Arbre<T>::node* Arbre<T>::eliminar(node *n){
	node *aux = NULL;
	//cout <<"n : "<< n->info << endl;
	if(n->primf == NULL){
		
		if(aux != NULL) aux = n->seggerm;
		
		destrueix_arbre(n);
		//n = aux;
		 
		
	}else{	//cout << "else"<<endl;
		if(n->primf != NULL){
			aux = eliminar(n->primf);
			
		}
		if(n->seggerm != NULL){
			aux = eliminar(n->seggerm);
			//n->seggerm = aux;
		}

	}
	//cout <<"fin"<<endl;
	return aux;
}

// Aquí va la implementació del mètode elimina_grau0

//****************************************************************************************
#include <iostream>
#include <stack>

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

template <typename T>	
void Arbre<T>::destrueix_arbre(node* p) throw() { 
  if (p != NULL) {
    destrueix_arbre(p -> primf);
    destrueix_arbre(p -> seggerm);
    delete p;
  }
}

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
void Arbre<T>::preordre(node *p, string pre) {
  if (p != NULL) {
    cout << pre << p->info << endl;
    preordre(p->primf, pre + "  ");
    preordre(p->seggerm, pre);
  }
}

template <typename T>
void Arbre<T>::preordre() const {
  preordre(_arrel, "");
}

// Llegeix un arbre general des de cin i el retorna.
Arbre<int> arbre() {
  int valor, nf;
  cin >> valor >> nf;
  Arbre<int> a(valor);
  stack<Arbre<int> > pa;
  while (nf>0) {
    pa.push(arbre());
    nf--;
  }
  while (not pa.empty()) {
    a.afegir_fill(pa.top());
    pa.pop();
  }
  return a;
}

int main() {
  Arbre<int> a(arbre());
  a.elimina_grau0();
  a.preordre();
  return 0;
}
