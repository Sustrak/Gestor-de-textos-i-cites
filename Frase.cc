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

void Frase::escriure()
{
	for (int i = 0; i < _frase.size(); ++i) {
		if (not es_lletra(_frase[i].back()) or i == 0) cout << _frase[i];
		else cout << " " << _frase[i];
	}
	cout << endl;
}
