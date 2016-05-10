/** @file Cita.cc
    @brief Implementació de les funcions de Cita.hh
*/

#include "Cita.hh"

Cita::Cita ()
{
	_eliminada = false;
}

Cita::~Cita (){}

void Cita::afegir_contingut(const vector<Frase>& contingut, int x, int y)
{
	_n_primera = x;
	while (x <= y) {
		_frases.push_back(contingut[x]);
		++x;
	}
}

void Cita::afegir_autor(const string& autor)
{
	_autor = autor;
}

void Cita::afegir_titol(const string& titol)
{
	_titol = titol;
}

void Cita::eliminar() {
	_eliminada = true;
}

string Cita::autor()
{
	return _autor;
}

string Cita::titol()
{
	return _titol;
}

int Cita::n_primera()
{
	return _n_primera;
}
int Cita::n_ultima()
{
	return _n_primera + _frases.size();
}

void Cita::escriure_contingut()
{
	for (int i = 0; i < _frases.size(); ++i) {
		cout << _n_primera+i << " ";
		_frases[i].escriure();
	}
}
