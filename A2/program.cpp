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
 
     // Modifica el contingut de l’arbre per tal de guardar a cada node l’altura
     // del seu subarbre.
     void arbre_altures();
 
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
     static void arbre_altures(node *now);
 };
 
 // Aquí va la implementació del mètode arbre_altures
 template <typename T>
void Abin<T>::arbre_altures(){
	arbre_altures(_arrel);
	//_arrel->info++;
}

template <typename T>
void Abin<T>::arbre_altures(node *now){

	if(now != NULL){//hi ha arbre
		//caso recursivo
		if(now->f_esq != NULL) arbre_altures(now->f_esq);
		if(now->f_dret != NULL) arbre_altures(now->f_dret);
		
		//caso base
		if(now->f_esq == NULL and now->f_dret == NULL) now->info = 1; 
		else {
			if(now->f_esq == NULL and now->f_dret != NULL)now->info = now->f_dret->info + 1;
			if(now->f_esq != NULL and now->f_dret != NULL and now->f_esq->info >= now->f_dret->info )now->info = now->f_esq->info + 1;
			else if (now->f_esq != NULL and now->f_dret != NULL and now->f_esq->info < now->f_dret->info) now->info = now->f_dret->info + 1;
			if(now->f_esq != NULL and now->f_dret == NULL)now->info = now->f_esq->info + 1;
		}
	}
}
