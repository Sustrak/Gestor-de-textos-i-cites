/** @file Cita.hh
    @brief Especificació de la classe Cita
*/

#ifndef Cita_hh
#define Cita_hh

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <map>
#endif

#include "Frase.hh"
using namespace std;

class Cita {

    /** @class Cita
        @brief Representa un text amb autor i conjunt de frases que són el contingut.
    */

private:
	/** @brief Indica si la cita ha estat eliminada.
	  
	 Es fa per mantenir les referències quan s'eliminen les cites.  */  
	bool _eliminada;
	/** @brief Indica l'autor del text corresponent a la cita.  */  
    string _autor;
	/** @brief Indica el títol del text corresponent a la cita.  */  
    string _titol;
	/** @brief Vector que té per elements les frases que composen la cita.
	 
	 Les frases estan ordenades per l'ordre en que estan en el text original. */
    vector<Frase> _frases;
	/** @brief Indica el número de la primera frase de la cita en el text original.  */  
    int _n_primera;

public:

  //Constructora

    /** @brief Creadora per defecte.
        S'executa automaticament al declarar una cita.
        \pre <em>Cert</em>.
        \post El resultat és una cita buida.
    */
    Cita ();

  //Destructora

    /** @brief Destructora per defecte.
    */
    ~Cita ();

  //Modificadores

    /** @brief El contingut del paràmetre implícit passa a ser les frases de la x-éssima a la y-éssima de <em>contingut</em>.
        \pre <em>Cert</em>.
        \post El contingut del p.i. passa a ser les frases de la x-éssima a la y-éssima de <em>contingut</em>.
    */
    void afegir_contingut(const vector<Frase>& contingut, int x, int y);

    /** @brief L'autor del paràmetre implícit passa a ser <em>autor</em>.
        \pre <em>Cert</em>.
        \post L'autor del p.i. passa a ser <em>autor</em>.
    */
    void afegir_autor(const string& autor);

    /** @brief El contingut del paràmetre implícit passa a ser <em>titol</em>.
        \pre <em>Cert</em>.
        \post El contingut del p.i. passa a ser <em>titol</em>.
    */
    void afegir_titol(const string& titol);

    /** @brief S'elimina el paràmetre implícit.
        \pre <em>Cert</em>.
        \post El p.i. passa a estar eliminat.
    */
    void eliminar();

  //Consultores

    /** @brief Retorna si el paràmetre implícit ha estat eliminat.
        \pre <em>Cert</em>.
        \post Retorna si el p.i. ha estat eliminat.
    */
    bool es_cita() const;

    /** @brief Retorna l'autor del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna l'autor del p.i.
    */
    string autor() const;

    /** @brief Retorna el títol del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el títol del p.i.
    */
    string titol() const;

    /** @brief Retorna el número de la frase inicial del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el número de la frase inicial del p.i.
    */
    int n_primera() const;

    /** @brief Retorna el número de la frase final del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el número de la frase final del p.i.
    */
    int n_ultima() const;

  //Escriptura

    /** @brief S'escriu el contingut del paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu el contingut del p.i. amb les frases numerades.
    */
    void escriure_contingut() const;

};

#endif /* Cita_hh */
