//
// Created by andy on 10/04/19.
//

#ifndef SERVIDORP_JUEGO_H
#define SERVIDORP_JUEGO_H


#include "Lista.h"
#include "empaquetar.h"
#include <string>
using namespace std;

class Juego {
public:
    Juego(int idjuego, int cantidadusers);

    Lista *ListaCambiosJuego = new Lista();
    char *GenerarPaq();
    json StringtoJson(string s1);
    Empaquetar *desempaquetar(json j1);
    Lista *generateList(json j1);
    void recibirPaq(Empaquetar*);
    int IDJuego;
    int CantidadUser;
    bool verificacionPalabra, ActJ, Actudo;
};


#endif //SERVIDORP_JUEGO_H
