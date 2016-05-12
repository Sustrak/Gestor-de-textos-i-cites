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
	bool _eliminada;
    string _autor;
    string _titol;
    vector<Frase> _frases;
    int _n_primera; 		//Número de la primera frase de la cita en el text original.

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
    bool es_cita();

    /** @brief Retorna l'autor del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna l'autor del p.i.
    */
    string autor();

    /** @brief Retorna el títol del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el títol del p.i.
    */
    string titol();

    /** @brief Retorna el número de la frase inicial del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el número de la frase inicial del p.i.
    */
    int n_primera();

    /** @brief Retorna el número de la frase final del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el número de la frase final del p.i.
    */
    int n_ultima();

  //Escriptura

    /** @brief S'escriu el contingut del paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu el contingut del p.i. amb les frases numerades.
    */
    void escriure_contingut();

};

#endif /* Cita_hh */
