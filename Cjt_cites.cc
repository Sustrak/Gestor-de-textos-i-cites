/** @file Cjt_cites.cc
    @brief Implementació de les funcions de Cjt_cites.hh
*/

#include "Cjt_cites.hh"

Cjt_cites::Cjt_cites();
    
Cjt_cites::~Cjt_cites();
    
void Cjt_cites::afegir_cita(const Biblioteca& b, int x, int y)
{
	if (x <= y and b.triat()) {
		Cita c;
		b.modificar_cita(c, x, y);
		
		string ref;
		bool error = false;
		fer_referencia(ref, c.autor());
		map<string, Cita>::const_iterator it = _cites.find(ref);
		while (it != _cites.end() and not error) {
			if (it->second.es_cita()) error = it->second.autor() == c.autor() and it->second.titol() == c.titol() and it->second.n_primera() == x and it->second.autor() == y;
			if (error) cout << "error" << endl; //Existeix una cita igual
			else {
				incrementa_ref(ref);
				it = _cites.find(ref);  // ES POT FER MES EFICIENT?? ++it??
			}
		}
		if (not error) _cites.insert(make_pair(ref, c));
	}
	else cout << "error" << endl; //No hi ha un text triat o x > y.
}
	
 
void Cjt_cites::eliminar_cita(string ref)
{
	map<string, Cita>::const_iterator it = _cites.find(ref);
	if (it != _cites.end()) it->second.eliminar();
	else cout << "error" << endl;  //No existeix cap cita amb la referencia ref.
}
    
bool Cjt_cites::te_cita(string ref)
{
	map<string, Cita>::const_iterator it = _cites.find(ref);
	return it != _cites.end() and it->second.es_cita();
}
    
void Cjt_cites::info_cita(string ref)
{
	map<string, Cita>::const_iterator it = _cites.find(ref);
	if (it != _cites.end()) {
		cout << it->second.autor() << " " << it->second.titol() << endl;
		cout << it->second.n_primera() << "-" << it->second.n_ultima() << endl;
		it->second.escriure_contingut();
	}
	else cout << "error" << endl; //No existeix cap cita amb la referencia ref.
}	

void Cjt_cites::cites_autor(string autor)
{
	string ref;
	fer_referencia(ref, autor);
	map<string, Cita>::const_iterator it = _cites.find(ref);
	while (it != _cites.end() and ref == it->first) {
		if (it->second.es_cita() and it->second.autor() == autor) {
			cout << ref << endl;
			it->second.escriure_contingut();
			cout << it->second.autor() << " " << it->second.títol() << endl;
		}
		incrementa_ref(ref);
		++it;
	}
}
    
void Cjt_cites::cites_text(const Biblioteca& b)
{
	if (b.triat()) {
		string autor, titol, ref;
		b.info_triat(autor, titol);
		fer_referencia(ref, autor);
		map<string, Cita>::const_iterator it = _cites.find(ref);
		while (it != _cites.end() and ref == it->first) {
			if (it->second.es_cita() and it->second.autor() == autor and it->second.titol() == titol) {
				cout << ref << endl;
				it->second.escriure_contingut();
			}
			incrementa_ref(ref);
			++it;
		}
	}
	else cout << "error" << endl; //No hi ha un text triat.
    
void Cjt_cites::totes_cites()
{
	map<string, Cita>::const_iterator it = _cites.begin();
	while (it != _cites.end()) {
		if (it->second.es_cita()) {
			cout << it->first << endl;
			it->second.escriure_contingut();
			cout << endl << it->second.autor << " " << it.second.titol() << endl;
		}
		++it;
	}
}
    
