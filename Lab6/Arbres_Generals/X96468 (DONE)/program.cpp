#include <cstdlib>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class Arbre {
 
 public:
   // Construeix un Arbre format per un únic node que conté a x.
   Arbre(const T &x);
 
   // Tres grans.
   Arbre(const Arbre<T> &a);
   Arbre& operator=(const Arbre<T> &a);
   ~Arbre() throw();
 
   // Col·loca l’Arbre donat com a primer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
   void afegir_fill(Arbre<T> &a);
 
   static const int ArbreInvalid = 400;
 
   // Retorna el nombre de fulles (nodes de grau 0) de l’arbre
   nat fulles() const;
 
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
   
 
   // Aquí va l’especificació dels mètodes privats addicionals
   static void fulles (nat &suma, node *x);
 };
//#############################################################################
 // Aquí va la implementació del mètode fulles
 template <typename T>
nat Arbre<T>::fulles() const{
	nat suma = 0;
	if(_arrel->primf != NULL or _arrel->primf != NULL)fulles (suma, _arrel);
	else if(_arrel != NULL) suma = 1;
	return suma;
}

template <typename T>
void Arbre<T>::fulles (nat &suma, node *x){
	if(x != NULL){
		if(x->primf == NULL) suma++;	//Sumar un uno por el arrel x
		
		//casos recursivos
		if(x->primf != NULL) fulles(suma, x->primf);
		if(x->seggerm != NULL) fulles(suma, x->seggerm);
		
	}
}
 //#############################################################################

