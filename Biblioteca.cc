/** @file Biblioteca.cc
    @brief Implementació de les funcions de Biblioteca.hh
*/

#include "Biblioteca.hh"

#include "Func_auxiliars.hh"
#include <sstream>

using namespace std;

Biblioteca::Biblioteca()
{
    _triat = false;
}

Biblioteca::~Biblioteca(){}

void Biblioteca::afegir_text(string titol)
{
    normalitzar(titol);
    string autor;
    cin >> autor >> autor;
    normalitzar(autor);
    
    _autors[autor].afegir_text(titol);
}

void Biblioteca::triar_text(string paraules)
{
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

void Biblioteca::eliminar_text()
{
    if (not _triat) cout << "error" << endl;
    else (*_autor_triat).second.eliminar_text();
}
    
void Biblioteca::substitueix (string par1, string par2)
{
    (*_autor_triat).second.substitueix(par1, par2);
}
    
bool Biblioteca::triat()
{
    return _triat;
}
    
void Biblioteca::modificar_cita(Cita& c, int x, int y){}
    
void Biblioteca::info_triat(string& autor, string& titol)
{
    if (not _triat) cout << "error" << endl;
    else {
        autor = (*_autor_triat).first;
        (*_autor_triat).second.titol_triat(titol);
    }
}

void Biblioteca::textos_autor(string autor)
{
    map<string, Cjt_textos>::iterator it = _autors.find(autor);
    (*it).second.escriure_titols();
}
    
void Biblioteca::tots_textos()
{
    map<string, Cjt_textos>::iterator it = _autors.begin();
    
    while (it != _autors.end()){
        cout << (*it).first << " ";
        (*it).second.escriure_titols();
    }
}
    
void Biblioteca::tots_autors()
{
    map<string, Cjt_textos>::iterator it = _autors.begin();
    while (it != _autors.end()) {
        cout << (*it).first << endl;
        //Falten funcions a Cjt_textos
    }
}
    
void Biblioteca::info(){}
    
void Biblioteca::autor(){}
    
void Biblioteca::contingut(){}
    
void Biblioteca::frasesxy (int x, int y){}
    
void Biblioteca::nombre_frases(){}
    
void Biblioteca::nombre_paraules(){}
    
void Biblioteca::taula_freq(){}
    
void Biblioteca::frases_expressio(string expressio){}
    
void Biblioteca::frases_paraules(string paraules){}
