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
    cin >> autor;
    getline(cin, autor);
    autor.erase(autor.begin());
    normalitzar(autor);
    _autors[autor].afegir_text(titol);
}

void Biblioteca::triar_text(string paraules)
{
    normalitzar(paraules);
    
    vector<string> paraules_buscar = par_buscar(paraules);
    
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
        _tfreq.clear();
        (*_autor_triat).second.fer_taula(_tfreq);
    }
    else {
        _triat = false;
        cout << "error" << endl;   //No hi ha cap text o n'hi més d'un que ho compleixi.
    }
}

void Biblioteca::eliminar_text()
{
    if (not _triat) cout << "error" << endl; //No hi ha un text triat.
    else (*_autor_triat).second.eliminar_text();
    
    if ((*_autor_triat).second.es_buit()) _autors.erase(_autor_triat);
}
    
void Biblioteca::substitueix (string par1, string par2)
{
    if (_triat) {
		(*_autor_triat).second.substitueix(par1, par2);
		_tfreq.substitueix(par1, par2);
	}
	else cout << "error" << endl; //No hi ha un text triat.
}
    
bool Biblioteca::triat()
{
    return _triat;
}
    
void Biblioteca::modificar_cita(Cita& c, int x, int y)
{
	if (_triat) {
		c.afegir_autor((*_autor_triat).first);
		(*_autor_triat).second.modificar_cita(c, x, y);
	}
}
    
void Biblioteca::info_triat(string& autor, string& titol) //REVISAR SI ES NECESITA AQUESTA FUNCIO
{
    if (not _triat) cout << "error" << endl; //No hi ha un text triat.
    else {
        autor = (*_autor_triat).first;
        (*_autor_triat).second.titol_triat(titol);
    }
}

void Biblioteca::textos_autor(string autor)
{
    normalitzar(autor);
    map<string, Cjt_textos>::iterator it = _autors.find(autor);
    if (it != _autors.end()) (*it).second.escriure_titols();
}
    
void Biblioteca::tots_textos()
{
    map<string, Cjt_textos>::iterator it = _autors.begin();
    
    while (it != _autors.end()){
        cout << (*it).first << " ";
        (*it).second.escriure_titols();
        ++it;
    }
}
    
void Biblioteca::tots_autors()
{
    map<string, Cjt_textos>::iterator it = _autors.begin();
    while (it != _autors.end()) {
        cout << (*it).first << endl;
        (*it).second.escriure_info();
        ++it;
    }
}
    
void Biblioteca::info()
{
    if (not _triat) cout << "error" << endl; //No hi ha un text triat.
    else {
        cout << (*_autor_triat).first << " ";
        (*_autor_triat).second.escriure_info_triat();
    }
}

void Biblioteca::autor()
{
    if (not _triat) cout << "error" << endl; //No hi ha un text triat.
    else {
        cout << (*_autor_triat).first << endl;
    }
}

void Biblioteca::contingut()
{
    if (not _triat) cout << "error" << endl; //No hi ha un text triat.
    else {
        bool tot = true;
        int x, y;
        (*_autor_triat).second.escriure_contingut(tot, x, y);
    }
}

void Biblioteca::frasesxy (int x, int y)
{
    if (not _triat or x > y) cout << "error" << endl; //No hi ha un text triat o x>y.
    else {
        bool tot = false;
        (*_autor_triat).second.escriure_contingut(tot, x, y);
    }
}
    
void Biblioteca::nombre_frases()
{
    if (not _triat) cout << "error" << endl; //No hi ha un text triat.
    else {
        (*_autor_triat).second.escriure_nombre_frases();
    }
}

void Biblioteca::nombre_paraules()
{
    if (not _triat) cout << "error" << endl; //No hi ha un text triat.
    else {
        (*_autor_triat).second.escriure_nombre_paraules();
    }
}

void Biblioteca::taula_freq()
{
    if (not _triat) cout << "error" << endl;
	else _tfreq.escriure();
}

void Biblioteca::frases_expressio(string expressio)
{
    if (not _triat) cout << "error" << endl; 	//No hi ha un text triat.
    else {
		//Netejar expressio.
		(*_autor_triat).second.frases_expressio(expressio);
	}
}
    
void Biblioteca::frases_paraules(string paraules)
{
    if (not _triat) cout << "error" << endl; 	//No hi ha un text triat.
    else {
        normalitzar(paraules);
        vector<string> vec_par = par_buscar(paraules);
        
        (*_autor_triat).second.frases_paraules(vec_par);
    }
    
}
