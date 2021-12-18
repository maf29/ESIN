#include <vector>
#include <cstddef>
using namespace std;
typedef unsigned int nat;

class Llista {
  // Llista doblement encadenada, sense fantasma i no circular.
  private:
    struct node {
      int info;  // Informació del node
      node *seg; // Punter al següent element
      node *ant; // Punter a l'anterior element
    };
    node *_prim; // Punter al primer element
    node *_ult;  // Punter a l'últim element
    nat _long;   // Nombre d'elements

  public:
    Llista();
    // Pre: True
    // Post: El p.i. és una llista buida.

    Llista(const vector<int> &v);
    // Pre: True
    // Post: El p.i. conté els elements de v amb el mateix ordre.

    ~Llista();
    // Post: Destrueix els elements del p.i.

    nat longitud() const;
    // Pre: True
    // Post: Retorna el nombre d'elements del p.i.

    void mostra() const;
    // Pre: True
    // Post: Mostra el p.i. pel canal estàndard de sortida.

    void mostra_invertida() const;
    // Pre: True
    // Post: Mostra el p.i. en ordre invers pel canal estàndard de sortida.

    void duplica_parells_elimina_senars();
    // Pre: True
    // Post: S'han duplicat els elements parells i
    //       s'han eliminat els elements senars del p.i.
    //       Exemple: [2 3 0 5 -2] => [2 2 0 0 -2 -2]
};
