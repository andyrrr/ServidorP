//
// Created by andy on 10/04/19.
//

#include "Juego.h"
#include "Diccionario.h"

Juego::Juego(int idjuego, int cantidaduser) : IDJuego(idjuego), CantidadUser(cantidaduser) {


}

void Juego::recibirPaq(Empaquetar *recibido) {

    Diccionario din;
    string palabra = din.hacerString(recibido->getListaCambios());

    if (din.compararString(palabra)==true){
        //Acá solo entra si verifica la palabra
        for (int i = 0; i < recibido->getListaCambios()->size; i++) {
            Nodo *cambio = recibido->getListaCambios()->retornar(i);
            cout << cambio->letra << endl;
            cout<<(ListaCambiosJuego->contiene(cambio)==false)<<endl;
            cout<<"muere"<<endl;
            if(ListaCambiosJuego->contiene(cambio)==false){
                ListaCambiosJuego->addLetra(cambio->letra, cambio->col, cambio->fil);
                cout<<"se agrego"<<endl;
                verificacionPalabra=true;
            }
        }
    }else{
        verificacionPalabra=false;
    }

    cout << "cambiosssss" << endl;

    cout<<"CJ"<<recibido->getCrearJuego()<<endl;
    cout<<"AJ"<<recibido->getActualizarJuego()<<endl;
    cout<<"Ado"<<recibido->getActualizado()<<endl;

    if (!recibido->getActualizarJuego()){
        ActJ=false;
        Actudo=false;
    }else{
        ActJ=false;
        Actudo=true;
    }
}

json Juego::StringtoJson(string s1) {
    cout << "el string" << s1 << endl;
    json j1;
    j1 = json::parse(s1);
    return j1;
}

Empaquetar* Juego::desempaquetar(json j1) {
    Empaquetar *paquete = new Empaquetar();
    json lista = j1["JSON"];
    int idGam = j1["IDGAME"];
    int idPlay = j1["IDPLAYER"];
    bool crearJuego = j1["CREATE"];
    bool refresh = j1["REFRESH"];
    bool refreshed = j1["REFRESHED"];
    paquete->setIDjuego(idGam);
    paquete->setIDJugador(idPlay);
    paquete->setCrearJuego(crearJuego);
    paquete->setActualizarJuego(refresh);
    paquete->setActualizado(refreshed);
    paquete->setCambios(lista);
    paquete->setListaCambios(generateList(lista));
    paquete->getListaCambios()->vernodos();
    return paquete;
}

Lista* Juego::generateList(json j1) {
    Lista *temp = new Lista(); //la lista es recibida mediante el socket
    int s = j1["0"];

    for (int j = 1; j <= s; ++j) {
        std::string sq = std::to_string(j);
        temp->addLetra(j1[sq]["Letra"], j1[sq]["Posi"][0], j1[sq]["Posi"][1]);
    }
    return temp;
}

char *Juego::GenerarPaq(){
    Empaquetar *enviar = new Empaquetar(0, 0, verificacionPalabra, ActJ, Actudo, ListaCambiosJuego);
    json jsonEnviar = enviar->generarJsonEmpaquetado();
    string stringEnviar = jsonEnviar.dump();
    char static mensajeServer[sizeof(stringEnviar)];
    strcpy(mensajeServer, stringEnviar.c_str());
    return mensajeServer;

}