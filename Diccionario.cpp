//
// Created by josue on 29/03/19.
//

#include "Diccionario.h"
#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "json.hpp"




using json = nlohmann::json;


Diccionario::Diccionario() {}

std::string Diccionario::hacerString(Lista *lista) { //esta funcion va dentro del cliente
    Nodo *temp;
    temp = lista->getHead();
    std::string palabra("");
    while (temp != NULL) {
        palabra.append(temp->letra);

        temp = temp->next;
    }
    return palabra;
}

json Diccionario::generateJson(Lista lista) {
    json j1;
    Nodo *temp;
    temp = lista.getHead();
    int i = 1;
    j1["0"] = lista.size;

    while (temp != NULL) {
        std::string s = std::to_string(i);
        std::string s1(temp->letra);
        j1[s] = {{"Letra", temp->letra},
                 {"Posi",  {1, 2}}};
        temp = temp->next;
        i++;
    }
    std::cout << j1.dump(2) << std::endl;
    return j1;
}

Lista *Diccionario::generateList(json j1) {
    Lista *temp = new Lista(); //la lista es recibida mediante el socket
    int s = j1["0"];
    if(s==1){
        std::cout << "hello"<<std::endl;

        temp->addLetra("NULL");
        return temp;
    }else{
        for (int j = 1; j <= s; ++j) {
            std::string sq = std::to_string(j);
            temp->addLetra(j1[sq]["Letra"]);
        }
        return temp;
    }

}

/**
 * La funcion recibe un string, generado convirtiendo una lista en un String,
 * este stiring será comparado con todos las palabars contenidas en el Archivo Json
 * Diccionario.json, si no se encuentra la palabra se procede a contactar al "experto"
 * para validar la palabra.
 *
 * @param s1
 * @return
 */

bool Diccionario::compararString(std::string s1){ //aqui se revisa el diccionario
    std::cout << "Comparando palabra" << std::endl;
    int size_of = 0;

    std::ifstream i("dicc.json");
    json j;
    i >> j;

    size_of = 0;
    char llave[] = {s1[0]};

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::cout << s1 << std::endl;
    while (size_of <= j[llave].size()) {
        if (j[llave][size_of].is_null()) {
            break;
        } else if (s1.compare(j[llave][size_of]) == 0) {
            std::cout << "La  palabra: " << s1 << ", es igual a: " << j[llave][size_of] << ", llave en json: "
                      << size_of << std::endl;
            return true;
        } else {
            size_of++;
        }

    }
    std::cout << "Palabra no encontrada en Diccionario, puede preguntar al experto" << std::endl;
    return false;

}

/**
 * El sistema de puntaje aun no esta elaborado por completo, sin embargo esta funcion
 * hace lo que se necesita. Solo se deben hacer las funciones para los demás puntajes.
 * @param s1
 * @param ptrPun
 */

char *one_pt[] = {"A","E","O","I","S","N","L","R","U","T"};
char *two_pt[] = {"D","G"};
char *three_pt[] = {"C","B","M","P"};
char *four_pt[] = {"H","F","V","Y"};
char *five_pt[] = {"CH","E"};
char *eigth_pt[] = {"J","LL","Ñ","RR","X"};
char *ten_pt[] = {"Z"};

void onePt(std::string s1, int &ptrPun) {
    for (int i = 0; i < 10; ++i) {
        if (s1.compare(std::string(one_pt[i])) == 0) {
            std::cout << s1 << " Es igual a: " << std::string(one_pt[i]) << ", Entonces sumo 1" << std::endl;
            ptrPun += 1;
        } else {
            ptrPun += 0;
        }
    }
}
void twoPt(std::string s1, int &ptrPun){
    for (int i = 0; i < 2; ++i) {
        if (s1.compare(std::string(two_pt[i])) == 0) {
            std::cout << s1 << " Es igual a: " << std::string(two_pt[i]) << ", Entonces sumo 2" << std::endl;
            ptrPun += 2;
        } else {
            ptrPun += 0;
        }
    }
}
void threePt(std::string s1, int &ptrPun){
    for (int i = 0; i < 4; ++i) {
        if (s1.compare(std::string(three_pt[i])) == 0) {
            std::cout << s1 << " Es igual a: " << std::string(three_pt[i]) << ", Entonces sumo 3" << std::endl;
            ptrPun += 3;
        } else {
            ptrPun += 0;
        }
    }
}
void fourPt(std::string s1, int &ptrPun){
    for (int i = 0; i < 4; ++i) {
        if (s1.compare(std::string(four_pt[i])) == 0) {
            std::cout << s1 << " Es igual a: " << std::string(four_pt[i]) << ", Entonces sumo 4" << std::endl;
            ptrPun += 4;
        } else {
            ptrPun += 0;
        }
    }
}
void fivePt(std::string s1, int &ptrPun){
    for (int i = 0; i < 2; ++i) {
        if (s1.compare(std::string(five_pt[i])) == 0) {
            std::cout << s1 << " Es igual a: " << std::string(five_pt[i]) << ", Entonces sumo 5" << std::endl;
            ptrPun += 5;
        } else {
            ptrPun += 0;
        }
    }
}
void eightPt(std::string s1, int &ptrPun){
    for (int i = 0; i < 5; ++i) {
        if (s1.compare(std::string(eigth_pt[i])) == 0) {
            std::cout << s1 << " Es igual a: " << std::string(eigth_pt[i]) << ", Entonces sumo 8" << std::endl;
            ptrPun += 8;
        } else {
            ptrPun += 0;
        }
    }
}

void tenPt(std::string s1, int &ptrPun){
    if (s1.compare(std::string(ten_pt[0])) == 0) {
        std::cout << s1 << " Es igual a: " << std::string(ten_pt[0]) << ", Entonces sumo 10" << std::endl;
        ptrPun += 10;
    } else {
        ptrPun += 0;
    }
}


int Diccionario::calcularPuntaje(Lista *lista) {
    int puntaje = 0;
    int &puntR = puntaje;
    Nodo *temp;
    int i = 0;

    temp = lista->getHead();
    while (temp != NULL) {
        std::string s1(temp->letra);
        onePt(s1, puntR);
        twoPt(s1, puntR);
        threePt(s1, puntR);
        fourPt(s1, puntR);
        fivePt(s1, puntR);
        eightPt(s1, puntR);
        tenPt(s1, puntR);
        temp = temp->next;
    }
    std::cout << "El puntaje de: "<<hacerString(lista)<<", es: "<< puntR << std::endl;
    return puntaje;
}