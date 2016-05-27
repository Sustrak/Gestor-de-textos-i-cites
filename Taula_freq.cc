/** @file Taula_freq.cc
    @brief Implementació de les funcions de Taula_freq.hh
*/

#include "Taula_freq.hh"

Taula_freq::Taula_freq(){}

Taula_freq::~Taula_freq(){}

void Taula_freq::substitueix(string par1, string par2)
{
	bool trobat = false;												//trobat indica si hem trobat par1.
	map<int, set<string, ordenar>>::iterator it1 = _taula.begin();
	set<string, ordenar>::iterator it2;
	int f1 = 0;									
	while (not trobat and it1 != _taula.end()) {						//Es busca en el conjunt de cada frequencia si hi és par1.
		it2 = it1->second.find(par1);
		trobat = it2 != it1->second.end();
		if (trobat) f1 = it1->first;									//Si par1 esta al text, ens guardem la seva frequencia.
		++it1;
	}

	if (trobat) {														//Si par1 es troba al text, s'ha de sumar la seva frequencia a la de par2 i esborrar-lo de la taula. Altrament, no cal fer res.
		
		--it1;															//Situem l'iterador a la frequencia on es troba par1.
		it1->second.erase(it2);											//Eliminem par1 de la taula de frequencies.
		
		trobat	= false;												//Ara trobat indica si hem trobat par2.
		map<int, set<string, ordenar>>::iterator it3 = _taula.begin();
		int f2 = 0;
		
		while (not trobat and it3 != _taula.end()) {					//Es busca en el conjunt de cada frequencia si hi és par2.
			it2 = it3->second.find(par2);
			trobat = it2 != it3->second.end();
			if (trobat) f2 = it3->first;								//Si par1 esta al text, ens guardem la seva frequencia.
			++it3;
		}

		if (trobat) {												//Si par2 es troba al text, s'ha d'esborrar del conjunt amb la seva frequencia inicial i inserir-lo en el conjunt de la suma de les frequencies de par1 i par2.
			
			--it3;														//Situem l'iterador a la frequencia on es troba par1.
			if (it1->second.empty()) _taula.erase(it1);					//Eliminen el conjunt on es trobava par1 si ha quedat buit.
			it3->second.erase(it2);										//Eliminem par2 del conjunt amb la seva frequencia inicial.
			if (it3->second.empty()) _taula.erase(it3);					//Eliminen el conjunt on es trobava par2 si ha quedat buit.
			
			f2 += f1;													//par2 passa a tenir la suma de ambdues frequencies.
			it1 = _taula.find(f2);
			if (it1 == _taula.end()) {									//No existeix a la taula el conjunt de paraules de frequencia f2, per tant el creem i l'inserim.
				set<string, ordenar> t;
				t.insert(par2);
				_taula.insert(make_pair(f2, t));
			}
			else it1->second.insert(par2);								//Ja xisteix a la taula el conjunt de paraules de frequencia f2.
		}
		else it1->second.insert(par2);								//Si par2 no hi era originalment, passa a tenir la frequencia inicial de par1, éper tant, l'inserim al conjunt on era par1.
	}
}

void Taula_freq::incrementa_freq (string s)
{
	bool trobat = false;												//Indica si s ja es troba a la taula.
	map<int, set<string, ordenar>>::iterator it1 = _taula.begin();
	set<string, ordenar>::iterator it2;
	int f = 1;
	while (not trobat and it1 != _taula.end()) {						//Es busca en el conjunt de cada frequencia si està s.
		it2 = it1->second.find(s);
		trobat = it2 != it1->second.end();
		if (trobat) f = it1->first + 1;									//Si s està a la taula ens guardem la seva frequencia i l'augmentem una unitat.
		++it1;
	}
    
    if (trobat) {													//Si s ja estava a la taula, l'eliminem del conjunt amb la seva frequencia inicial i l'inserim al de la frequencia una unitat superior..
		
        if (it1 != _taula.end() and it1->first == f) {					//En aquest cas, ja existeix un conjunt per a la frequencia incrementada.
           it1->second.insert(s);
            --it1;															//it1 apunta el conjunt de la frquencia inicial de s.
        }
        else {															//En aquest cas, no existeix un conjunt per a la frequencia incrementada.
            --it1;															//it1 apunta el conjunt de la frquencia inicial de s.
            set<string, ordenar> t;
            t.insert(s);
            _taula.insert(make_pair(f, t));
        }
        it1->second.erase(it2);											//Eliminem s del conjunt de la seva frequencia inicial.
        
        if (it1->second.empty()) _taula.erase(it1);						//Si el conjunt de la frequencia inicial de s queda buit, l'eliminem;
        
    }
    
    else {														//Si s no es troba a la taula, l'inserim en el conjut de frequencia 1.
        it1 = _taula.begin();
        if (it1 != _taula.end() and it1->first == 1) it1->second.insert(s);  	//Existeix el conjut de frequencia 1.
        else {																	//No existeix el conjut de frequencia 1.
            set<string, ordenar> t;
            t.insert(s);
            _taula.insert(make_pair(1, t));
        }
    }
	
			
}

void Taula_freq::clear()
{
	_taula.clear();
}

int Taula_freq::freq(string& s)
{
	bool trobat = false;
	map<int, set<string, ordenar>>::iterator it1 = _taula.begin();
	set<string, ordenar>::iterator it2;
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
	map<int, set<string, ordenar>>::iterator it1 = _taula.end();
	set<string, ordenar>::iterator it2;
	while (it1 != _taula.begin()) {
        --it1;
		for (it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) cout << *it2 << " " << it1->first << endl;
		
	}
}
