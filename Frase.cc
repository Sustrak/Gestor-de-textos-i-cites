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
	do {					//S'afeigeix a la frase paraula a paraula el contingut de la linia fin al primer '.', '!' o '?'
		iss >> m;
		if (not es_lletra(m.back())) {		//Si m conté un signe de puntuació.
			if (m.size() == 1) {				//Si només hi ha un segne de puntuació, no augmentarem el nombre de paraules.
				_frase.push_back(m);
				--_n_paraules;
			}
			else {								//Si la paraula te un signe de puntuació enganxat, els separem i els afegim com a dos elements diferens
				string m1 = m;
				m1.pop_back();
				string m2;
				m2.push_back(m.back());
				_frase.push_back(m1);
				_frase.push_back(m2);
			}
		}
		else _frase.push_back(m);			//Si m és una paraula sense signes de puntuació, l'afegim.
		++_n_paraules;
	} while (m.back() != '.' and m.back() != '?' and m.back() != '!');
	ws(iss);
	getline(iss, linia);			//Deixem a linia el contingut sense tractar.
    if (aux == linia) linia = "";		//Si linia només li queda una paraula , la buidem.
}

void Frase::substitueix (const string& par1, const string& par2)
{
	for (int i = 0; i < _frase.size(); ++i) {
		if (_frase[i] == par1) _frase[i] = par2;
	}
}

int Frase::n_paraules() const
{
	return _n_paraules;
}

bool Frase::buscar_paraules(vector<string>& paraules) const
{
    for (int i = 0; i < paraules.size(); ++i) {			//Per a cada paraula a buscar, comprovem si està a la frase.
		bool aux = false;;
        for (int j = 0; not aux and j < _frase.size(); ++j) {
			aux = paraules[i] == _frase[j];
            if (aux){
                paraules[i] = paraules[paraules.size()-1];	//Si troba la paraula està a la frase, s'elimina del vector de paraules.
                paraules.pop_back();
                --i;
            }
        }
    }
    return paraules.size() == 0;		//Si ja hem trobat totes les paraules, el vector estarà buit.
}

bool Frase::buscar_consecutives(const vector<string>& paraules) const
{
	bool trobat = false;
    int k = _frase.size() - paraules.size();
    for (int i = 0; i <= k and not trobat; ++i) {
		if (_frase[i] == paraules[0]) {					//Si alguna de les paraules de la frase concideix amb la primera paraula a buscar, busquem en les següents.
			trobat = true;		//Trobat indica que les paraules a buscar que hem tractat és troben de forma consecutiva.
			int p = 0;		//Compte els signes de puntuacio.
            int j = 1;
			while (j < paraules.size() and trobat) {
				if (i+j+p < _frase.size()) {
                    if (not es_lletra(_frase[i+j+p][0])) ++p;		//Hi ha un signe de puntuació
                    else{
                        trobat = _frase[i+j+p] == paraules [j];
                        ++j;
                    }
				}
                else trobat = false;
			}
            
		}
	}
	return trobat;		//Si al final trobat és cert, vol dir que totes les paraules estàn de forma consecutiva.
}

void Frase::actualitzar_taula(Taula_freq& t) const
{
	for (int i = 0; i < _frase.size(); ++i) {
        if (es_lletra(_frase[i].front())){
			t.incrementa_freq(_frase[i]); 	//Per a cada paraula que no és un signe de puntuació, s'incrementa la freqüència.
        }
	}
}

bool Frase::compleix_expressio(string expressio) const
{
	if (expressio[0] == '{') {		// Si l'expressió és només un conjunt de paraules (sense connectors), comprovem si la frase conté totes les paraules del conjunt.
		normalitzar(expressio);
		vector<string> paraules;
		par_buscar(expressio, paraules);
		return buscar_paraules(paraules);
	}
	normalitzar(expressio);
	int i = 0;			// Indica si hem tancat els mateixos parèntesis que hem obert.
    string esq;
	while (0 < expressio.length()) {		// Si l'expressió té connectors, en busquem el principal i tractem per separat el que queda a la seva esquerra i a la seva dreta.
		if (expressio[0] == '(') ++i;				//Obre parèntesis.
		else if (expressio[0] == ')') --i;			//Tanca parèntesis.	
		else if (i == 0 and expressio[0] == '&') {		//El connector principal és un &
			esq.erase(esq.end()-1);
            expressio.erase(expressio.begin());
            expressio.erase(expressio.begin());
            return compleix_expressio(esq) and compleix_expressio(expressio);
		}
		else if (i == 0 and expressio[0] == '|') {		//El connector principal és un &
			esq.erase(esq.end()-1);
            expressio.erase(expressio.begin());
            expressio.erase(expressio.begin());
			return compleix_expressio(esq) or compleix_expressio(expressio);
		}
		esq.push_back(expressio[0]);				//Posem el caracter tractat a la subexpressió esquerre
        expressio.erase(expressio.begin());			// i l'eliminem de la subexpressió dreta.
	}
    return true;
}

void Frase::escriure() const
{
	for (int i = 0; i < _frase.size(); ++i) {
		if (not es_lletra(_frase[i].back()) or i == 0) cout << _frase[i];
		else cout << " " << _frase[i];
	}
	cout << endl;
}
