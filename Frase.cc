/** @file Frase.cc
    @brief Implementació de les funcions de Frase.hh
*/

#include "Frase.hh"

Frase::Frase ()
{
	_n_paraules = 0;
}

Frase::~Frase(){}

void Frase::llegir(string& linia)
{
	istringstream iss(linia);
	string m, aux = linia;
	do {
		iss >> m;
		if (not es_lletra(m.back())) {
			string m1 = m;
			m1.pop_back();
			string m2;
			m2.push_back(m.back());
			_frase.push_back(m1);
			_frase.push_back(m2);
		}
		else _frase.push_back(m);
		++_n_paraules;
	} while (m.back() != '.' and m.back() != '?' and m.back() != '!');
	ws(iss);
	getline(iss, linia);
    if (aux == linia) linia = "";
}

void Frase::substitueix (string par1, string par2)
{
	for (int i = 0; i < _frase.size(); ++i) {
		if (_frase[i] == par1) _frase[i] = par2;
	}
}

int Frase::n_paraules()
{
	return _n_paraules;
}

bool Frase::buscar_paraules(vector<string>& paraules)
{
    for (int i = 0; i < paraules.size(); ++i) {
		bool aux = false;;
        for (int j = 0; not aux and j < _frase.size(); ++j) {
			aux = paraules[i] == _frase[j];
            if (aux){
                paraules[i] = paraules[paraules.size()-1]; //Si troba la paraula la elimina del vector de paraules
                paraules.pop_back();
                --i;
            }
        }
    }
    return paraules.size() == 0;
}

bool Frase::buscar_consecutives(vector<string>& paraules)
{
	bool trobat = false;
    for (int i = 0; i <= _frase.size()-paraules.size() and not trobat; ++i) {
		if (_frase[i] == paraules[0]) {
			trobat = true;
			int p = 0;		//Compte els signes de puntuacio.
			for (int j = 1; j < paraules.size() and trobat; ++j) {
				if (i+j+p < _frase.size()) {
					if (not es_lletra(_frase[i+j+p][0])) ++p;
					else trobat = _frase[i+j+p] == paraules [j];
				}
			}
		}
	}
	return trobat;			
}

void Frase::actualitzar_taula(Taula_freq& t)
{
	for (int i = 0; i < _frase.size(); ++i) {
        if (es_lletra(_frase[i].back())){
			t.incrementa_freq(_frase[i]); 
        }
	}
}

bool Frase::compleix_expressio(string expressio)
{
	if (expressio[0] == '{') {
		normalitzar(expressio);
		vector<string> paraules = par_buscar(expressio);
		return buscar_paraules(paraules);
	}
	normalitzar(expressio);
	int i = 0;
    string esq;
	while (0 < expressio.length()) {
		if (expressio[0] == '(') ++i;
		else if (expressio[0] == ')') --i;
		else if (i == 0 and expressio[0] == '&') {
			esq.erase(esq.end()-1);
            expressio.erase(expressio.begin());
            expressio.erase(expressio.begin());
            return compleix_expressio(esq) and compleix_expressio(expressio);
		}
		else if (i == 0 and expressio[0] == '|') {
			esq.erase(esq.end()-1);
            expressio.erase(expressio.begin());
            expressio.erase(expressio.begin());
			return compleix_expressio(esq) or compleix_expressio(expressio);
		}
		esq.push_back(expressio[0]);
        expressio.erase(expressio.begin());
	}
    return true;
}

void Frase::escriure()
{
	for (int i = 0; i < _frase.size(); ++i) {
		if (not es_lletra(_frase[i].back()) or i == 0) cout << _frase[i];
		else cout << " " << _frase[i];
	}
	cout << endl;
}
