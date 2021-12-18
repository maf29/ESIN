#include <cstdlib>
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
 
   // Retorna un vector amb les sumes de tots els elements de cada camí que va de l’arrel a una fulla.
   vector<T> sumes_camins() const;
 
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
   static void sumes_camins(node *now, vector<T> &v, T &suma);
 };
 
 // Aquí va la implementació del mètode sumes_camins
 template <typename T>
vector<T>  Arbre<T>::sumes_camins() const{
	vector<T> v;
	
	T suma = 0;
	sumes_camins(_arrel, v, suma);
	return v;
}
 template <typename T>
void Arbre<T>::sumes_camins(node *now, vector<T> &v, T &suma){
	if(now == NULL) v.push_back(suma);
	else{	
		T pf = suma;
		pf += now->info;	//si existe primer fill pasarle la suma del fill tambien
		
		sumes_camins(now->primf, v, pf);
		
		
		T sg = suma;//si no existe primer fill, el seggerm solo necesita el elemento de sum para seguir buscando si tiene fills
	
		if(now->seggerm != NULL)sumes_camins(now->seggerm, v, sg);
	}
}

