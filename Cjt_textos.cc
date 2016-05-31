/** @file Cjt_textos.cc
    @brief Implementació de les funcions de Cjt_textos.hh
*/

#include "Cjt_textos.hh"

Cjt_textos::Cjt_textos()
{
	//Es crea un conjunt de textos buit.
    _n_frases = 0;
    _n_paraules = 0;
}
    
Cjt_textos::~Cjt_textos(){}
    
void Cjt_textos::afegir_text(string& titol)
{
    if (_textos.find(titol) == _textos.end()) {		//Si no existeix cap altre text amb el mateix títol, s'afegeix el text.
		_textos[titol].llegir_text();					//Es crea un text i es llegeix el contingut.
		_n_frases += _textos[titol].n_frases();			//S'actulitza el nombre de frases.
		_n_paraules += _textos[titol].n_paraules();		//S'actulitza el nombre de paraules.
	}
    else{							//Si ja existeix un text amb el mateix titol, s'escriu error.
        cout << "error" << endl;
        string s;
        getline(cin, s);
        while (s != "****") getline(cin, s);		//Es llegeix el text que està esperant a l'input.
    }
}
    
void Cjt_textos::eliminar_text()
{
    _n_paraules -= (*_text_triat).second.n_paraules();		//Es resta el nombre de paraules del text que s'elimina.
    _n_frases -= (*_text_triat).second.n_frases();			//Es resta el nombre de frases del text que s'elimina.
    _textos.erase(_text_triat);								//S'elimina el text triat.
}

void Cjt_textos::triar_text(bool& trobat, const vector<string>& paraules, string& autor)
{
    map<string, Text>::iterator it_text = _textos.begin();
    while (not trobat and it_text != _textos.end()) {		//Es busca un text que contingui paraules fins que es troba.
        string titol = (*it_text).first;
        trobat = (*it_text).second.conte_paraules(paraules, autor, titol);
        ++it_text;
    }
    if (trobat) {
		--it_text;					//Es torna a posar l'iterador apuntant al text que conté paraules, ja que abans de sortir del bucle s'ha incrementat.
		_text_triat = it_text;		//Guardem com ha text triat el que apunta l'iterador.
	}
}

void Cjt_textos::substitueix (const string& par1, const string& par2)
{
    (*_text_triat).second.substitueix(par1, par2);
}

void Cjt_textos::buscar_text(bool& trobat, const vector<string>& paraules, string& autor) const
{
    map<string, Text>::const_iterator it_text = _text_triat;
    ++it_text;
    while (not trobat and it_text != _textos.end()) {		//Es busca un text a partir del que apunta _text_triat que contingui paraules fins que es troba.
        string titol = (*it_text).first;
        if ((*it_text).second.conte_paraules(paraules, autor, titol)) trobat = true;
        else ++it_text;
    }
}

void Cjt_textos::fer_taula(Taula_freq& t) const
{
	(*_text_triat).second.fer_taula(t);
}

bool Cjt_textos::es_buit() const
{
    if (_textos.empty()) return true;	//No hi ha textos.
    else return false;
}

void Cjt_textos::titol_triat(string& titol) const
{
	titol = (*_text_triat).first;
}	

void Cjt_textos::modificar_cita(Cita& c, int x, int y) const
{
	//S'afegeix a la cita c el títol i el contingut del text triat.
	c.afegir_titol((*_text_triat).first);
	(*_text_triat).second.afegir_contingut(c, x, y);
}

void Cjt_textos::escriure_titols(string& autor, bool tots) const
{
    map<string, Text>::const_iterator it = _textos.begin();
    while (it != _textos.end()) {		// Per a cada text, s'escriu l'autor (és el mateix) i el títol.
        if (tots) cout << autor << " ";
        cout << '"' << (*it).first << '"';
        ++it;
        cout << endl;

    }
}

void Cjt_textos::escriure_info() const
{
    cout << _textos.size() << " " << _n_frases << " " << _n_paraules << endl;
}

void Cjt_textos::escriure_info_triat() const
{
    cout << '"' << (*_text_triat).first << '"' << " " << (*_text_triat).second.n_frases() << " " << (*_text_triat).second.n_paraules() << endl;
}

void Cjt_textos::escriure_titol_triat() const
{
	cout << '"' << (*_text_triat).first << '"';
}

void Cjt_textos::escriure_contingut(bool tot, int x, int y) const
{
    if (tot) {		//Si hem d'escriure tot el contingut del text, x és 1 i y el nombre de frases del text.
        x = 1;
        y = (*_text_triat).second.n_frases();
    }
    (*_text_triat).second.escriure_contingut(x, y);
}

void Cjt_textos::escriure_nombre_frases() const
{
    cout << (*_text_triat).second.n_frases() << endl;
}

void Cjt_textos::escriure_nombre_paraules() const
{
    cout << (*_text_triat).second.n_paraules() << endl;
}

void Cjt_textos::frases_expressio(string& expressio) const
{
	(*_text_triat).second.frases_expressio(expressio);
}

void Cjt_textos::frases_paraules(const vector<string>& paraules) const
{
    (*_text_triat).second.conte_consecutives(paraules);
}
