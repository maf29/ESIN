#include <iostream>
#include "llista.hpp"

int main() {
  string alumne_cercat, alumne_nou, alumne;
  vector<string> v;
  while (cin >> alumne and alumne != "Final") {    
    v.push_back(alumne);
  }    
  Llista l(v);
  cin >> alumne_cercat;
  cin >> alumne_nou;
  //cout << alumne_cercat << " - " << alumne_nou;
  l.alumne_nou(alumne_cercat,alumne_nou);
  l.mostra();    
 
}
