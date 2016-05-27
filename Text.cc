/** @file Text.cc
    @brief Implementació de les funcions de Text.hh
*/

#include "Text.hh"

Text::Text()
{
    _n_paraules = 0;
}

Text::~Text(){}

int Text::n_frases()
{
    return _contingut.size();
}

int Text::n_paraules()
{
    return _n_paraules;
}

bool Text::conte_paraules(vector<string> paraules, string& autor, string& titol)
{
    bool trobat = false;
    
    istringstream iss (autor);
    string aux;
    
    while (not trobat and iss >> aux) {
        bool b = false;
        for (int i = 0; not b and i < paraules.size(); ++i) {
            b = aux == paraules[i];
            if (b){
                paraules[i] = paraules[paraules.size()-1];
                paraules.pop_back();
            }
        }
        trobat = paraules.size() == 0;
    }
    
    istringstream isss (titol);
    
    while (not trobat and isss >> aux) {
        bool b = false;
        for (int i = 0; not b and i < paraules.size(); ++i) {
			if (not es_lletra(aux.back())) aux.erase(aux.end()-1);
            b = aux == paraules[i];
            if (b){
                paraules[i] = paraules[paraules.size()-1];
                paraules.pop_back();
            }
        }
        trobat = paraules.size() == 0;
    }
    
    for (int i = 0; not trobat and i < _contingut.size(); ++i) {
        trobat = _contingut[i].buscar_paraules(paraules);
    }
    return trobat;
}

void Text::conte_consecutives(vector<string>& paraules)
{
    for (int i = 0; i < _contingut.size(); ++i){
        if(_contingut[i].buscar_consecutives(paraules)) {
			cout << i+1 << " ";
			_contingut[i].escriure();
		}
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
    
	while (linia.length()>0){
        Frase frase;
		frase.llegir(linia);
		_contingut.push_back(frase);
        _n_paraules += frase.n_paraules();
	}
}

void Text::substitueix (string par1, string par2)
{
    for (int i = 0; i < _contingut.size(); ++i) {
        _contingut[i].substitueix(par1, par2);
    }
}

void Text::afegir_contingut(Cita& cita, int x, int y)
{
	cita.afegir_contingut(_contingut, x, y);
}

void Text::fer_taula(Taula_freq& t)
{
	for (int i = 0; i < _contingut.size(); ++i) {
		_contingut[i].actualitzar_taula(t);
	}
}

void Text::escriure_contingut(int x, int y)
{
	if (y > _contingut.size() or x < 1) cout << "error" << endl;
	else {
		while (x <= y) {
			cout << x << " ";
			_contingut[x-1].escriure();
			++x;
		}
	}
}

void Text::frases_expressio(string& expressio)
{
	for (int i = 0; i < _contingut.size(); ++i) {
		if (_contingut[i].compleix_expressio(expressio)) {
			cout << i+1 << " ";
			_contingut[i].escriure();
		}
	}
}
