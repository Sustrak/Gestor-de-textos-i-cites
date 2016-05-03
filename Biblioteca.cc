/** @file Biblioteca.cc
    @brief Implementació de les funcions de Biblioteca.hh
*/

#include "Biblioteca.hh"

#include "Func_auxiliars.hh"
#include <sstream>

using namespace std;

Biblioteca::Biblioteca(){
    _triat = false;
}

Biblioteca::~Biblioteca(){}

void Biblioteca::afegir_text(string titol){
    normalitzar(titol);
    string autor;
    cin >> autor >> autor;
    normalitzar(autor);
    
    _autors[autor].afegir_text(titol);
}

void Biblioteca::triar_text(string paraules){
    normalitzar(paraules);
    
    istringstream iss(paraules);
    vector<string> paraules_buscar;
    string aux;
    while (iss >> aux) paraules_buscar.push_back(aux);
    
    map<string, Cjt_textos>::iterator it_autor = _autors.begin();
    bool trobat = false;
    
    while (not trobat and it_autor != _autors.end()){
        (*it_autor).second.triar_text(trobat, paraules_buscar);
        ++it_autor;
    }
    if (trobat) {
        --it_autor;
        map<string, Cjt_textos>::iterator it = it_autor;
        (*it).second.buscar_text(trobat, paraules_buscar); //Comprova si hi ha un altre text amb paraules en el mateix autor.
        ++it;
        while (trobat and it != _autors.end()) {
            (*it).second.triar_text(trobat, paraules_buscar);
            ++it;
        }
    }
    if (trobat) {
        _triat = true;
        _autor_triat = it_autor;
    }
    else {
        _triat = false;
        cout << "error" << endl;
    }
}
