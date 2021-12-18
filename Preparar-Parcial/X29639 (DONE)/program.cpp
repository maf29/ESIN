#include <cstdlib>
#include <iostream>
 #include <vector>
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
 
   // Col·loca l’Arbre donat com a darrer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
   void afegir_darrer_fill(Arbre<T> &a);
 
   static const int ArbreInvalid = 400;
 
   // Retorna un vector amb les sumes de tots els elements de cada nivell.
   vector<T> sumes_nivells() const;
 
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
   static void sumes_nivells(node *now, vector<T> &v, nat n);
 };
 
 // Aquí va la implementació del mètode sumes_nivells
 template <typename T>
 vector<T> Arbre<T>::sumes_nivells() const{
 	vector<T> v;
 	nat nivel = 0;
 
 	sumes_nivells(_arrel, v, nivel);
 	return v;
 }
 
 template <typename T>
 void Arbre<T>::sumes_nivells(node *now, vector<T> &v, nat n) {
 	if(now != NULL){
 		if(v.size() > n) {
 			v[n] = v[n] + now->info;
 		}	
 		else v.push_back(now->info);
 		
 		sumes_nivells(now->primf, v, n+1);
 		sumes_nivells(now->seggerm, v, n);
 		
 	}
}
