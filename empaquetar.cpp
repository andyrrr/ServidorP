//
// Created by andy on 10/04/19.
//

#include "empaquetar.h"


Empaquetar::Empaquetar(int IDJugador, int IDjuego, bool CrearJuego, bool ActualizarJuego, bool Actualizado,
                       Lista *listaCambios) : IDJugador(
        IDJugador), IDjuego(IDjuego), CrearJuego(CrearJuego), ActualizarJuego(ActualizarJuego), Actualizado(
        Actualizado), ListaCambios(listaCambios) {}

Empaquetar::Empaquetar() {}

int Empaquetar::getIDJugador() const {
    return IDJugador;
}

void Empaquetar::setIDJugador(int idjugador) {
    IDJugador = idjugador;
}

int Empaquetar::getIDjuego() const {
    return IDjuego;
}

void Empaquetar::setIDjuego(int idjuego) {
    IDjuego = idjuego;
}

bool Empaquetar::getCrearJuego() {
    return CrearJuego;
}

void Empaquetar::setCrearJuego(bool crearJuego) {
    CrearJuego = crearJuego;
}

bool Empaquetar::getActualizarJuego() {
    return ActualizarJuego;
}

void Empaquetar::setActualizarJuego(bool actualizarJuego) {
    ActualizarJuego = actualizarJuego;
}

bool Empaquetar::getActualizado() {
    return Actualizado;
}

void Empaquetar::setActualizado(bool actualizado) {
    Actualizado = actualizado;
}

void Empaquetar::setCambios(json cambio) {
    Cambios = cambio;
}

Lista *Empaquetar::getListaCambios() const {
    return ListaCambios;
}

void Empaquetar::setListaCambios(Lista *listaCambios) {
    ListaCambios = listaCambios;
}

json Empaquetar::getCambios() {
    return Cambios;
}

int Empaquetar::getPuntaje() const {
    return Puntaje;
}

void Empaquetar::setPuntaje(int puntaje) {
    Puntaje = puntaje;
}

json Empaquetar::generarJsonEmpaquetado() {
    json empa;

    empa["IDPLAYER"] = getIDJugador();
    empa["IDGAME"] = getIDjuego();
    empa["CREATE"] = getCrearJuego();
    empa["REFRESH"] = getActualizarJuego();
    empa["REFRESHED"] = getActualizado();
    empa["JSON"] = generarJson();
    return empa;
}

json Empaquetar::generarJson() {
    json j1;
    Nodo *temp;
    temp = ListaCambios->getHead();
    int i = 1;
    j1["0"] = ListaCambios->size;

    while (temp != NULL) {
        std::string s = std::to_string(i);
        j1[s] = {{"Letra", temp->letra},
                 {"Posi",  {temp->col, temp->fil}}};
        temp = temp->next;
        i++;
    }

    return j1;
}