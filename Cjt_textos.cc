/** @file Cjt_textos.cc
    @brief Implementació de les funcions de Cjt_textos.hh
*/

#include "Cjt_textos.hh"

Cjt_textos::Cjt_textos()
{
    _n_frases = 0;
    _n_paraules = 0;
}
    
Cjt_textos::~Cjt_textos(){}
    
void Cjt_textos::afegir_text(string titol)
{
    _textos[titol].llegir_text();
}
    
void Cjt_textos::eliminar_text()
{
    _textos.erase(_text_triat);
}

void Cjt_textos::modificar_cita(Cita& c, int x, int y)
{
	c.afegir_titol((*_text_triat).first);
	(*_text_triat).second.afegir_contingut(c, x, y);
}

void Cjt_textos::triar_text(bool& trobat, const vector<string>& paraules)
{
    map<string, Text>::iterator it_text = _textos.begin();
    while (not trobat and it_text != _textos.end()) {
        trobat = (*it_text).second.conte_paraules(paraules);
        ++it_text;
    }
    if (trobat) _text_triat = --it_text;
}

void Cjt_textos::buscar_text(bool& trobat, const vector<string>& paraules)
{
    map<string, Text>::iterator it_text = ++_text_triat;
    while (trobat and it_text != _textos.end()) {
        if ((*it_text).second.conte_paraules(paraules)) trobat = false;
        else ++it_text;
    }
}

void Cjt_textos::substitueix (string par1, string par2)
{
    (*_text_triat).second.substitueix(par1, par2);
}
    
void Cjt_textos::escriure_titols()
{
    map<string, Text>::iterator it = _textos.begin();
    while (it != _textos.end()) {
        cout << (*it).first << " ";
    }
    cout << endl;
}
