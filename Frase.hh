/** @file Frase.hh
    @brief Especificació de la classe Frase
*/

#ifndef Frase_hh
#define Frase_hh

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Func_auxiliars.hh"
#endif

#include "Taula_freq.hh"

using namespace std;

class Frase {

    /** @class Frase
        @brief Representa una frase.
    */

private:
    vector<string> _frase;
    int _n_paraules;

public:

  //Constructora

    /** @brief Creadora per defecte.
        S'executa automaticament al declarar una frase.
        \pre <em>Cert</em>.
        \post El resultat és una frase buida.
    */
    Frase();

  //Destructora

    /** @brief Destructora per defecte.
    */
    ~Frase();

  //Modificadora

    /** @brief El paràmetre implícit conté la primera frase de <em>linia</em>.
        \pre <em>Cert</em>.
        \post El p.i. conté la primera frase de <em>linia</em>.
    */
    void llegir(string& linia);
    
    /** @brief Substitueix una paraula per una altre en el paràmetre implícit.
        \pre <em>Cert</em>.
        \post Canvia totes les aparicions de <b>par1</b> per <b>par2</b> en el p.i.
    */
    void substitueix (string par1, string par2);

  //Consultora

    /** @brief Retorna el nombre de paraules del paràmetre implícit.
        \pre <em>Cert</em>.
        \post Retorna el nombre de paraules del p.i.
    */
    int n_paraules();
    
    /** @brief Mira si al p.i hi ha les paraules del vector
        \pre <em>Cert</em>
        \post Retorna true si les paraules del vector estan en el p.i, altrament retorna false
     */
    bool buscar_paraules(const vector<string>& paraules);

    /** @brief Afegeix per referència a la taula de freqüències <em>t</em> les paraules del paràmetre implícit.
     \pre <em>Cert</em>.
     \post Afegeix per referència a la taula de freqüències <em>t</em> les paraules del paràmetre implícit.
     */
    void actualitzar_taula(Taula_freq& t);   
    
  //Escriptura

    /** @brief S'escriu el paràmetre implícit.
        \pre <em>Cert</em>.
        \post S'escriu el contingut del p.i.
    */
    void escriure();

};

#endif /* Frase_hh */
