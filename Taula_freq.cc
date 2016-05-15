/** @file Taula_freq.cc
    @brief Implementació de les funcions de Taula_freq.hh
*/

#include "Taula_freq.hh"

Taula_freq::Taula_freq(){}

Taula_freq::~Taula_freq(){}

void Taula_freq::substitueix(string par1, string par2)
{
	bool trobat = false;		//trobat indica si hem trobat par1.
	map<int, set<string>>::iterator it1 = _taula.begin();
	set<string>::iterator it2;
	int f1 = 0;
	while (not trobat and it1 != _taula.end()) {
		it2 = it1->second.find(par1);
		trobat = it2 != it1->second.end();
		if (trobat) f1 = it1->first;
		++it1;
	}
	if (trobat) {
		--it1;
		it1->second.erase(it2);
		
		trobat	= false;		//Ara trobat indica si hem trobat par2.
		map<int, set<string>>::iterator it3 = _taula.begin();
		int f2 = 0;
		
		while (not trobat and it3 != _taula.end()) {
			it2 = it3->second.find(par2);
			trobat = it2 != it3->second.end();
			if (trobat) f2 = it3->first;
			++it3;
		}
		if (trobat) {
			if (it1->second.empty()) _taula.erase(it1);		//Eliminen el conjunt on es trobava par1 si és buit.
			--it3;
			it3->second.erase(it2);
			if (it3->second.empty()) _taula.erase(it3);		//Eliminen el conjunt on es trobava par2 si és buit.
			f2 += f1;										//par 2 passa a tenir la suma de ambdues freq.
			it1 = _taula.find(f2);
			if (it1 == _taula.end()) {						//No existeix a maps el conjunt de paraules de freq. f2.
				set<string> t;
				t.insert(par2);
				_taula.insert(make_pair(f2, t));
			}
			else it1->second.insert(par2);
		}
		else it1->second.insert(par2);						//Com par2 no hi era originalment, passa a tenir la freq. original de par1, és a dir va al seu conjunt original.
	}
}

void Taula_freq::incrementa_freq (string s)
{
	bool trobat = false;
	map<int, set<string>>::iterator it1 = _taula.begin();
	set<string>::iterator it2;
	int f = 1;
	while (not trobat and it1 != _taula.end()) {
		it2 = it1->second.find(s);
		trobat = it2 != it1->second.end();
		if (trobat) f = it1->first + 1;
		++it1;
	}
	if (it1 == _taula.end() or it1->first != f) {	//No existeix a maps el conjunt de paraules de freq. f.
		set<string> t;
		t.insert(s);
		_taula.insert(make_pair(f, t));
	}
	else it1->second.insert(s);						//Ja existeix a maps el conjunt de paraules de freq. f.
	
	if (trobat) {									//Originalment s ja estava a la taula de freq, l'eliminem del conjunt amb la seva freq. original.
		--it1;
		it1->second.erase(it2);
		if (it1->second.empty()) _taula.erase(it1);	//Si el conjunt de paraules de freq. f-1 és buit, l'eliminem;
	}		
}

void Taula_freq::clear()
{
	_taula.clear();
}

int Taula_freq::freq(string& s)
{
	bool trobat = false;
	map<int, set<string>>::iterator it1 = _taula.begin();
	set<string>::iterator it2;
	int f = 0;
	while (not trobat and it1 != _taula.end()) {
		it2 = it1->second.find(s);
		trobat = it2 != it1->second.end();
		if (trobat) f = it1->first;
		++it1;
	}
	return f;
}

void Taula_freq::escriure()
{
	map<int, set<string>>::iterator it1 = _taula.end();
	set<string>::iterator it2;
	while (it1 != _taula.begin()) {
		for (it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) cout << *it2 << " " << it1->first << endl;
		--it1;
	}
}
