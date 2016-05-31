/** @file Cjt_cites.cc
    @brief Implementació de les funcions de Cjt_cites.hh
*/

#include "Cjt_cites.hh"

void Cjt_cites::fer_ini(string& ini, string autor)
{
	istringstream iss(autor);
	string m;
	while (iss >> m) ini.push_back(m.front());	//Per a cada paraula que té autor, s'afegeix el seu primer caràcter a ini.
}

void Cjt_cites::fer_ref(const string& ini, int i, string& ref)
{
    string num;
    ostringstream convert;
    convert << i;
    num = convert.str();	//Es converteix l'enter i en un string m.
    ref = ini+num;			//Es concatenen les inicial amb num.
}

Cjt_cites::Cjt_cites(){}

Cjt_cites::~Cjt_cites(){}

void Cjt_cites::afegir_cita(const Biblioteca& b, int x, int y)
{
	if (x > 0 and x <= y and b.triat()) {		//Si la x>0, y>=x i hi ha un text triat, s'afegiex la cita, si es pot.
		Cita c;
		b.modificar_cita(c, x, y);	//Es crea la cita amb les frases de la x-éssima a la y-éssima del text triat a la biblioteca,
									//si y és més gran que el nombre de frases del text triat la cita es creara com si estigués eliminada.
		
		if (c.es_cita()) {			//Si y <= el nombre de frases del text triat, s'afegeix la cita, si es pot.
			string ref, ini;
			bool error = false;			//error indica si existeix una altre cita igual.
			fer_ini(ini, c.autor());
			ref = ini + "1";
			int i = 1;
			map<string, Cita>::iterator it = _cites.find(ref);
			while (it != _cites.end() and it->first == ref and not error) {		//Recorrem totes les cites amb les que comparteix inicials per comprobar que
																				// no n'hi ha cap igual i saber quina referència hauriem d'adjudicar a la cita.
																				
				if (it->second.es_cita()) error = it->second.autor() == c.autor() and it->second.titol() == c.titol() and it->second.n_primera() == x and it->second.n_ultima() == y;
				if (error) cout << "error" << endl;		//Si existeix una cita igual, s'escriu error.
				else {
					++it;
					++i;
					fer_ref (ini, i, ref);		//S'actualitza la ref, s'incrementa una unitat el seu número.
				}
			}
			if (not error) _cites.insert(make_pair(ref, c));		//Si no existeix una cita igual, s'insereix la nova cita.
		}
		else cout << "error" << endl;		//Si y <= el nombre de frases del text triat, s'esriu error.
	}
	else cout << "error" << endl;		//Si no hi ha un text triat o x > y, s'escriu error.
}

void Cjt_cites::eliminar_cita(string& ref)
{
	normalitzar(ref);		//S'esborren les cometes que van amb la referència.
	map<string, Cita>::iterator it = _cites.find(ref);
	if (it != _cites.end() and it->second.es_cita()) it->second.eliminar();		//Si existeix una cita amb la referència, s'elimina.
	else cout << "error" << endl;  												//Si no existeix cap cita amb la referencia, s'escriu error.
}

bool Cjt_cites::te_cita(string& ref) const
{
	normalitzar(ref);		//S'esborrren les cometes que van amb la referència.
	map<string, Cita>::const_iterator it = _cites.find(ref);
	return it != _cites.end() and it->second.es_cita();
}

void Cjt_cites::info_cita(string& ref) const
{
	normalitzar(ref);
	map<string, Cita>::const_iterator it = _cites.find(ref);
	if (it != _cites.end()) {
		cout << it->second.autor() << " " << '"' << it->second.titol() << '"' << endl;
		cout << it->second.n_primera() << "-" << it->second.n_ultima() << endl;
		it->second.escriure_contingut();
	}
	else cout << "error" << endl; //No existeix cap cita amb la referencia ref.
}

void Cjt_cites::cites_autor(string& autor) const
{
	autor.erase(autor.end()-1);		//S'esborra l'interrogant i l'espai
	autor.erase(autor.end()-1);		// que segueixen a l'expressió.
	normalitzar(autor);				//S'esborren les cometes que van amb l'autor.
	string ref, ini;
	fer_ini(ini, autor);
	ref = ini + "1";
	int i = 1;
	map<string, Cita>::const_iterator it = _cites.find(ref);
	while (it != _cites.end() and ref == it->first) {					//Recorrem totes les cites que tenen les mateixes inicials que l'autor
		if (it->second.es_cita() and it->second.autor() == autor) {			//Si la cita no ha estat eliminada i és de l'autor que estem buscant, la escrivim.
			cout << ref << endl;
			it->second.escriure_contingut();
			cout << '"' << it->second.titol() << '"' << endl;
		}
		++i;
		fer_ref(ini, i, ref);		//S'incrementa la referència.
		++it;
	}
}

bool Cjt_cites::cites_text(const Biblioteca& b) const
{
	bool te_cites = false;
	if (b.triat()) {
		string autor, titol, ref, ini;
		b.info_triat(autor, titol);			//Consultem l'autor i el títol del text triat
		fer_ini(ini, autor);
		ref = ini + "1";
		int i = 1;
		map<string, Cita>::const_iterator it = _cites.find(ref);
		while (it != _cites.end() and ref == it->first) {		//Recorrem totes les cites que tenen les mateixes inicials que l'autor del text
			if (it->second.es_cita() and it->second.autor() == autor and it->second.titol() == titol) {		//Si la cita no ha estat eliminada i correspon al text triat, la escrivim.
				cout << ref << endl;
				it->second.escriure_contingut();
				te_cites = true;
			}
			++i;
			fer_ref(ini, i, ref);		//S'incrementa la referència.
			++it;
		}
	}
	return te_cites;
}

void Cjt_cites::totes_cites() const
{
	map<string, Cita>::const_iterator it = _cites.begin();
	while (it != _cites.end()) {		//Recorrem totes les cites.
		if (it->second.es_cita()) {			//Si la cita no ha estat eliminada, la escrivim.
			cout << it->first << endl;
			it->second.escriure_contingut();
			cout << it->second.autor() << " " << '"' << it->second.titol() << '"' << endl;
		}
		++it;
	}
}
