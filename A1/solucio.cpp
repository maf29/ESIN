##include "llista.hpp"
#include <iostream>

//simplement encadenada, sense fantasma i no circula

// Pre: True
// Post: S'han duplicat els elements positius i
//       s'han eliminat els elements negatius del p.i.
//       Exemple: [0 3 -6 8 0 4 -2 0] => [0 3 3 8 8 0 4 4 0]
void Llista::duplica_positius_elimina_negatius(){
        node *now = _prim, *anterior = NULL;

        if(now != NULL){

                while(now != NULL){
                        if(now->info > 0){      //Si es un numero positivo
                                if(anterior == NULL){ //esta al principio
                                        _prim = new node;
                                        _prim->info = now->info;
                                        _prim->seg = now;

                                        anterior = now;
                                        now = now->seg;
                                }
                                else{
                                        anterior->seg = new node;
                                        anterior->seg->info = now->info;
                                        anterior->seg->seg = now;

                                        anterior = anterior->seg->seg;
                                        now = now->seg;
                                }

                                _long++;

                        } else if(now->info < 0){ //Si es un numero negativo
                                if(anterior == NULL){ //esta al principio
                                        _prim = now->seg;

                                        now = now->seg;
                                }
                                else{
                                        anterior->seg = now->seg;
                                        now = now->seg;
                                }

                                _long--;
                        }else{  //Si es un 0

                                anterior = now;
                                now = now->seg;
                        }
                }
        }
}

