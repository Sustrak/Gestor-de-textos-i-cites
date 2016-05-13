/** @file Taula_freq.hh
    @brief Especificació de la classe Taula_freq
*/

#ifndef Taula_freq_hh
#define Taula_freq_hh

#ifndef NO_DIAGRAM
#include <string>
#include <set>
#include <iostream>
#include <map>
#endif

using namespace std;

class Taula_freq {

    /** @class Taula_freq
        @brief Representa una taula amb la freqüencia d'aparició de les paraules d'un text.
    */

private:
	map<int, set <string>> _taula;

public:

  //Constructora

    /** @brief Creadora per defecte.
        S'executa automaticament al declarar una taula de freqüències.
        \pre <em>Cert</em>.
        \post El resultat és una taula de freqüències buida.
    */
    Taula_freq();

  //Destructora

    /** @brief Destructora per defecte.
    */
    ~Taula_freq();

  //Modificadora
    
    /** @brief Substitueix una paraula per una altre en el paràmetre implícit.
        \pre <em>Cert</em>.
        \post Canvia totes les aparicions de <b>par1</b> per <b>par2</b> en el p.i.
    */
    void substitueix (string par1, string par2);
    
        /** @brief Incrementa una unitat la freqüència de <em>s</em>.
        \pre <em>Cert</em>.
        \post Incrementa una unitat la freqüència de <em>s</em>.
    */
    void incrementa_freq (string s);

  //Consultora

    /** @brief Retorna la freqüència de <em>s</em>.
        \pre <em>Cert</em>.
        \post Retorna la freqüència de <em>s</em>.
    */
    int freq(string& s);

  //Escriptura

    /** @brief S'escriu el paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu el contingut del p.i.
    */
    void escriure();

};

#endif /* Frase_hh */
