#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
typedef unsigned int nat;
 
 				//HACER CON BST	
 
template <typename Clau>
class dicc {

	public:
		// Constructora per defecte. Crea un diccionari buit.
		dicc();

		// Les tres grans: Constructora per còpia, destructora, operador d’assignació
		dicc(const dicc &d);
		~dicc();
		dicc& operator=(const dicc &d);

		// Insereix la clau k en el diccionari. Si ja hi era, no fa res.
		void insereix(const Clau &k);

		// Elimina la clau k del diccionari. Si no hi era, no fa res.
		void elimina(const Clau &k);

		// Consulta si la clau k està en el diccionari.
		bool consulta(const Clau &k) const;

		// Retorna quants elements (claus) té el diccionari.
		nat quants() const;						//cost 

		// Impressió per cout de claus del diccionari en ordre ascendent, separades per
		// un espai, començant per ’[’ i acabant per ’]’, en dues versions:
		// Imprimeix totes les claus
		void print() const;								//cost lineal
		// Imprimeix les claus entre k1 i k2 ambdós incloses. Pre: k1 <= k2
		void print_interval(const Clau &k1, const Clau &k2) const;				//cost lineal

		// Retorna la clau més petita i la més gran respectivament.
		// Pre: El diccionari no està buit
		Clau min() const;
		Clau max() const;

		// Retorna la clau de la posició i-èssima (comptant-les en ordre ascendent).
		// Pre: El diccionari no està buit. 1 <= i <= quants()
		Clau iessim(nat i) const;

	private:
	// Aquí van els atributs i mètodes privats
		struct node {
			Clau _k;	// Clau equivale a ==>  T info;
			
			node* f_esq;
			node* f_dret;
			
			// nat _nsz;
			node(const Clau &k, node* esq = NULL, node* dret = NULL) throw();	//Como si inicializa un arbol
		};
		
		node* _arrel;
		nat _sz;	//variable que contiene el numero de elementos que tiene el arbol
		
		//MÈTODES PRIVATS 
		static void esborra_nodes(node* m);	//funcion auxilir de la funcion : ~
		node* igualar(node* n);			//funcion auxiliar de la funcion : =
		node* insereix(const Clau k, bool & existeix, node* now);	//funcion auxiliar de insereix
 };
 /*	insereix, elimina, consulta, min, max i iessim ==>  COST LOGARITMIC 
	quants ==> COST CONSTANT i els mètodes 
	print i print_interval ==> COST LINEAL.
*/

 // Aquí va la implementació dels mètodes públics i privats
template <typename Clau>
dicc<Clau>::node::node(const Clau &k, node* esq = NULL, node* dret = NULL) throw() : _k(k), fesq(esq), fdret(dret){	
	//Como si inicializa un arbol
}

template <typename Clau>
dicc<Clau>::dicc(){	// Constructora per defecte. Crea un diccionari buit.
	_arrel = NULL;	//crear un arbol con raiz vacia para que a posteriori inserir elementos
	_sz = 0;	//hay 0 elementos ahora en el abrol;
}

template <typename Clau>
dicc<Clau>::dicc(const dicc &d){	// Constructora per còpia
	*this = d;	//el parametro implicito pasa a ser d
}

template <typename Clau>
dicc<Clau>::~dicc(){	// Destructora
	esborra_nodes(_arrel);
}

template <typename Clau>
void dicc<Clau>::esborra_nodes(node* m) {
/* Pre: cert */
/* Post: no fa res si m és NULL, sinó allibera
   espai dels nodes de l'arbre binari apuntat per m */
   
	if (m != NULL) {
		esborra_nodes(m->f_esq);
		esborra_nodes(m->f_dret);
		delete m;
	}
};

template <typename Clau>	
dicc<Clau>& dicc<Clau>::operator=(const dicc &d){	// Operador d’assignació
	_sz = d._sz;
	_arrel = igualar(d._arrel);	//crear una funcion auxiliar para igualar todos los nodos
	return *this; 
}

template <typename Clau>
template dicc<Clau>::node* dicc<Clau>::igualar(node* now){
	node * aux = NULL;
	if(aux != NULL){
		aux = new node(now->_k, igualar(now->f_esq), igualar(now->f_dret));	//crear nuevo nodo con los datos de now
	} 
	return aux;
}

template <typename Clau>
void dicc<Clau>::insereix(const Clau &k){	// Insereix la clau k en el diccionari. Si ja hi era, no fa res.
	_arrel = insereix(k, false, _arrel);
}
template <typename Clau>
template dicc<Clau>::node* dicc<Clau>::insereix(const Clau k, bool & existeix, node* now){
	if(n != NULL){
		if(k > now->_k) insereix(k, existeix, now->f_esq);	//si k es mayor, entonces esta en el subarbre izq
		else if (k < now->_k) insereix(k, existeix, now->f_dret);	//si k es mayor, entonces esta en el subarbre dret
		else existeix = true;	//si k == now->_k entonces esta repetido el nodo  y dejamos de seguir buscando
	}
	else{	//si el nodo no existe en el arbol, hay que crearlo
		now = new node(k, NULL, NULL);
		++_sz;	//se incrementa el contador de elementos pq se ha añadido un elemento
	}
	
	return now;
}
//***********************************************************************************************************************

#include <iostream>
#include <sstream>
using namespace std;

int main() {
  string linea, comanda;;
  int n, n1, n2;
  while (getline(cin, linea)) {
    dicc<int> d;

    // Obtenim elements 1er diccionari
    istringstream ss1(linea);
    while (ss1 >> n){
      d.insereix(n);
    }
    d.print(); cout << endl;

    // Processem comandes
    while (getline(cin, linea) and linea != "----------") {
      cout << linea << ": ";
      istringstream ss2(linea);
      ss2 >> comanda;

      if (comanda == "insereix") {
        ss2 >> n;
        d.insereix(n);
        cout << d.quants();

      } else if (comanda == "elimina") {
        ss2 >> n;
        d.elimina(n);
        cout << d.quants();

      } else if (comanda == "consulta") {
        ss2 >> n;
        cout << d.consulta(n);

      } else if (comanda == "quants") {
        cout << d.quants();

      } else if (comanda == "print") {
        d.print();

      } else if (comanda == "print_interval") {
        ss2 >> n1 >> n2;
        d.print_interval(n1, n2);

      } else if (comanda == "min") {
        cout << d.min();

      } else if (comanda == "max") {
        cout << d.max();

      } else if (comanda == "iessim") {
        ss2 >> n;
        cout << d.iessim(n);
      }
      cout<<endl;
    }
    if (linea == "----------")
      cout << linea << endl;
  }
}
