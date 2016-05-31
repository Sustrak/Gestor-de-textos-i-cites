/** @file Biblioteca.cc
    @brief Implementació de les funcions de Biblioteca.hh
*/

#ifndef NO_DIAGRAM
#include <sstream>
#endif

#include "Biblioteca.hh"

using namespace std;

Biblioteca::Biblioteca()
{
	//Crea una biblioteca buida on  no hi ha cap text triat.
    _triat = false;
}

Biblioteca::~Biblioteca(){}

void Biblioteca::afegir_text(string& titol)
{
    normalitzar(titol);			//S'esborren les cometes que van amb el títol.
    string autor, s;
    getline(cin,autor);			//Llegim la línia "autor "<autor>"".
    istringstream iss(autor);
    iss >> s;
    ws(iss);
	getline(iss, autor);		//Ens quedem només amb ""<autor>"".
    normalitzar(autor);			//S'esborren les cometes que van amb l'autor.
    _autors[autor].afegir_text(titol);		//Si es pot, s'afegeix el text.
}

void Biblioteca::triar_text(string& paraules)
{
    normalitzar(paraules);		//S'esborren els claudàtors que van al principi i final del conjunt de paraules.

    vector<string> paraules_buscar;
    par_buscar(paraules, paraules_buscar);		//Es posa el conjunt de paraules com un vector amb una paraula a cada element.
    
    map<string, Cjt_textos>::iterator it_autor = _autors.begin();
    bool trobat1 = false, trobat2 = false;				//trobat1 indica si hem trobat un text i trobat2 si n'hem trobat un segon que continguin el conjunt de paraules.
    
    while (not trobat1 and it_autor != _autors.end()){		//Busquem, a cada autor, si existeix un text que contingui les paraules fins a trobar-ne un.
        string autor = (*it_autor).first;
        (*it_autor).second.triar_text(trobat1, paraules_buscar, autor);
        ++it_autor;
    }
    if (trobat1) {				//Si n'hem trobat un, busquem s'hi n'hi ha un altre.
        --it_autor;
        map<string, Cjt_textos>::iterator it = it_autor;
        string autor = (*it).first;
        (*it).second.buscar_text(trobat2, paraules_buscar, autor); //Comprova si hi ha un altre text amb paraules en el mateix autor.
        ++it;
        while (not trobat2 and it != _autors.end()) {	//Busquem, a la resta d'autors, si existeix un text que contingui les paraules fins a trobar-ne un.
            string autor = (*it).first;
            (*it).second.triar_text(trobat2, paraules_buscar, autor);
            ++it;
        }
    }
    if (trobat1 and not trobat2) {			//Si només hem trobat un text que contingui el conjunt de paraules, el triem i en fem la taula de freqüencies.
        _triat = true;
        _autor_triat = it_autor;
        _tfreq.clear();
        (*_autor_triat).second.fer_taula(_tfreq);
    }
    else {							//Si no hi ha cap text o n'hi més d'un que contingui el conjunt de paraules, escriurem error i deixarà de haver un text triat.
        _triat = false;
        cout << "error" << endl;
    }
}

void Biblioteca::eliminar_text()
{
    if (not _triat) cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
    else {											//Si hi ha un text triat, l'eliminem i deixa de haver un text triat.
		(*_autor_triat).second.eliminar_text();
		if ((*_autor_triat).second.es_buit()) _autors.erase(_autor_triat);	//Si l'autor del text eliminat queda sense textos, l'eliminem.
		_triat = false;
	}
}
    
void Biblioteca::substitueix (string& par1, string& par2)
{
    if (_triat) {				//Si hi ha un text triat, hi substituirem les  aparicions de par1 per par2 i actualitzarem la taula de freqüències.
        normalitzar(par1);			//S'esboren les cometes que van amb la par1.
        normalitzar(par2);			//S'esboren les cometes que van amb la par2.
        if (par1 != par2) {			//Si par1 i par2 són iguals no cal fer res.
			(*_autor_triat).second.substitueix(par1, par2);		//Es substitues la paraula.
			_tfreq.substitueix(par1, par2);						//S'actualitza la taula de freqüències.
		}
	}
	else cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
}
    
bool Biblioteca::triat() const
{
    return _triat;
}
    
void Biblioteca::modificar_cita(Cita& c, int x, int y) const
{
	if (_triat) {								//Si hi ha un text triat, c passa a ser una cita amb les frases de la x-éssima a la y-éssima del text triat.
		c.afegir_autor((*_autor_triat).first);
		(*_autor_triat).second.modificar_cita(c, x, y);
	}
}
    
void Biblioteca::info_triat(string& autor, string& titol)  const
{
    if (not _triat) cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
    else {											//Si hi ha un text triat, escriurem la seva informació.
        autor = (*_autor_triat).first;
        (*_autor_triat).second.titol_triat(titol);
    }
}

void Biblioteca::textos_autor(string autor) const
{
    normalitzar(autor);						//S'esborren les cometes que van amb l'autor.
    map<string, Cjt_textos>::const_iterator it = _autors.find(autor);
    if (it != _autors.end()) (*it).second.escriure_titols(autor, false);	//Si existeix l'autor, s'escriuen els títols dels seus textos.
}
    
void Biblioteca::tots_textos() const
{
    map<string, Cjt_textos>::const_iterator it = _autors.begin();
    
    while (it != _autors.end()){			//Recorrem tots els autors escribint-ne els títols dels seus textos.
        string autor = (*it).first;
        (*it).second.escriure_titols(autor, true);
        ++it;
    }
}
    
void Biblioteca::tots_autors() const
{
    map<string, Cjt_textos>::const_iterator it = _autors.begin();
    while (it != _autors.end()) {		//Recorrem tots els autors escribint-ne el nom i la seva informació.
        cout << (*it).first << " ";
        (*it).second.escriure_info();
        ++it;
    }
}
    
void Biblioteca::info() const
{
    if (not _triat) cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
    else {
        cout << (*_autor_triat).first << " ";
        (*_autor_triat).second.escriure_info_triat();
    }
}

void Biblioteca::autor() const
{
    if (not _triat) cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
    else {
        cout << (*_autor_triat).first << endl;
    }
}

void Biblioteca::autor_titol() const
{
	if (_triat) {		//Si hi ha un text triat, escriurem l'autor i el títol del text triat en la mateixa línia.
        cout << (*_autor_triat).first << " ";
        (*_autor_triat).second.escriure_titol_triat();
        cout << endl;
    }
}

void Biblioteca::contingut() const
{
    if (not _triat) cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
    else {
        bool tot = true;
        int x, y;
        (*_autor_triat).second.escriure_contingut(tot, x, y);
    }
}

void Biblioteca::frasesxy (int x, int y) const
{
    if (not _triat or x > y) cout << "error" << endl; 		//Si no hi ha un text triat o x > y, escriurem error.
    else {
        bool tot = false;
        (*_autor_triat).second.escriure_contingut(tot, x, y);
    }
}
    
void Biblioteca::nombre_frases() const
{
    if (not _triat) cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
    else {
        (*_autor_triat).second.escriure_nombre_frases();
    }
}

void Biblioteca::nombre_paraules() const
{
    if (not _triat) cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
    else {
        (*_autor_triat).second.escriure_nombre_paraules();
    }
}

void Biblioteca::taula_freq() const
{
    if (not _triat) cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
	else _tfreq.escriure();
}

void Biblioteca::frases_expressio(string& expressio) const
{
    if (not _triat) cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
    else {
        expressio.erase(expressio.end()-1);		//S'esborra l'interrogant i l'espai
        expressio.erase(expressio.end()-1);		// que segueixen a l'expressió.
		(*_autor_triat).second.frases_expressio(expressio);
	}
}
    
void Biblioteca::frases_paraules(string& paraules) const
{
    if (not _triat) cout << "error" << endl;		//Si no hi ha un text triat, escriurem error.
    else {
		paraules.erase(paraules.end()-1);	//S'esborra l'interrogant i l'espai
        paraules.erase(paraules.end()-1);	// que segueixen a la seqüència de paraules.
        normalitzar(paraules);				//S'esborren les cometes que van amb la seqüència de paraules.
        vector<string> vec_par;
        par_buscar(paraules, vec_par);		//Es posa la seqüència de paraules cada paraula com un element d'un vector.
        
        (*_autor_triat).second.frases_paraules(vec_par);
    }
    
}
