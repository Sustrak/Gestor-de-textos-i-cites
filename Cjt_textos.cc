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
    if (_textos.find(titol) == _textos.end()) _textos[titol].llegir_text();
    else cout << "error" << endl;		//Ja existeix un text amb el mateix titol.
    
    _n_frases += _textos[titol].n_frases();
    _n_paraules += _textos[titol].n_paraules();
}
    
void Cjt_textos::eliminar_text()
{
    _n_paraules -= (*_text_triat).second.n_paraules();
    _n_frases -= (*_text_triat).second.n_frases();
    _textos.erase(_text_triat);
}

void Cjt_textos::modificar_cita(Cita& c, int x, int y)
{
	c.afegir_titol((*_text_triat).first);
	(*_text_triat).second.afegir_contingut(c, x, y);
}

void Cjt_textos::triar_text(bool& trobat, vector<string>& paraules, string& autor)
{
    map<string, Text>::iterator it_text = _textos.begin();
    while (not trobat and it_text != _textos.end()) {
        string titol = (*it_text).first;
        trobat = (*it_text).second.conte_paraules(paraules, autor, titol);
        ++it_text;
    }
    if (trobat) {
		--it_text;
		_text_triat = it_text;
	}
}

void Cjt_textos::buscar_text(bool& trobat, vector<string>& paraules, string& autor)
{
    map<string, Text>::iterator it_text = _text_triat;
    ++it_text;
    while (not trobat and it_text != _textos.end()) {
        string titol = (*it_text).first;
        if ((*it_text).second.conte_paraules(paraules, autor, titol)) trobat = true;
        else ++it_text;
    }
}

void Cjt_textos::substitueix (string par1, string par2)
{
    (*_text_triat).second.substitueix(par1, par2);
}

void Cjt_textos::fer_taula(Taula_freq& t)
{
	(*_text_triat).second.fer_taula(t);
}

bool Cjt_textos::es_buit()
{
    if (_n_frases == 0) return true;
    else return false;
}

void Cjt_textos::titol_triat(string& titol)
{
	titol = (*_text_triat).first;
}	

void Cjt_textos::escriure_titols(string& autor, bool tots)
{
    map<string, Text>::iterator it = _textos.begin();
    while (it != _textos.end()) {
        if (tots) cout << autor << " ";
        cout << '"' << (*it).first << '"';
        ++it;
    }
    cout << endl;
}

void Cjt_textos::escriure_info()
{
    cout << _textos.size() << " " << _n_frases << " " << _n_paraules << endl;
}

void Cjt_textos::escriure_info_triat()
{
    cout << '"' << (*_text_triat).first << '"' << " " << (*_text_triat).second.n_frases() << " " << (*_text_triat).second.n_paraules() << endl;
}

void Cjt_textos::escriure_contingut(bool tot, int x, int y)
{
    if (tot) {
        x = 1;
        y = (*_text_triat).second.n_frases();
    }
    (*_text_triat).second.escriure_contingut(x, y);
}

void Cjt_textos::escriure_nombre_frases()
{
    cout << (*_text_triat).second.n_frases() << endl;
}

void Cjt_textos::escriure_nombre_paraules()
{
    cout << (*_text_triat).second.n_paraules() << endl;
}

void Cjt_textos::frases_expressio(string& expressio)
{
	(*_text_triat).second.frases_expressio(expressio);
}

void Cjt_textos::frases_paraules(vector<string> paraules)
{
    (*_text_triat).second.conte_consecutives(paraules);
}
