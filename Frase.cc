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
	string m;
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
	} while (m.back() != '.' or m.back() != '?' or m.back() != '!');
	ws(iss);
	getline(iss, linia);
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

bool Frase::buscar_paraules(const vector<string>& paraules);

void Frase::actualitzar_taula(Taula_freq& t)
{
	for (int i = 0; i < _frase.size(); ++i) {
		if (es_lletra(_frase[i].back()) t.incrementa_freq(_frase[i]);
	}
}

bool Frase::compleix_expressio(expressio)
{
	if (expressio[0] == '{') {
		normalitzar(expressio);
		vector<string> paraules = par_buscar(expressio);
		return buscar_paraules(paraules);
	}
	normalitzar(expressio);
	int i = 0;
	int j = 0;
	bool parada = false;
	for (int j = 0; j < expressio.length(); ++j) {
		if (expressio[j] == '(') ++i;
		else if (expressio[j] == ')') --i;
		else if (i == 0 and expressio[j] == '&') {
			//arreglar esq i dreta;
			return compleix_expressio(esq) and compleix_expressio(dreta);
		}
		else if (i == 0 and expressio[j] == '|') {
			//arreglar esq i dreta;
			return compleix_expressio(esq) or compleix_expressio(dreta);
		}
	}
}

void Frase::escriure()
{
	for (int i = 0; i < _frase.size(); ++i) {
		if (not es_lletra(_frase[i].back()) or i == 0) cout << _frase[i];
		else cout << " " << _frase[i];
	}
	cout << endl;
}
