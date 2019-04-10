//
// Created by andy on 10/04/19.
//

#ifndef SERVIDORP_LISTA_H
#define SERVIDORP_LISTA_H


#include <iostream>
#include "Nodo.h"

class Lista {
private:
    Nodo *head, *tail;

public:

    int size;

    Lista(); //constructor


    void addLetra(std::string letra,int fila,int col);
    void clear();
    void vernodos();
    Nodo *getHead() const;
    Nodo *retornar(int indice) const;
    bool contiene(Nodo* ref);

    void setHead(Nodo *head);


//
//    void deleteCollectorEnd();

};

#endif //SERVIDORP_LISTA_H
