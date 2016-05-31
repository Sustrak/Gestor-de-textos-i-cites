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

#ifndef NO_DIAGRAM
	/** @brief Estructura que ens permet ordenar els elements d'un set de strings.
	 
	 Ordena els elements primer per llargada i després alfabèticament. */
struct ordenar
{
    bool operator() (const string& s, const string& t){
        if (s.length() < t.length()) return true;
        else if (s.length() == t.length() and s < t) return true;
        else return false;
    }
};
#endif

class Taula_freq {

    /** @class Taula_freq
        @brief Representa una taula amb la freqüencia d'aparició de les paraules d'un text.
    */

private:
	/** @brief Map que representa la taula de freqüències d'un text.

      La clau són les freqüències de les paraules dels text i els valor és el conjunt de paraules que té la freqüencia que indica la clau.
      El map s'ordena creixentment per freqüència. Cada conjunt ordena els elements primer per llargada i després alfabèticament. */
	map<int, set <string, ordenar>> _taula;

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
    void substitueix (const string& par1, const string& par2);
    
        /** @brief Incrementa una unitat la freqüència de <em>s</em>.
        \pre <em>Cert</em>.
        \post Incrementa una unitat la freqüència de <em>s</em>.
    */
    void incrementa_freq (const string& s);

    /** @brief El paràmetre implícit queda buit.
        \pre <em>Cert</em>.
        \post El paràmetre implícit queda buit.
    */
    void clear();

  //Escriptura

    /** @brief S'escriu el paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu el contingut del p.i.
    */
    void escriure() const;

};

#endif /* Frase_hh */
