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
    return _contingut.size()-1;
}

int Text::n_paraules()
{
    return _n_paraules;
}

bool Text::conte_paraules(const vector<string>& paraules)
{
    bool trobat = false;
    for (int i = 0; not trobat and i < _contingut.size(); ++i) {
        trobat = _contingut[i].buscar_paraules(paraules);
    }
    return trobat;
}

void Text::llegir_text()
{
	string linia, l;
	getline(cin, linia);
	getline(cin, l);
	while (l != "****") {  //Es posa tot el text en un únic string
		linia += l;
		getline(cin, l);
	}

    Frase frase;
	while (linia.length()>0){
		frase.llegir(linia);
		_contingut.push_back(frase);
	}
}

void Text::afegir_contingut(Cita& cita, int x, int y)
{
	cita.afegir_contingut(_contingut, x, y);
}

void Text::escriure_contingut()
{
    for (int i = 0; i < _contingut.size(); ++i) {
        cout << i+1 << " ";
        _contingut[i].escriure();
        cout << endl;
    }
}

void Text::substitueix (string par1, string par2)
{
    for (int i = 0; i < _contingut.size(); ++i) {
        _contingut[i].substitueix(par1, par2);
    }
}
