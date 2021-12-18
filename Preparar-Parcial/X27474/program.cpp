#include <cstdlib>
 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class Abin {
   public:
     Abin(): _arrel(NULL) {};
     // Pre: cert
     // Post: el resultat és un arbre sense cap element
     Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
     // Pre: cert
     // Post: el resultat és un arbre amb un element i dos subarbres
 
     // Les tres grans
     Abin(const Abin<T> &a);
     ~Abin();
     Abin<T>& operator=(const Abin<T>& a);
 
     // operador << d’escriptura
     template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);
 
     // operador >> de lectura
     template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);
 
     // Modifica el contingut de l’arbre per tal de guardar a cada node la quantitat de
     // nodes del seu subarbre.
     void arbre_quantitats();
 
   private:
     struct node {
       node* f_esq;
       node* f_dret;
       T info;
     };
     node* _arrel;
     static node* copia_nodes(node* m);
     static void esborra_nodes(node* m);
     static void print_nodes(node* m, ostream &os, string d1);
 
     // Aquí va l’especificació dels mètodes privats addicionals
     static void arbre_quantitats(node *now);
 };
 
 // Aquí va la implementació del mètode arbre_quantitats
template <typename T>
void Abin<T>::arbre_quantitats(){
	 arbre_quantitats(_arrel);
}

template <typename T>
void Abin<T>::arbre_quantitats(node *now){
	if(now != NULL){
		arbre_quantitats(now->f_esq);
		arbre_quantitats(now->f_dret);
		
		if(now->f_esq == NULL and now->f_dret == NULL) now->info = 1;
		else if(now->f_esq != NULL and now->f_dret != NULL) now->info = now->f_esq->info + now->f_dret->info + 1;
		else if(now->f_esq == NULL and now->f_dret != NULL) now->info = now->f_dret->info + 1;
		else now->info = now->f_esq->info + 1;
	}
}

