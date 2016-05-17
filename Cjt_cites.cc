/** @file Cjt_cites.cc
    @brief Implementació de les funcions de Cjt_cites.hh
*/

#include "Cjt_cites.hh"

void fer_ini(string& ini, string autor)
{
	istringstream iss(autor);
	string m;
	while (iss >> m) ini.push_back(m.front());
}

void fer_ref(string& ini, int& i, string& ref)
{
    string num;
    ostringstream convert;
    convert << i;
    num = convert.str();
    ref = ini+num;
}

Cjt_cites::Cjt_cites(){}
    
Cjt_cites::~Cjt_cites(){}
    
void Cjt_cites::afegir_cita(Biblioteca& b, int x, int y)
{
	if (x <= y and b.triat()) {
		Cita c;
		b.modificar_cita(c, x, y);
		
		string ref, ini;
		bool error = false;
		fer_ini(ini, c.autor());
		ref = ini + "1";
		int i = 1;
		map<string, Cita>::iterator it = _cites.find(ref);
		while (it != _cites.end() and it->first == ref and not error) {
			if (it->second.es_cita()) error = it->second.autor() == c.autor() and it->second.titol() == c.titol() and it->second.n_primera() == x and it->second.n_ultima() == y;
			if (error) cout << "error" << endl; //Existeix una cita igual
			else {
				++it;
				++i;
				fer_ref (ini, i, ref);				
			}
		}
		if (not error) _cites.insert(make_pair(ref, c));
	}
	else cout << "error" << endl; //No hi ha un text triat o x > y.
}
	
void Cjt_cites::eliminar_cita(string ref)
{
	map<string, Cita>::iterator it = _cites.find(ref);
	if (it != _cites.end() and it->second.es_cita()) it->second.eliminar();
	else cout << "error" << endl;  //No existeix cap cita amb la referencia ref.
}
    
bool Cjt_cites::te_cita(string ref)
{
	map<string, Cita>::iterator it = _cites.find(ref);
	return it != _cites.end() and it->second.es_cita();
}
    
void Cjt_cites::info_cita(string ref)
{
	map<string, Cita>::iterator it = _cites.find(ref);
	if (it != _cites.end()) {
		cout << it->second.autor() << " " << it->second.titol() << endl;
		cout << it->second.n_primera() << "-" << it->second.n_ultima() << endl;
		it->second.escriure_contingut();
	}
	else cout << "error" << endl; //No existeix cap cita amb la referencia ref.
}	

void Cjt_cites::cites_autor(string autor)
{
	string ref, ini;
	fer_ini(ini, autor);
	ref = ini + "1";
	int i = 1;
	map<string, Cita>::iterator it = _cites.find(ref);
	while (it != _cites.end() and ref == it->first) {
		if (it->second.es_cita() and it->second.autor() == autor) {
			cout << ref << endl;
			it->second.escriure_contingut();
			cout << it->second.autor() << " " << it->second.titol() << endl;
		}
		++i;
		fer_ref(ini, i, ref);
		++it;
	}
}
    
void Cjt_cites::cites_text(Biblioteca& b)
{
	if (b.triat()) {
		string autor, titol, ref, ini;
		b.info_triat(autor, titol);
		fer_ini(ini, autor);
		ref = ini + "1";
		int i = 1;
		map<string, Cita>::iterator it = _cites.find(ref);
		while (it != _cites.end() and ref == it->first) {
			if (it->second.es_cita() and it->second.autor() == autor and it->second.titol() == titol) {
				cout << ref << endl;
				it->second.escriure_contingut();
			}
			++i;
			fer_ref(ini, i, ref);
			++it;
		}
	}
	else cout << "error" << endl; //No hi ha un text triat.
}

void Cjt_cites::totes_cites()
{
	map<string, Cita>::iterator it = _cites.begin();
	while (it != _cites.end()) {
		if (it->second.es_cita()) {
			cout << it->first << endl;
			it->second.escriure_contingut();
			cout << endl << it->second.autor() << " " << it->second.titol() << endl;
		}
		++it;
	}
}
    
