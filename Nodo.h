//
// Created by andy on 10/04/19.
//

#ifndef SERVIDORP_NODO_H
#define SERVIDORP_NODO_H


#include <iostream>

class Nodo {
public:
    int fil=5;
    int col=5;
    std::string letra;
    Nodo *next;





    int getDato() const;
    void setLetra(std::string letra);

    Nodo *getNext() const;
    void setNext(Nodo *next);

};


#endif //SERVIDORP_NODO_H
