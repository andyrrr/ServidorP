//
// Created by andy on 10/04/19.
//

#ifndef SERVIDORP_EMPAQUETAR_H
#define SERVIDORP_EMPAQUETAR_H
#include "json.hpp"
#include "Lista.h"
#include "json.hpp"
#include "Lista.h"

using json = nlohmann::json;

class Empaquetar {
public:
    Empaquetar(int IDJugador, int IDjuego, bool CrearJuego, bool ActualizarJuego, bool Actualizado,
               Lista *listaCambios);

    Empaquetar();

    int getIDJugador() const;

    void setIDJugador(int idjugador);

    int getIDjuego() const;

    void setIDjuego(int idjuego);

    bool getCrearJuego();

    void setCrearJuego(bool crearJuego);

    bool getActualizarJuego();

    void setActualizarJuego(bool actualizarJuego);

    bool getActualizado();

    void setActualizado(bool actualizado);

    json generarJsonEmpaquetado();

    json getCambios();

    void setCambios(json Cambios);

    json generarJson();

    int getPuntaje() const;

    void setPuntaje(int puntaje);

    Lista *getListaCambios() const;

    void setListaCambios(Lista *listaCambios);


private:
    int Puntaje;
    int IDJugador;
    int IDjuego;
    bool CrearJuego;
    bool ActualizarJuego;
    bool Actualizado;
    json Cambios;
    Lista *ListaCambios;
};

#endif //SERVIDORP_EMPAQUETAR_H
