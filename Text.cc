/** @file Text.cc
    @brief Implementació de les funcions de Text.hh
*/

#include "Text.hh"

Text::Text()
{
	//Es crea un text buit.
    _n_paraules = 0;
}

Text::~Text(){}

int Text::n_frases() const
{
	//La mida del vector _ontingut és el nombre de frases del text.
    return _contingut.size();
}

int Text::n_paraules() const
{
    return _n_paraules;
}

bool Text::conte_paraules(vector<string> paraules, string& autor, string& titol) const
{
	//El vector conté les paraules que ha de contenir el text en l'autor, el títol o el contingut.
	//Quan es troba una de les paraules aquesta és eliminada del vector. Així si el vector queda buit
	// voldrà dir que el text conté totes les paraules.
	
    bool trobat = false;		//trobat indica si el text conté totes les paraules del vector paraules.
    
    istringstream iss (autor);
    string aux;
    
    while (not trobat and iss >> aux) {		//Es comproba si l'autor conté alguna de les paraules.
        bool b = false;
        for (int i = 0; not b and i < paraules.size(); ++i) {
            b = aux == paraules[i];
            if (b){				//Si conté alguna de les paraules, aquesta s'elimina del vector.
                paraules[i] = paraules[paraules.size()-1];
                paraules.pop_back();
            }
        }
        trobat = paraules.size() == 0;
    }
    
    istringstream isss (titol);
    
    while (not trobat and isss >> aux) {	//Es comproba si el títol conté alguna de les paraules.
        bool b = false;
        for (int i = 0; not b and i < paraules.size(); ++i) {
			if (not es_lletra(aux.back())) aux.erase(aux.end()-1);
            b = aux == paraules[i];
            if (b){				//Si conté alguna de les paraules, aquesta s'elimina del vector.
                paraules[i] = paraules[paraules.size()-1];
                paraules.pop_back();
            }
        }
        trobat = paraules.size() == 0;
    }
    
    for (int i = 0; not trobat and i < _contingut.size(); ++i) {		//Es comproba si cada frase del text conté alguna de les paraules.
        trobat = _contingut[i].buscar_paraules(paraules);
    }
    return trobat;
}

void Text::afegir_contingut(Cita& cita, int x, int y) const
{
	cita.afegir_contingut(_contingut, x, y);
}

void Text::fer_taula(Taula_freq& t) const
{
	for (int i = 0; i < _contingut.size(); ++i) {	//S'actualitza la taula de freqncies t per a cada frase.
		_contingut[i].actualitzar_taula(t);
	}
}

void Text::llegir_text()
{
	string linia, l;
	linia.clear();
	getline(cin, l);
	while (l != "****") {  //Es posa tot el text en un únic string
		linia += " " + l;
		getline(cin, l);
	}
    
	while (linia.length()>0){	//Es llegeix cada frase fins que la linia queda buida.
        Frase frase;
		frase.llegir(linia);		//frase conté la primera frase (fins al primer punt) de linia.
		_contingut.push_back(frase);
        _n_paraules += frase.n_paraules();		//S'actualitza el nombre de paraules.
	}
}

void Text::substitueix (const string& par1, const string& par2)
{
    for (int i = 0; i < _contingut.size(); ++i) {	//Es substitueix par1 per par2 a cada frase.
        _contingut[i].substitueix(par1, par2);
    }
}

void Text::conte_consecutives(const vector<string>& paraules) const
{
    for (int i = 0; i < _contingut.size(); ++i){
        if(_contingut[i].buscar_consecutives(paraules)) {		//Si la frase conte les paraules de forma consecutiva, s'escriu.
            cout << i+1 << " ";
            _contingut[i].escriure();
        }
    }
}

void Text::escriure_contingut(int x, int y) const
{
	if (y > _contingut.size() or x < 1) cout << "error" << endl;	//Si la y és més gran que el nombre de frases del text triat o la x no és positiva, s'escriu error.
	else {															//Altrament, s'escriu el contingut del text triat de la frase x-éssima a la y-éssima numerades.
		while (x <= y) {
			cout << x << " ";
			_contingut[x-1].escriure();
			++x;
		}
	}
}

void Text::frases_expressio(const string& expressio) const
{
	for (int i = 0; i < _contingut.size(); ++i) {
		if (_contingut[i].compleix_expressio(expressio)) {	//Si la frase compleix l'expressió, s'escriu.
			cout << i+1 << " ";
			_contingut[i].escriure();
		}
	}
}
