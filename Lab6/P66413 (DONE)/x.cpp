

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VE;
struct Node {
	int valor;
	VE fill;
};

// Llegeix un arbre i el desa a un tros del vector v començant a la posicio j.
// Modifica la variable j perque apunti a la seguent posicio lliure de v.
// Retorna la posicio dins de v de l’arrel del (sub)arbre llegit.
int arbre(int& j, vector<Node>& v) {
	int a = j;
	++j;
	int f;
	cin >> v[a].valor >> f;
	v[a].fill = VE(f);
	for (int i = 0; i < f; ++i) v[a].fill[i] = arbre(j, v);
	return a;
}

void postordre(vector<Node> v){
	int j = 0;
	//for(int i = 0; i < size; i++){
		
		/*for (auto size : v[size].fill){
			//cout << " "<< v[i].fill[j]  ;
			//cout << "size : "<< size << "   " <<endl; // <<v[size].fill
			postordre(v, size);
		}*/
		//for(int i = 1; i < size; i++) postordre(v, i);
		//cout << " " << v[size].valor ;
		
		/*for(auto i = 0; i != v[i].size(); ++i){
			postordre(v, );
		}*/
		for(int i = 1; i < v.size(); i++){
			
			cout <<"v["<<i<<"].fill.size() = "<< v[i].fill.size() << endl;
			
			if(v[i].fill.size() == 0){
				
				postordre();
			}
			cout << " " << v[i].valor << endl;
		}
		//cout << " " << v[0].valor << endl;
		
	//}
	//cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<Node> v(n);	//vector de n = 12 posiciones 
	//cout << "size : "<<v.size() << endl;
	int j = 0;	
	arbre(j, v);
	
	postordre(v);
	
	cout << endl;
	
}
